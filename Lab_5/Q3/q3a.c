#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int f=fork();
	if(f==-1)
	{
		printf("Fork Failed!!\n");
		exit(1);
	}
	if(f==0)
	{
		printf("My Child PID: %d\n",(long)getpid());
		printf("My Child PPID: %d\n",(long)getppid());
	}
	else
	{
		wait(NULL);
		printf("My PID: %d\n",(long)getpid());
		printf("My PPID: %d\n",(long)getppid());
	}
}
