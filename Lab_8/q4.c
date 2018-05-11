#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main(int size,void * args[])
{
	int i=1;
	struct stat buff;
	
	for(i=1;i<size;i++)
	{
		stat(args[i],&buff);
		if(S_ISREG(buff.st_mode))
		{
			printf("%s",args[i]);
			printf(" is a Regular File\n");
			printf("Inode Number: %d\n",buff.st_ino);
			printf("Access Time: %d\n",buff.st_atime);
			printf("Modifies Time: %d\n",buff.st_mtime);
			printf("Size: %d\n",buff.st_size);
		}
		else if(S_ISDIR(buff.st_mode))
		{
			printf("%s",args[i]);
			printf(" is a Directory\n");
			printf("User ID: %d\n",buff.st_uid);
		}
			
	}
}
