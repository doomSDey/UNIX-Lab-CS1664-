#include<stdio.h>
#include<fcntl.h>
int main()
{
        int i,j;
        char buf1[3],buf2[3];
        i=open("a",O_RDONLY);
        j=dup(i);
        read(i,buf1,2);
        read(j,buf2,2);
        buf1[2]='\0';
        buf2[2]='\0';
        //read(j,buf,sizeof(buf2));
        printf("%s\n",buf1);
        printf("%s\n",buf2);
        close(j);
        close(i);
        return 0;
}



