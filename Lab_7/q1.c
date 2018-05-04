#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int size,char *args[])
{ 
	char ch[256];
	int n;
	
	int fd1 = open( args[2] ,O_WRONLY|O_CREAT,0777);
	int fd2 = open(args[1],O_RDONLY);
	while(1)
	{
		n=read(fd2,ch,255);
		if(n<=0)
			exit(1);
		
		write(fd1,ch,n);
	}	
	
	return 0;
	
}
