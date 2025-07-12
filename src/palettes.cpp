#include"bmp.h"
#include"colormani.h"
#include"raw.h"

ImageRAW* genpalette(char r, char g, char b) {
    int rbits = 1 << r;
    int gbits = 1 << g;
    int bbits = 1 << b;
    int cols = rbits * gbits * bbits;
    int w = (int)sqrt(cols * 1.5);
    if (w < 16) w = 16;
    int h = (cols + w - 1) / w;
    if (h < 16) h = 16;

    printf("r-g-b %d-%d-%d\ncolors: %d\nsize: %dx%d\n", r, g, b, cols, w, h);
    ImageRAW* img = new ImageRAW(w, h);

    int i = 0;
    for (int ri = 0; ri < rbits; ri++) {
        for (int gi = 0; gi < gbits; gi++) {
            for (int bi = 0; bi < bbits; bi++) {
                if (i >= w * h) break;
                color rgb;
                rgb.r = (ri * 255) / (rbits - 1);
                rgb.g = (gi * 255) / (gbits - 1);
                rgb.b = (bi * 255) / (bbits - 1);
                img->pixels[i++] = rgb;
            }
        }
    }
    while (i < w * h) {
        img->pixels[i++] = {0, 0, 0};
    }

    return img;
}


int main() {
	saveBMP("palette rgb_555.bmp", toBMP(genpalette(5,5,5)));
	saveBMP("palette rgb_565.bmp", toBMP(genpalette(5,6,5)));
	saveBMP("palette rgb_332.bmp", toBMP(genpalette(3,3,2)));
	saveBMP("palette rgb_444.bmp", toBMP(genpalette(4,4,4)));
	saveBMP("palette rgb_811.bmp", toBMP(genpalette(8,1,1)));
	saveBMP("palette rgb_121.bmp", toBMP(genpalette(1,2,1)));
    return 0;
}
