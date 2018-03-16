#include<stdio.h>
int isPalindrome(char *arr,int size)
{
	int i=0;
	int j=size-1;
	for(i;i<size/2;i++)
	{
		if(arr[i]!=arr[j])
			return -1;
		j--;
	}
	return 1;
}
