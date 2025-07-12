#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<cstdint>
#include<math.h>
#include"raw.h"

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
	uint32_t size;
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


Image* loadBMP(const char* name);
Image* toBMP(ImageRAW* img);
void saveBMP(const char* name,Image* img);
int max(int a,int b);