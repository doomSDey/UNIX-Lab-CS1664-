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
	int i,n,x,z=1;
	struct node arr[1000];
	printf("Enter the number of buffers\n");
	scanf("%d",&n);
	while(z==1)
	{
		printf("Enter a number\n");
		scanf("%d",&x);
		//for(i=1;i<=n;i++)
		//{
		//	if(x%n==0)
		//	{
				ins(&arr[x%n],x);
				//display(arr[i-1]);
			//	break;
			//}
		//}
		printf("Headers\t\tnodes\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t\t",i);
			display(&arr[i]);
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&z);
	}
	return 0;
}
