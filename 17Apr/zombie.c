#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid,status;
	pid=fork();

	if(pid==0)
	{
		printf("child process pid:%d\n",getpid());
	}
	else
	{
		printf("parent process id:%d\n",getpid());
		sleep(30);
		wait(&status);
		printf("parent process terminated\n");
	}

	return 0;
}
