#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char * argv[])
{
	char x[100],y[100];
	int fd,xr,fd2;
	char b[20];
	//x=argv[1];
	//y=argv[2];
	if((fd=open(argv[1],0))==-1 && (fd2=open(argv[2],"w"))==-1)
	{
		printf("can't open file\n");
		return 0;
	}
	//do{
		xr=read(fd,b,sizeof(b));
		b[xr]='\0';
	//}while(xr==20);
		//printf("%s",argv[2]);
	int dx=write(fd2,b,xr);
			//printf("buffer write error\n");
	close(fd);
	close(fd2);
}
