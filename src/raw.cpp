#include"raw.h"
ImageRAW* toraw(Image* img){
	int w=img->info.w;
	int h=img->info.h;
	int row_size=(3*w+3)&~3;
	ImageRAW* raw=new ImageRAW(w,h);

	for(int y=0;y<h;y++){
		int BMPr=(h-1-y)*row_size;
		int rawr=y*w;
		for(int x=0;x<w;x++){
			int BMPi=BMPr+x*3;
			int rawi=rawr+x;
			raw->pixels[rawi].b=img->data[BMPi];
			raw->pixels[rawi].g=img->data[BMPi+1];
			raw->pixels[rawi].r=img->data[BMPi+2];
		}
	}
	return raw;
}