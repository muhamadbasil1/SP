#include<stdio.h>
#include<myStr.h>
int main()
{
	char *arr="mdam";
	if(isPalindrome(arr,5)==1)
		printf("Palindrome\n");
	else
		printf("Not a Palindrome\n");
}
