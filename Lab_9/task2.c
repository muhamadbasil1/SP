#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	pid_t cpid=fork();
	if(cpid==0)
	{
		while(1)
		{
			printf("Child!\n");
		}
	}
	else
	{
		sleep(5);
		kill(cpid,SIGINT);
		printf("Parent");
		_exit(0);
	}
	return 0;
}
