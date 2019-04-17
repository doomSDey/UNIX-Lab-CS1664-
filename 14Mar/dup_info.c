#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	char buf[2],buf1[5],buf2[5],buf3[5];
	if(argc!=2)
	{
		printf("enter a file name as argument\n");
		return 0;
	}
	int fd,xr,fd1;

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		printf("error opening file\n");
		return 0;
	}
	int dupfd=dup(fd);

	int dup2fd=5;
	int dup3fd=10;

	dup2(fd,dup2fd);
	dup3(fd,dup3fd,O_CLOEXEC);

	printf("value of original fd=%d\n",fd);
	printf("value of dup fd=%d\n",dupfd);
	printf("value of dup2 fd=%d\n",dup2fd);
	printf("value of dup3 fd=%d\n",dup3fd);

	read(fd,buf,sizeof(buf));
	read(dupfd,buf1,sizeof(buf1));
	read(dup2fd,buf2,sizeof(buf2));
	read(dup3fd,buf3,sizeof(buf3));

	printf("data from original fd : %s\n",buf);
	printf("data from dup fd : %s\n",buf1);
	printf("data from dup2 fd : %s\n",buf2);
	printf("data from dup3 fd : %s\n",buf3);

	close(dupfd);
	close(fd);
	return 0;
}
