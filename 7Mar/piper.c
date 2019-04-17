#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int fd1;
	char buf[100];
	fd1=open("mypipe",O_RDONLY);
	read(fd1,buf,100);
	printf("%s\n",buf);
	close(fd1);
}
