#pragma once
#include<cmath>
#include"raw.h"
color HSVtoRGB(float h,float s,float v);
uint8_t quant(uint8_t v,int bits);