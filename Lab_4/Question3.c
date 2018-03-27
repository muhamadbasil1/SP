#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
static jmp_buf env;
void firstSetJmp(int c)
{
	printf("Counter Value: %d\n",c);
	c=c+1;
	longjmp(env,c);
}
void haveFun(int c)
{
	printf("Counter Value: %d\n",c);
	c=c+1;
	longjmp(env,c);
}
int main()
{
	int counter;
	counter = setjmp(env);
	if(counter == 0)
		firstSetJmp(counter);
	else
		haveFun(counter);
	return 0;
}
