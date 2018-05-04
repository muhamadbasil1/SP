#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	char ch[256];
	int n;
	int fd1 = open("newFile.txt",O_WRONLY|O_CREAT,0777);
	int fd2 = open("f1.txt",O_RDONLY|O_CREAT,0777);
	while(1)
	{
		n=read(fd2,ch,255);
		if(n<=0)
			exit(1);
		
		write(fd1,ch,n);
	}
	return 0;
	
}
