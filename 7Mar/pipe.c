#include<stdio.h>
#define READ 0
#define WRITE 1
char* phrase="my first program  in Inter process communication";
main()
{
int fd[2],bytesRead;
char msg[100];
        pipe(fd);
        if(fork()==0)
        {
                close(fd[READ]);
                write(fd[WRITE],phrase,strlen(phrase)+1);
                close(fd[WRITE]);
        }
        else
        {
                close(fd[WRITE]);
                bytesRead=read(fd[READ],msg,100);
                printf("Read %d bytes: %s\n",bytesRead,msg);
                close(fd[READ]);
        }
}



