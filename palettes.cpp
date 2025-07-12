#include"bmp.h"

ImageRAW* genpalette(char r,char g,char b) {
    int cols=(1<<r)*(1<<g)*(1<<b);
    int w=(int)sqrt(cols*1.5);
    float deg=360.0f/w;
    int h=(cols+w-1)/w;
    if (w<16)w=16;
    if (h<16)h=16;
	printf("r-g-b %d-%d-%d\ncolors: %d\nsize: %dx%d\n",r,g,b,cols,w,h);
	
    ImageRAW* img=new ImageRAW(w,h);
    
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            float hue=(float)x*deg;
            float brightness=1.0f-(float)y/(h-1);
            float saturation,value;
            
            if (brightness>0.5f) {
                saturation=2.0f*(1.0f-brightness);
                value=1.0f;
            } else {
                saturation=1.0f;
                value=brightness*2.0f;
            }
            color rgb=HSVtoRGB(hue,saturation,value);
            rgb.r=quant(rgb.r,r);
            rgb.g=quant(rgb.g,g);
            rgb.b=quant(rgb.b,b);
            img->pixels[y*w+x]=rgb;
        }
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
