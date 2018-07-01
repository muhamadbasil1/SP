#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	sigset_t newset,oldset;
	sigemptyset(&newset);
	sigaddset(&newset,SIGINT);
	sigaddset(&newset,SIGHUP);
	sigaddset(&newset,SIGTSTP);
	sigaddset(&newset,SIGQUIT);
	sigaddset(&newset,SIGINT);
	int count=0;
	sigprocmask(SIG_SETMASK,&newset,&oldset);
	while(count!=40)
	{
		printf("Signals Blocked!\n");
		sleep(2);
		count++;
	}
	sigprocmask(SIG_SETMASK,&oldset,NULL);
	while(count!=20)
	{
		printf("Signal Unblocked!\n");
		sleep(2);
		count++;
	}
	return 0;
}
