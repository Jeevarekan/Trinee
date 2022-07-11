#include<iostream>
#include<Windows.h>
int main()
{
	FILE *fptr;
	FILE *fptr1;
	BYTE *ptr;
	//BYTE *ptr1;
	//int arr;
	int i=0, size;
	int verify;
	int bytesperpixel = 3;
	ptr = (BYTE*)malloc(size);
	/*ptr1 = (BYTE*)malloc(size);*/
	if (ptr == NULL)
	{
		printf("Memory is not allocated\n");
		exit(1);
	}
	fptr = fopen("D:\Jeeva\RGBFrames", "rb+");
	if (fptr == NULL)
	{
		printf("File doesn't respond");
		exit(1);
	}
	verify=fread(ptr, 1, size, fptr);
	fptr1 = fopen("Copiedfile", "wb");
	if (fptr == NULL)
	{
		printf("File doesn't created");
		exit(1);
	}
	/*while (verify != EOF)
	{
		*(ptr1+i) = *(ptr+i);
		i++;
	}*/
	fwrite(ptr, 1, size, fptr1);
	fclose(fptr);
	/*fclose(fptr1);*/
	return 0;
}