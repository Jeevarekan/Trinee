#include<iostream>
#include<Windows.h>

#define WEIGHTEDRED	0.299
#define WEIGHTEDGREEN	0.587
#define WEIGHTEDBLUE	0.114
#define UMAX		0.436
#define VMAX		0.615

/////////////////////////////////////
// NAME       : rbgtoyuv()
// USE        : Use to calculate value of y,u and v
// PARAMETERS : float getvaluered , float getvaluegreen, float getvalueblue
/////////////////////////////////////
void rgbtoyuv( BYTE getvaluered, BYTE getvaluegreen, BYTE getvalueblue);

int main()
{
	FILE *fptrread;
	BYTE *ptrdatastore;
	BYTE valuered;
	BYTE valuegreen;
	BYTE valueblue;
	int height, length, size;
	int bytesperpixel = 3;
	int verifyreadfile;
	printf("Enter the height:\n");
	scanf("%d", &height);
	printf("Enter the length:\n");
	scanf("%d", &length);
	size = height * length * bytesperpixel;
	fptrread = fopen("D:\\Jeeva\\RGBFrame.raw", "rb");
	if (fptrread == NULL)
	{
		printf("File doesn't respond\n");
		exit(1);
	}
	ptrdatastore = (BYTE*)malloc(size);
	if (ptrdatastore == NULL)
	{
		printf("Memory is not allocated\n");
		exit(1);
	}
	verifyreadfile = fread(ptrdatastore, 1, size, fptrread);
	fclose(fptrread);
	if (verifyreadfile != size)
	{
		printf("Fread function return false value\n");
	}
	for (int i = 0; i < 3; i++)
	{
		valuered = *(ptrdatastore + i);
		i++;
		valuegreen = *(ptrdatastore + i);
		i++;
		valueblue = *(ptrdatastore + i);
	}
	rgbtoyuv(valuered,valuegreen,valueblue);
	return 0;
}

void rgbtoyuv( BYTE getvaluered , BYTE getvaluegreen, BYTE getvalueblue) 
{
	BYTE yvalue;
	BYTE uvalue;
	BYTE vvalue;
	yvalue = (WEIGHTEDRED * getvaluered) + (WEIGHTEDGREEN * getvaluegreen) + (WEIGHTEDBLUE * getvalueblue);
	uvalue = UMAX * ((getvaluered - yvalue) / (1 - WEIGHTEDBLUE));
	vvalue = VMAX * ((getvaluered - yvalue) / (1 - WEIGHTEDRED));
	printf("\n%d \n", yvalue);
	printf("%d \n", uvalue);
	printf("%d \n", vvalue);

}