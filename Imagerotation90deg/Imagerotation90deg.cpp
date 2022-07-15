#include<iostream>
#include<Windows.h>

#define YUVPERPIXEL 2
int width = 640;
int height = 480;

bool imagerotation(BYTE *getreadvalue, BYTE *getwritevalue);
int main()
{
	FILE *fptrread;
	FILE *fptrwrite;
	BYTE *ptrread;
	BYTE *ptrwrite;
	fptrread = fopen("D:\\Jeeva\\FilesTesting\\YUVfile.raw", "rb");
	ptrread = (BYTE*)malloc(width*height*YUVPERPIXEL);
	if (ptrread == NULL)
	{
		printf("Memory allocation is failed\n");
	}
	int verifyreadfile = fread(ptrread, 1, width*height*YUVPERPIXEL,fptrread);
	if (verifyreadfile != width * height * YUVPERPIXEL)
	{
		printf("Fread function returned the value less than provided value\n");
	}
	fclose(fptrread);
	ptrwrite = (BYTE*)malloc(width*height*YUVPERPIXEL);
	if (ptrwrite == NULL)
	{
		printf("Memory allocation is failed\n");
	}
	bool validate = imagerotation(ptrread,ptrwrite);
	if (validate == false)
	{
		printf("Imagerotation function unvalid value\n ");
	}
	fptrwrite = fopen("D:\\Jeeva\\FilesTesting\\Rotatedfile.raw", "wb");
	int verifywritefile = fwrite(ptrwrite, 1, width*height*YUVPERPIXEL, fptrwrite);
	if (verifywritefile != width * height*YUVPERPIXEL)
	{
		printf("Fwrite function returns false value\n");
	}
	fclose(fptrwrite);
	return 0;
}
//////////////////////////////////////////////////////////
//NAME       : imagerotation()
//USE        : To rotate uyvy image into 90deg
//Parameters : BYTE *getreadvalue, BYTE *getwritevalue
/////////////////////////////////////////////////////////
bool imagerotation(BYTE *getreadvalue, BYTE *getwritevalue)
{
	int iloop;
	int jloop, kcal=0;
	int cal = 0;
	int temp;
	int size = width * height * YUVPERPIXEL;
	temp = width;
	width = height;
	height = temp;
	for (iloop = 1 ; iloop <= height* YUVPERPIXEL; ++iloop)
	{
		cal = (size - height* YUVPERPIXEL) + iloop;
		for (jloop =1; jloop <= width ; ++jloop)
		{
			*(getwritevalue + kcal) = *(getreadvalue + cal);
			kcal++;
			cal = cal - height* YUVPERPIXEL;
		}
	}
	return *getwritevalue;

}