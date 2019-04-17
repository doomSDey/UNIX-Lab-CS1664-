#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/stat.h>
//#include "./include/apue.h"

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main()
{
	int fd;
	if((fd=creat("a.txt",'w'))<0)
		printf("create error");
	if(write(fd,buf1,10)!=10)
		printf("buff1 write error");
	exit(0);
}
