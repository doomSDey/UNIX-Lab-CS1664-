#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        int pid;
        pid=fork();
        if(pid==0)
        {
                sleep(3);
                printf("in child process id=%d\n",getpid());
		sleep(3);
		printf("child process out of sleep");
		printf("in parent process id=%d\n",getppid());
        }
        else if(pid>0)
	{
       	 	printf("in parent process id=%d\n",getpid());
	}
	sleep(7);
			printf("in parent process id=%d\n",getppid());
	return 0;
}

