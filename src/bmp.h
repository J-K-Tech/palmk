#pragma once
#include"imagetypes.h"




Image* loadBMP(const char* name);
Image* toBMP(ImageRAW* img);
void saveBMP(const char* name,Image* img);
int max(int a,int b);