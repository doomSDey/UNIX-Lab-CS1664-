#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
char* phrase="stuff this in yopur pipe and smoke";
int main()
{
        int fd1;
        fd1=open("mypipe",O_WRONLY);
        write(fd1,phrase,strlen(phrase)+1);
        close(fd1);
}




