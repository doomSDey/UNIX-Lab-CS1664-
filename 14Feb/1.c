#include<stdio.h>
int main()
{
	int fd;
	if((fd=open("file.dat"))==-1)
	{
		perror("can't open file.dat");
		exit(0);
	}
	else
		printf("\nFile Opened\n");
	return 0;
}
