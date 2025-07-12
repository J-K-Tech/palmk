#include"bmp.h"
Image* loadBMP(const char* name){
	std::ifstream file(name,std::ios::binary);
	if(!file)return nullptr;
	BMPfile fileh;
	BMPinfo infoh;
	
	file.read(reinterpret_cast<char*>(&fileh),sizeof(fileh));
	file.read(reinterpret_cast<char*>(&infoh),sizeof(infoh));
	if(fileh.type!=0x4d42)return nullptr;

	int w=infoh.w;
	int h=infoh.h;
	int row_size=(3*w+3)&~3;
	std::vector<uint8_t> pixels(row_size*h);

	file.seekg(fileh.offset,std::ios::beg);
	file.read(reinterpret_cast<char*>(pixels.data()),pixels.size());
	return new Image{fileh,infoh,pixels};
}


Image* toBMP(ImageRAW* img){
	Image* BMP=new Image;

	int w=img->w;
	int h=img->h;
	int rows=(3*w+3)&~3;
	int datas=rows*h;

	BMP->data.resize(datas,0);

	BMP->file.type=0x4d42;
	BMP->file.size=sizeof(BMPfile)+sizeof(BMPinfo)+datas;
	BMP->file.reserved=0;
	BMP->file.reserved2=0;
	BMP->file.offset=sizeof(BMPfile)+sizeof(BMPinfo);

	BMP->info.size=sizeof(BMPinfo);
	BMP->info.w=w;
	BMP->info.h=h;
	BMP->info.planes=1;
	BMP->info.bits=24;
	BMP->info.compression=0;
	BMP->info.imgsize=datas;
	BMP->info.xppm=0;
	BMP->info.yppm=0;
	BMP->info.used=0;
	BMP->info.important=0;

	for(int y=0;y<h;y++){
		int BMPr=(h-1-y)*rows;
		int rawr=y*w;
		for(int x=0;x<w;x++){
			int BMPi=BMPr+x*3;
			int rawi=rawr+x;

			BMP->data[BMPi]=img->pixels[rawi].b;
			BMP->data[BMPi+1]=img->pixels[rawi].g;
			BMP->data[BMPi+2]=img->pixels[rawi].r;
		}
	}

	return BMP;
}

void saveBMP(const char* name,Image* img){
	std::ofstream file(name,std::ios::binary);
	file.write(reinterpret_cast<const char*>(&img->file),sizeof(img->file));
	file.write(reinterpret_cast<const char*>(&img->info),sizeof(img->info));
	file.write(reinterpret_cast<const char*>(img->data.data()),img->data.size());
}

int max(int a,int b){return a>b?a:b;}
