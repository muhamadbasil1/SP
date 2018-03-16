#include<stdio.h>
#include"myMath.h"
int main()
{
	if( isEqual(3,3) == 1 )
		printf("Equal\n");
	else
		printf("Not Equal\n");
	swap(2,4);
}
