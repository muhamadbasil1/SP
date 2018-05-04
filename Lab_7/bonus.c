#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int size,char *args[])
{ 
	char ch[256];
	int n,fd=1;
	if(size > 1)
	{
		close(1);
		fd=open( args[1] ,O_WRONLY|O_CREAT,0777 );
	}
	printf("hello");
	int fd2 = open("abc.txt",O_RDONLY);
	while(1)
	{
		n=read(fd2,ch,255);
		if(n<=0)
			break;
		
		write(fd,ch,n);
	}	
	
	return 0;
	
}
