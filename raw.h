#pragma once
#include "bmp.h"
struct color{
	uint8_t r,g,b;
};
struct ImageRAW{
	int w,h;
	std::vector<color> pixels;
	ImageRAW():w(0),h(0){}
	ImageRAW(int w,int h):w(w),h(h),pixels(w*h){}
	ImageRAW(int w,int h,std::vector<color> px):w(w),h(h),pixels(px){}
};
ImageRAW* toraw(Image* img);