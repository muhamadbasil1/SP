#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void mySignalHandler(int signum)
{
	printf("Signal Number: %d\n",signum);
}

int main()
{
	signal(SIGINT,mySignalHandler);
	signal(SIGTSTP,mySignalHandler);
	signal(SIGFPE,mySignalHandler);
	signal(SIGHUP,mySignalHandler);
	signal(SIGQUIT,mySignalHandler);
	
	while(1)
	{
		printf("Running!\n");
		sleep(2);
	}
	return 0;
}
