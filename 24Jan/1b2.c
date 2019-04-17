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
	int i,n,x,z=1,lim;
	struct node arr[1000];
	int free[100];
//	struct node * freehead=(struct node*)malloc(sizeof(struct node));
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number of buffers\n");
	scanf("%d",&n);
	printf("Enter the no. of elements of free list\n");
	scanf("%d",&lim);
	printf("Enter the number\n");
	for(i=0;i<lim;i++)
	{
		scanf("%d",&free[i]);
	}
	while(z==1||z==2)
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
		printf("Enter 1 to continue or 2 to remove from free list\n");
		scanf("%d",&z);
		if(z==2)
		{
			int tmp,flag=0;
			struct node * temp1=(struct node*)malloc(sizeof(struct node));
			struct node * temp2=(struct node*)malloc(sizeof(struct node));
			printf("Enter the number to remove\n");
			scanf("%d",&tmp);
			for(i=0;i<lim;i++)
			{
				if(free[i]==tmp)
					flag=1;
			}
			//printf("%d",flag);
			if(flag==1)
			{
				int sto=tmp%n;
				temp1=&arr[sto];
				if(temp1->next==NULL)
				{
					if(temp1->data==tmp)
					{
						flag=2;
						break;
			printf("st%d\n",temp1->data);
					
					}
				}
				else
				{
					while(temp1->next!=NULL)
					{

						if(temp1->data==tmp){
							flag=2;
							break;
						}
										printf("saf%d\n",temp1->data);
						temp1=temp1->next;
					}
					if(temp1->data==tmp)
						flag=2;
				}
			}
			printf("flg%d",flag);
			if(flag==2)
			{
				for(i=0;i<lim;i++)
				{
					if(free[i]==tmp)
						free[i]=-1;
				}
				printf("Element found and removed.The new free list is\n");
				for(i=0;i<lim;i++)
				{
					if(free[i]!=-1)
						printf("%d",free[i]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
