#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int f=fork();
	int status;
	if(f==-1)
	{
		printf("Fork Failed!!\n");
		exit(1);
	}
	if(f==0)
	{
		exit(-1);
	}
	else
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Exit status= %d\n",WEXITSTATUS(status));
		}
		printf("My PID: %d\n",(long)getpid());
		printf("My PPID: %d\n",(long)getppid());
	}
}
