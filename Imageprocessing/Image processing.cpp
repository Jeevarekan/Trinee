#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	FILE *fptr;
	char *ptr;
	int x, y,z, arr;
	int i , j;
	cout << "Enter the Size:" << endl;
	cin >> x; cout << "*"; cin >> y;
	z = x * y;
	cout << "Enter the Number to be stored" << endl;
	cin >> arr;
	ptr = (char*)malloc(z * sizeof(char));
	if (ptr == NULL)
	{
		cout << "Memory Allocation Failed" << endl;
		exit(1);
	}
	else
	{
		free(ptr);
		ptr = NULL;
	}
	for (i = 0; i < z ; i++)
	{
		*(ptr + i) = arr;
	}
	*fptr = fopen("D:\\Jeeva\\bufferfile.txt","w");
	if (fptr==NULL)
	{
		printf("File doesn't created");
		exit(1);
	}
	fclose(fptr);
	return 0;

}
