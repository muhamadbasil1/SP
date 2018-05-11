#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[256];
	int fd = open("/etc/passwd",O_RDONLY);
	int fd1 = dup(fd);
	while(1)
	{
		int n = read(fd1,buff,255);
		if(n<=0)
			break;
		write(0,buff,n);
	}
	close(fd);
	close(fd1);
}
