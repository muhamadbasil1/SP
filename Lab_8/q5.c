#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main(int size,void * args[])
{
	if(access(args[1],R_OK)==0)
		printf("Reading Permission\n");
	if(access(args[1],W_OK)==0)
		printf("Writing Permission\n");
	if(access(args[1],X_OK)==0)
		printf("Executing Permission\n");
}
