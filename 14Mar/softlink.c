#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int f=symlink("a.txt","new.txt");
}
