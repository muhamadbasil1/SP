#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[256];
	close(2);
	int fd2 = dup(1);
	close(1);
	int fd1 = open("f2.txt",O_WRONLY);
	close(0);
	int fd = open("f1.txt",O_RDONLY);
	while(1)
	{
		int n = read(0,buff,255);
		if(n<=0)
			break;
		write(1,buff,n);
	}
	close(fd);
	close(fd1);
	close(fd2);
}
