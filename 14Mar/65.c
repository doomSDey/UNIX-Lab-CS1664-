#include<stdio.h>
#include<fcntl.h>
int main()
{
        int i,j;
        char buf1[1],buf2[2];
        int fd=open("a.txt",O_RDWR);
        int val=fcntl(fd,F_GETFL,0); 
        int accmode=val &O_ACCMODE;
        if(accmode==O_RDONLY)
        	printf("read allowed\n");
        if(accmode==O_WRONLY)
        	printf("write allowed\n");
        if(accmode==O_RDWR)
        	printf("read and write allowed\n");
        if(accmode==O_APPEND)
        	printf("append mode allowed\n");
        if(access("a.txt",W_OK)<0)
        	printf("write error\n");
        close(fd);
        return 0;
}
        
