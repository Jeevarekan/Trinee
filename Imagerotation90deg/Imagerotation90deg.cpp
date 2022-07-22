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
	int jloop;
	int ical = 1;
	int jcal = 0;
	int kcal = 0;
	int cal = 0;
	int temp;
	int size = width * height * YUVPERPIXEL;
	BYTE yvalue;
	BYTE ynxtvalue;
	BYTE uvvalue;
	BYTE uvalue;
	BYTE vvalue;
	int funwidth;
	int funheight;
	funwidth = height;
	funheight = width;
	for (iloop = 0; iloop < size; iloop = iloop + 4)
	{
		uvalue = *(getreadvalue + iloop );
		yvalue = *(getreadvalue + iloop + 1);
		vvalue = *(getreadvalue + iloop + 2);
		ynxtvalue = *(getreadvalue + iloop + 3);
	}

	for (iloop = 1; iloop <= funheight; iloop++)
	{
		cal = (size - funheight) + ical;
		for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop++)
		{
			uvvalue = *(getreadvalue + cal);
			*(getwritevalue + jcal) = uvvalue;
			cal++;
			jcal++;
			ynxtvalue = *(getreadvalue + cal);
			*(getwritevalue + jcal) = yvalue;
			cal = (cal - funheight) - 1;
		}
		ical=ical+2;
	}

	
	return *getwritevalue;
}

	
	
