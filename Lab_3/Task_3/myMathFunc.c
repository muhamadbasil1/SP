#include<stdio.h>

int isEqual(int x,int y)
{
	if(x==y)
		return 1;
	else
		return -1;
}
int swap(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	printf(a);
}
