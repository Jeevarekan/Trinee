#include<iostream>
#include<Windows.h>
int main()
{
	FILE *fptrread;
	FILE *fptrwrite;
	BYTE *ptr;
	int size;
	int verifyreadfile, verifywritefile;	
	fptrread = fopen("D:\\Jeeva\\RGBFrame.raw", "rb");
	if (fptrread == NULL)
	{
		printf("File doesn't respond\n");
		exit(1);
	}
	fseek(fptrread, 0, SEEK_END);
	size = ftell(fptrread);
	ptr = (BYTE*)malloc(size);
	if (ptr == NULL)
	{
		printf("Memory is not allocated\n");
		exit(1);
	}
	fseek(fptrread, 0, SEEK_SET);
	verifyreadfile=fread(ptr,1,size, fptrread);
	fclose(fptrread);
	if (verifyreadfile != size)
	{
		printf("Fread function returns false value\n");
	}
	fptrwrite = fopen("D:\\Jeeva\\FilesTesting\\Copiedfile.raw", "wb");
	if (fptrwrite == NULL)
	{
		printf("File doesn't created\n");
		exit(1);
	}
	verifywritefile=fwrite(ptr, 1, size, fptrwrite);
	if (verifywritefile != size)
	{
		printf("Fwrite function returns false value\n");
	}
	fclose(fptrwrite);
	return 0;
}