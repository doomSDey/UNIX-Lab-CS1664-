#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};
/*
struct free
{
	int data;
	struct node * next;
	struct node * prev;
};
*/
/*
struct node GetNode(int x)
{
	struct node newnode=(struct node)malloc(sizeof(struct node));
	if(x%4==0||x%4==1||x%4=2)
	{
		newnode->data=x;
		newnode->prev=NULL;
		newnode->next=NULL;
	}
	else
	{
		printf("Error.Limit exceeded\n");
	}
	return newnode;
}

struct node *insert()
{
	struct node * newnode=GetNode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
}

void Display
{
	struct node * ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d-",ptr->data);
		ptr=ptr->next;
	}
}
*/

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
	int i,n,x,x1,z=1;
	struct node arr[1000];
	struct node * freehead=NULL;
	struct node * last=NULL;
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number of buffers\n");
	scanf("%d",&n);
	printf("Enter the no. of elements of free list\n");
	scanf("%d",&x);
	printf("Enter the number\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&x1);
	//	ins(&freehead,x1);
		if(freehead==NULL)
		{
			freehead=(struct node*)malloc(sizeof(struct node));
			freehead->data=x1;
		//	printf("Free %d",freehead->data);
			freehead->next=NULL;
			freehead->prev=NULL;
			last=freehead;
		}
		else
		{

			while(freehead->next !=NULL)
			{
				freehead=freehead->next;
			}
			if(freehead->next==NULL)
			{
				struct node * newnode=(struct node*)malloc(sizeof(struct node));
				freehead->next=newnode;
				newnode->data=x1;
				newnode->prev=freehead;
				newnode->next=NULL;
			}
			/*	scanf("%d",&temp->data);
				temp->next=NULL;
				temp->prev=last;
				last->next=temp;
				last=temp;*/
		}
		//freehead->next=NULL;
		//printf("%d",last->data);
		//last->next=NULL;
	}
	freehead=last;
//	last->next=NULL;
	display(freehead);
	while(z==1||z==2)
	{
		int k=1;
		while(k==1){
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
		printf("k=0 to exit\n");
		scanf("%d",&k);
		}
		z=2;
	//	printf("Enter a \n");
	//	scanf("%d",&z);
		if(z==2)
		{
			int tmp,flag=0;
			struct node * temp1=(struct node*)malloc(sizeof(struct node));
			struct node * temp2=(struct node*)malloc(sizeof(struct node));
			printf("Enter the number \n");
			scanf("%d",&tmp);
			temp=freehead;
			while(temp->next!=NULL)
			{
				if(temp->data==tmp)
				{
					flag=1;
					temp2=temp;
					break;
				}
				temp=temp->next;
			}
			if(flag==1)
			{
				temp=&arr[tmp%n];
				while(temp->next!=NULL)
				{
				//	printf("tempdata %d",temp->data);
					if(temp->data==tmp)
					{
						flag=2;
						break;
					}
					temp=temp->next;
				}
			}
			if(temp->data==tmp)
				flag=2;
			printf("flg=%d\n",flag);
			if(flag==0)
			{
				freehead=freehead->next;
				freehead->prev=NULL;
				ins(&arr[tmp%n],tmp);
			}
			/*while(temp->next!=NULL)
			{
				if(temp->data=tmp)
				{
					temp2=temp;
					if(temp2->next==NULL)
					{
						temp2=temp2->prev;
						temp2->next=NULL;
						break;
					}
				else
					{
						temp1=temp2->next;
						temp1->prev=temp2->prev;
						temp2=temp2->prev;
						temp2->next=temp1;
						printf("Element removed.The current free list is\n");
						break;
					}
				}
				temp=temp->next;
			}*/
			display(freehead);
		}
	}
	return 0;
}
