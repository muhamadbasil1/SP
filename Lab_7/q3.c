#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	char ch[256];
	int n;
	int fd = open("newFile.txt",O_WRONLY|O_CREAT,0777);
	while(1)
	{
		n=read(0,ch,255);
		if(n<=0)
			exit(1);
		
		write(fd,ch,n);
	}
	return 0;
	
}
