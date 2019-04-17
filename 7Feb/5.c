#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

void * ins(struct node * y,int x)
{
	if(y==NULL)
	{
		y=(struct node*)malloc(sizeof(struct node));
		y->next=NULL;
		y->prev=NULL;
		y->data=x;
	}
	else{
		while(y->next !=NULL)
		{
			y=y->next;
		}
		if(y->next==NULL)
		{
			struct node * newnode=(struct node*)malloc(sizeof(struct node));
			y->next=newnode;
			newnode->data=x;
			newnode->prev=y;
			newnode->next=NULL;
		}
	}
}

void display(struct node *  x)
{
	if(x->next==NULL)
		printf("%d->",x->data);
	while(x->next!=NULL)
	{
		printf("%d->",x->data);
		x=x->next;
	}
	printf("%d->",x->data);
	printf("\n");
}

int main()
{
	int i,n,x,z=1,n2,n3,ele[100];
	struct node arr[1000];
	struct node * freehead=NULL;
	struct node * temp=NULL;
	struct node * temp1=NULL;
	printf("Enter the number of buffers\n");
	scanf("%d",&n);
	printf("Enter the number of elements\n");
	scanf("%d",&n2);
	printf("Enter the numbers\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&ele[i]);
	}
	for(i=0;i<n2;i++)
	{
	//	printf("Enter a number\n");
	//	scanf("%d",&x);
		ins(&arr[ele[i]%n],ele[i]);
	}
	printf("Headers\t\tnodes\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",i);
		display(&arr[i]);
	}
	printf("Enter the no. elements in freelist\n");
	scanf("%d",&n3);
	printf("Enter the elements\n");
	for(i=0;i<n3;i++)
	{
		scanf("%d",&x);
		if(freehead==NULL)
		{
			freehead=(struct node*)malloc(sizeof(struct node));
			freehead->next=NULL;
			freehead->prev=NULL;
			freehead->data=x;
			temp1=freehead;
		}
		else{
			while(freehead->next !=NULL)
			{
				freehead=freehead->next;
			}
			if(freehead->next==NULL)
			{
				struct node * newnode=(struct node*)malloc(sizeof(struct node));
				freehead->next=newnode;
				newnode->data=x;
				newnode->prev=freehead;
				newnode->next=NULL;
			}
		}
	}
	printf("Freelist:\n");
	//freehead=temp1;
	printf("Freehead %d\n",freehead->data);
	//display(freehead);
	printf("Enter the number to enter into the buffer\n");
	scanf("%d",&x);
	int flag=0;
	for(i=0;i<n2;i++)
	{
		if(ele[i]==x)
			printf("Element found in hash queue and is busy.\nGoing to sleep\n");
	}
	//if(flag==0)
		//printf("Element not found in hash queue\n");
	sleep(5);
	
	temp=&(arr[x%n]);
	ins(freehead,x);
	printf("Updated freelist:\n");
	display(temp1);
	//temp->prev=NULL;
	//printf("%d temp",temp->data);
	//arr[0]=*temp;
	//freehead->next=NULL;
	/*
	if(temp->next!=NULL)
	{
		temp=temp->next;
		//temp=temp->next;
		temp->prev=NULL;
	}
	else
	{
		temp=temp->prev;
		temp->next=NULL;
	}*/
	//printf("%d added to freelist and removed from hash queue\n",temp->data);
	//freehead=NULL;
	ins(&arr[x%n],x);
	//printf("Free list emptied and new element added to hash queue\n");
	printf("Headers\t\tnodes\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",i);
		display(&arr[i]);
	}
	return 0;
}
