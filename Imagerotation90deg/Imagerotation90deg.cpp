#include<iostream>
#include<Windows.h>

#define YUVPERPIXEL 2
#define RGBPERPIXEL 3
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
		printf("Imagerotation function gives unvalid value\n ");
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
	int size = width * height * YUVPERPIXEL;
	BYTE yvalue;
	BYTE ynxtvalue;
	BYTE uvalue;
	BYTE unxtvalue;
	BYTE vvalue;
	BYTE vnxtvalue;
	/*BYTE *rgbptr;
	BYTE rvalue;
	BYTE gvalue;
	BYTE bvalue;*/
	int funwidth;
	int funheight;
	funwidth = height;
	funheight = width;
	/*rgbptr = (BYTE*)malloc(width*height*RGBPERPIXEL);
	if (rgbptr == NULL)
	{
		printf("Memory allocation is failed\n");
	}*/
	
	/*for (iloop = 0; iloop < funheight; iloop++)
	{
		cal = (size - funheight) + ical;
		for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop++)
		{
			yvalue = *(getreadvalue + cal);
			*(getwritevalue + jcal) = yvalue;
			jcal++;
			cal = (cal - funheight);
		
		}
		ical=ical+2;
	}*/
	/*for (iloop = 0; iloop < funheight; iloop++)
	{
		cal = (size - (funheight * YUVPERPIXEL)) + ical;
		for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop = jloop + 2)
		{
			*(getwritevalue + jcal) = *(getreadvalue + cal);
			jcal = jcal + 2;
			cal = (cal - funheight * YUVPERPIXEL);
		}
		ical = ical + 2;
	}
	cal = 0;
	jcal = 0;
	ical = 1;*/
	for (iloop = 0; iloop < funheight; iloop++)
	{
		cal = (size -(funheight * YUVPERPIXEL)) + ical;
		for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop=jloop+2)
		{
			*(getwritevalue + jcal) = *(getreadvalue + cal);
			yvalue = *(getreadvalue + cal);
			*(getwritevalue + jcal+1) = yvalue;
			jcal = jcal + 2;
			cal = (cal - funheight*YUVPERPIXEL);
		}
		ical = ical + 2;
	}

	//for (iloop = 1; iloop <= funheight; iloop++)
	//{
	//	cal = (size - funheight*YUVPERPIXEL) + ical;
	//	for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop++)
	//	{
	//		*(getwritevalue + jcal) = *(getreadvalue + cal);
	//		jcal++;
	//	/*	yvalue = *(getreadvalue + cal);
	//		*(getwritevalue + jcal) = yvalue;*/
	//		cal = (cal - funheight)-1;

	//	}
	//	ical = ical + 1;
	//}
	/*
	jcal = 1;
	for (iloop = 1; iloop <= funheight; iloop++)
	{
		cal = (size - funheight) + ical;
		for (jloop = 0; jloop < funwidth*YUVPERPIXEL; jloop++)
		{
			yvalue = *(getreadvalue + cal);
			*(getwritevalue + jcal) = yvalue;
			jcal=jcal+2;
			cal = (cal - funheight)-2;

		}
		ical = ical + 2;
	}*/
	//conversion
	//for (iloop = 0, jloop = 0; iloop < width*height*RGBPERPIXEL; iloop = iloop + 6, jloop = jloop + 4)
	//{
	//	//first pixel
	//	uvalue = *(getreadvalue + jloop);
	//	yvalue = *(getreadvalue + jloop + 1);		
	//	vvalue = *(getreadvalue + jloop + 2);

	//	rvalue = yvalue + (1.4065 *(vvalue - 128));
	//	gvalue = yvalue - (0.3455*(uvalue - 128)) - (0.7169*(vvalue - 128));
	//	bvalue = yvalue + (1.7790*(uvalue - 128));

	//	*(rgbptr + iloop) = rvalue;
	//	*(rgbptr + iloop + 1) = gvalue;
	//	*(rgbptr + iloop + 2) = bvalue;

	//	//next pixel
	//	unxtvalue = *(getreadvalue + jloop);
	//	ynxtvalue = *(getreadvalue + jloop + 3);
	//	vnxtvalue = *(getreadvalue + jloop + 2);

	//	rvalue = ynxtvalue + (1.4065 *(vnxtvalue - 128));
	//	gvalue = ynxtvalue - (0.3455*(unxtvalue - 128)) - (0.7169*(vnxtvalue - 128));
	//	bvalue = ynxtvalue + (1.7790*(unxtvalue - 128));

	//	*(rgbptr + iloop + 3) = rvalue;
	//	*(rgbptr + iloop + 4) = gvalue;
	//	*(rgbptr + iloop + 5) = bvalue;

	//}


	//for (iloop = 1; iloop <= funheight; iloop++)
	//{
	//	cal = ((width*height*RGBPERPIXEL) - funheight) + ical;
	//	for (jloop = 0; jloop < funwidth*RGBPERPIXEL; jloop=jloop+3)
	//	{
	//		*(getwritevalue + jcal) = *(rgbptr + cal);
	//		*(getwritevalue + jcal+1) = *(rgbptr + cal + 1);
	//		*(getwritevalue + jcal+2) = *(rgbptr + cal + 2);
	//		jcal=jcal+3;
	//		cal = (cal - funheight*RGBPERPIXEL);
	//	}
	//	ical = ical + 3;
	//}

	////rotation

	//for (iloop = 0; iloop < funheight*RGBPERPIXEL; iloop++)
	//{
	//	cal = ((funheight*funwidth*RGBPERPIXEL) - funheight*RGBPERPIXEL) + ical;
	//	for (jloop = 0; jloop < funwidth; jloop++)
	//	{
	//		*(getwritevalue + jcal) = *(rgbptr + cal);
	//		cal = (cal - (funheight*RGBPERPIXEL));
	//		jcal++;
	//	}
	//	ical++;
	//}	
	


	return *getwritevalue;
}

	
	
