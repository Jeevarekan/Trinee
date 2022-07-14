#include<iostream>
#include<Windows.h>

#define YUVPERPIXEL 2
int width = 640;
int height = 480;

BYTE imagerotation(BYTE *getreadvalue, BYTE *getwritevalue);
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
		printf("Fread function returns false value\n");
	}
	fclose(fptrread);
	ptrwrite = (BYTE*)malloc(width*height*YUVPERPIXEL);
	if (ptrwrite == NULL)
	{
		printf("Memory allocation is failed\n");
	}
	imagerotation(ptrread,ptrwrite);
	fptrwrite = fopen("D:\\Jeeva\\FilesTesting\\Rotatedfile.raw", "wb");
	int verifywritefile = fwrite(ptrwrite, 1, width*height*YUVPERPIXEL, fptrwrite);
	if (verifywritefile != width * height*YUVPERPIXEL)
	{
		printf("Fwrite function returns false value\n");
	}
	fclose(fptrwrite);
	return 0;
}

BYTE imagerotation(BYTE *getreadvalue, BYTE *getwritevalue)
{
	int i;
	int j;
	int subheight;
	int subwidth;
	int temp;
	int size = width * height*YUVPERPIXEL;
	temp = width;
	width = height;
	height = temp;
	BYTE copyvalue;
	/*for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			*getwritevalue[i][j] = *getreadvalue[width - 1 - j][i];
		}
	}*/
	//for (i =0; i < height; i++)
	//{
	//	subwidth = width;
	//	subheight = 0;
	//	for (j = 0; j < width; j++)
	//	{
	//		*(getwritevalue + subheight ) = *(getreadvalue + subwidth);
	//		subwidth--;
	//		subheight++;
	//	}
	//	subwidth = subwidth * 2;
	//}

	return *getwritevalue;

}