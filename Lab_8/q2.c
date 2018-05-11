#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[256];
	int fd = open("file1.txt",O_RDONLY);
	close(1);
	int fd1 = open("errorAndoutput.txt",O_CREAT|O_WRONLY,0777);
	close(2);
	int fd2 = dup(fd1);
	if(fd==-1)
	{
		perror("Error: ");
	}
	else
	{
		while(1)
		{
			int n = read(fd,buff,255);
			if(n<=0)
				break;
			write(1,buff,n);
		}
	}
	close(fd);
	close(fd1);
	close(fd2);
}
