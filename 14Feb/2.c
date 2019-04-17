#include<stdio.h>
int main()
{
	char b[20];
	int fd,xr;
	if((fd=open("write",0))==-1)
	{
		printf("can't open file\n");
		exit(1);
	}
	do
	{
		xr=read(fd,b,20);
		b[xr]='\0';
		printf("%s",b);
	}while(xr==20);
	close(fd);
}
