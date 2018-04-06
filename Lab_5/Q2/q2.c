#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
extern errno;

int main()
{
	uid_t ruid, euid, suid;
	gid_t rgid, egid, sgid;
	getresuid(&ruid,&euid,&suid);
	printf("Real user-ID: %d\n",ruid);
	printf("Effective user-ID: %d\n",euid);
	printf("Saved user-ID: %d\n",suid);
	
	getresgid(&rgid,&egid,&sgid);
	printf("Real group-ID: %d\n",rgid);
	printf("Effective group-ID: %d\n",egid);
	printf("Saved group-ID: %d\n",sgid);
	
	int x=setuid(501);
	if(x!=-1)
	{
		printf("After Successful setuid(501)\n");
		getresuid(&ruid,&euid,&suid);
		printf("Real user-ID: %d\n",ruid);
		printf("Effective user-ID: %d\n",euid);
		printf("Saved user-ID: %d\n",suid);
		
		getresgid(&rgid,&egid,&sgid);
		printf("Real group-ID: %d\n",rgid);
		printf("Effective group-ID: %d\n",egid);
		printf("Saved group-ID: %d\n",sgid);
	}
	else
	{
		printf("Error!!!\n");
	}
}
