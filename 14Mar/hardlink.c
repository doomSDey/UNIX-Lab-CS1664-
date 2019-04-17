#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int f=link("a.txt","new2.txt");
}
