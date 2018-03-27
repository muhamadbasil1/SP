#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	int *p1,*p2,*p3,*p4;
	printf("Current Program break Address: 0x%d \n",sbrk(0));
	p1=(int*) malloc (1);
	printf("After p1 malloc : 0x%d \n",sbrk(0));
	p2=(int*) malloc (3);
	printf("After p2 malloc : 0x%d \n",sbrk(0));
	p3=(int*) malloc (5);
	printf("After p3 malloc : 0x%d \n",sbrk(0));
	p4=(int*) malloc (7);
	printf("After p4 malloc : 0x%d \n",sbrk(0));
	//values does not change bcoz malloc takes large space from 
	//OS on the first attempt!!
	
	
	
	printf("p1: %d \np2: %d \np3: %d \np4: %d \n",p1,p2,p3,p4);
	//malloc calls sbrk()!!
	return 0;
}
