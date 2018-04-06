#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	printf("Real user-ID: %d\n",getuid());
	printf("Effective user-ID: %d\n",geteuid());
	printf("Real group-ID: %d\n",getgid());
	printf("Effective group-ID: %d\n",getegid());
}
