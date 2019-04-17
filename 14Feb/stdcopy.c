	#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[]){

	int file1=open(argv[1],O_RDWR|O_APPEND);
	int file2=open(argv[2],O_CREAT|O_RDWR);
	int xr;
	if (file1 >0 && file2 >0){
		printf("\nFile Opened:\n");
		char buff[100];
		xr=read(file1,buff,sizeof(buff));
		buff[xr]='\0';
		printf("\nRead from file:%s\n",buff);
		int inf=write(file2,buff,xr);
		printf("\nWritten bytes:%d\n",inf);

	}
	else{
		printf("\nError\n");

	}
	return 0;
}
