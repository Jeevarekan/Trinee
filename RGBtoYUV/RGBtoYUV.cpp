#include<iostream>
#include<Windows.h>

#define WEIGHTEDRED	0.299
#define WEIGHTEDGREEN	0.587
#define WEIGHTEDBLUE	0.114
#define UMAX		0.436
#define VMAX		0.615
#define RGBPERPIXEL 3
#define YUVPERPIXEL 2

int width = 640;
int height = 480;

BYTE rgbtoyuv(BYTE *getrgbframe, BYTE *getuyvyframe);

int main()
{
	FILE *fptrread;
	FILE *fptrwrite;
	BYTE *rgbframe;
	BYTE *uyvyframe;
	fptrread = fopen("D:\\Jeeva\\RGBFrame.raw", "rb");
	if (fptrread == NULL)
	{
		printf("File doesn't respond\n");
		exit(1);
	}
	rgbframe = (BYTE*)malloc(width * height * RGBPERPIXEL);
	uyvyframe = (BYTE*)malloc(width * height * YUVPERPIXEL);
	if (rgbframe == NULL)
	{
		printf("Memory is not allocated\n");
		exit(1);
	}
	if (uyvyframe == NULL)
	{
		printf("Memory is not allocated\n");
		exit(1);
	}
	int verifyreadfile = fread(rgbframe, 1, width * height * RGBPERPIXEL, fptrread);
	fclose(fptrread);
	if (verifyreadfile != width * height * RGBPERPIXEL)
	{
		printf("Fread function return false value\n");
	}
	rgbtoyuv(rgbframe, uyvyframe);
	fptrwrite = fopen("D:\\Jeeva\\FilesTesting\\YUVfile.raw", "wb");
	if (fptrwrite == NULL)
	{
		printf("File doesn't created\n");
		exit(1);
	}
	int verifywritefile= fwrite(uyvyframe, 1, width * height * YUVPERPIXEL, fptrwrite);
	if (verifywritefile != width * height * YUVPERPIXEL)
	{
		printf("Fwrite function return false value\n");
	}
	fclose(fptrwrite);
	return 0;
}

BYTE rgbtoyuv( BYTE *getrgbframe , BYTE *getuyvyframe) 
{
	int j = 0;
	BYTE yvalue;
	BYTE uvalue;
	BYTE vvalue;
	BYTE ynxtvalue;
	BYTE unxtvalue;
	BYTE vnxtvalue;
	BYTE valuered;
	BYTE valuegreen;
	BYTE valueblue;
	BYTE nxtvaluered;
	BYTE nxtvalueblue;
	BYTE nxtvaluegreen;
	for (int i = 0; i < (width * height * RGBPERPIXEL); i = i + 6)
	{
		valuered = *(getrgbframe + i);
		valuegreen = *(getrgbframe + i + 1);
		valueblue = *(getrgbframe + i + 2);
		nxtvaluered = *(getrgbframe + i + 3);
		nxtvaluegreen = *(getrgbframe + i + 4);
		nxtvalueblue = *(getrgbframe + i + 5);

		yvalue = (0.257 * valuered) + (0.504 * valuegreen) + (0.098 * valueblue) + 16;
		vvalue = (0.439 * valuered) - (0.368 * valuegreen) - (0.071 * valueblue) + 128;
		uvalue = -(0.148 * valuered) - (0.291 * valuegreen) + (0.439 * valueblue) + 128;

		ynxtvalue = (0.257 * nxtvaluered) + (0.504 * nxtvaluegreen) + (0.098 * nxtvalueblue) + 16;
		vnxtvalue = (0.439 * nxtvaluered) - (0.368 * nxtvaluegreen) - (0.071 * nxtvalueblue) + 128;
		unxtvalue = -(0.148 * nxtvaluered) - (0.291 * nxtvaluegreen) + (0.439 * nxtvalueblue) + 128;

		unxtvalue = (uvalue + unxtvalue) / 2;
		vnxtvalue = (vvalue + vnxtvalue) / 2;
		*(getuyvyframe + j) = unxtvalue;
		*(getuyvyframe + j + 1) = yvalue;
		*(getuyvyframe + j + 2) = vnxtvalue;
		*(getuyvyframe + j + 3) = ynxtvalue;
		j = j + 4;
	}
	return *getuyvyframe;
		
}