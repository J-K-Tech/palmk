#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<cstdint>
#include<math.h>

#pragma pack(push,1)
struct BMPfile{
	uint16_t type;
	uint32_t size;
	uint16_t reserved;
	uint16_t reserved2;
	uint32_t offset;
};
struct BMPinfo{
	uint32_t size;
	int32_t w;
	int32_t h;
	uint16_t planes;
	uint16_t bits;
	uint32_t compression;
	uint32_t imgsize;
	int32_t xppm;
	int32_t yppm;
	uint32_t used;
	uint32_t important;
};
struct Image{
	BMPfile file;
	BMPinfo info;
	std::vector<uint8_t> data;
};

#pragma pack(pop)
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