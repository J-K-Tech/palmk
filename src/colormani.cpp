#include"colormani.h"

color HSVtoRGB(float h,float s,float v){
	float r,g,b;
	float c=v*s;
	float x=c*(1-fabs(fmod(h/60.f,2)-1));
	float m=v-c;

	if(h>=0&&h<60){r=c;g=x;b=0;}
	else if(h<120){r=x;g=c;b=0;}
	else if(h<180){r=0;g=c;b=x;}
	else if(h<240){r=0;g=x;b=c;}
	else if(h<300){r=x;g=0;b=c;}
	else{r=c;g=0;b=x;}

	color col;
	col.r=(uint8_t)((r+m)*255);
	col.g=(uint8_t)((g+m)*255);
	col.b=(uint8_t)((b+m)*255);

	return col;
}

uint8_t quant(uint8_t v,int bits){
	if(bits>=8)return v;
	int maxv=(1<<bits)-1;
	int q=(v*maxv)/255;
	return (q*255)/maxv;
}
