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
	int i,n,x,z=1,n2,ele[100];
	struct node arr[1000];
	struct node * freehead=NULL;
	struct node * temp=NULL;
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
	printf("Enter the number to enter into the buffer\n");
	scanf("%d",&x);
	int flag=0;
	for(i=0;i<n2;i++)
	{
		if(ele[i]==x)
			flag++;
	}
	if(flag==0)
		printf("Element not found in hash queue and no buffers on free list.Going to sleep\n");
	else
		return 0;
	sleep(5);
	freehead=(struct node*)malloc(sizeof(struct node));
	temp=&(arr[0]);
	freehead->data=temp->data;
	freehead->prev=NULL;
	freehead->next=NULL;
	temp=temp->next;
	int ze=temp->data;
	temp=temp->next;
	temp->prev=NULL;
	//printf("%d temp",temp->data);
	arr[0]=*temp;
	freehead->next=NULL;/*
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
	printf("%d added to freelist and removed from hash queue\n",z);
	freehead=NULL;
	ins(&arr[x%n],x);
	printf("Free list emptied and new element added to hash queue\n");
	printf("Headers\t\tnodes\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",i);
		display(&arr[i]);
	}
	return 0;
}
