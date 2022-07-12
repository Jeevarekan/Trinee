#include<iostream>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;
	BYTE *ptr1;
	BYTE *ptr2;
	BYTE *ptr3;
	int byteperpixel = 3;
	int x, y, size;
	BYTE arr1 = 0x7D, arr2 = 0xFF, arr3 = 0;
	int i, a, b, c;
	printf("Enter the Size:\n");
	scanf("%d", &x);
	printf("*"); scanf("%d", &y);
	size = x * y * byteperpixel;
	ptr1 = (BYTE*)malloc(size);
	ptr2 = (BYTE*)malloc(size);
	ptr3 = (BYTE*)malloc(size);
	if (ptr1 == NULL)
	{
		printf("Memory Allocation for grayfile is failed\n");
		exit(1);
	}
	if (ptr2 == NULL)
	{
		printf("Memory Allocation for whitefile is Failed\n");
		exit(1);
	}
	if (ptr3 == NULL)
	{
		printf("Memory Allocation for blackfile is Failed");
		exit(1);
	}
	for (i = 0; i < size; i = i + byteperpixel)
	{
		*(ptr1 + i) = arr1;

	}
	for (i = 1; i < size; i = i + byteperpixel)
	{
		*(ptr2 + i) = arr1;
	}
	for (i = 2; i < size; i = i + byteperpixel)
	{
		*(ptr3 + i) = arr1;
	}
	fptr1 = fopen("gray.raw", "wb");
	if (fptr1 == NULL)
	{
		printf("File gray doesn't created");
		exit(1);
	}
	a = fwrite(ptr1, 1, size, fptr1);
	if (a != size)
	{
		printf("Value not assigned properly for grayfile");
	}
	fptr2 = fopen("white.raw", "wb");
	if (fptr2 == NULL)
	{
		printf("File white doesn't created");
		exit(1);
	}
	b = fwrite(ptr2, 1, size, fptr2);
	if (b != size)
	{
		printf("Value not assigned properly for whitefile");
	}
	fptr3 = fopen("black.raw", "wb");
	if (fptr3 == NULL)
	{
		printf("File black doesn't created");
		exit(1);
	}
	c = fwrite(ptr3, 1, size, fptr3);
	if (c != size)
	{
		printf("Value not assigned properly for blackfile");
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;

}