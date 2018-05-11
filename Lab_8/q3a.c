#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[256];
	close(0);
	int fd = open("f1.txt",O_RDONLY);
	close(1);
	int fd1 = dup(fd);
	close(2);
	int fd2 = dup(fd);
	while(1)
	{
		int n = read(fd,buff,255);
		if(n<=0)
			break;
		write(1,buff,n);
	}
	close(fd);
	close(fd1);
	close(fd2);
}
