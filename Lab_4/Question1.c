#include<stdio.h>
#include<stdlib.h>
int main()
{
	//Creating 1D array of size 10
	int size=10;
	//malloc
	int *arr=(int*) malloc (sizeof(int)* size);
	int i=0;
	for(i;i<size;i++)
	{
		arr[i]=i*i;
	}
	for(i=0;i<size;i++)
	{
		printf("Value at %d is: %d\n",i,arr[i]);
	}
	printf("\n\nNew Array!!\n");
	
	//realloc
	int s=2*size;
	int *arr1=(int*) realloc (arr,sizeof(int)* s);
	for(i;i<s;i++)
	{
		arr1[i]=i;
	}
	for(i=0;i<s;i++)
	{
		printf("Value at %d is: %d\n",i,arr1[i]);
	}
	free(arr1);
	return 0;
}
