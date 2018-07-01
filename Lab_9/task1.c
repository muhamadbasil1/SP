#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	signal(SIGINT,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);
	signal(SIGFPE,SIG_IGN);
	signal(SIGHUP,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	
	while(1)
	{
		printf("Running!\n");
		sleep(1);
	}
	return 0;
}
