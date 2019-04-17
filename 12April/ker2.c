#include<stdio.h>
#include<stdlib.h>
struct Process
{
        int priority;
        int count;
        int v;
};
typedef struct Process process;
int base_p;
int cpu_count(int count)
{
        return(count-10);
}
int priority(int count)
{
        int p;
        p=base_p+(count/10);
        return p;
}
int main()
{
        int i,j,t,n,high,high_index;
        printf("\nEnter base Priority : ");
        scanf("%d",&base_p);

        printf("\nEnter number of Processes : ");
        scanf("%d",&n);
        process p[n];
        for(j=0;j<n;j++)
        {
                p[j].priority=base_p;
                p[j].count=0;
        }

        printf("\nEnter time : ");
        scanf("%d",&t);

        printf("--------------------------------------------------------------------------------\n\n");
        for(j=0;j<n;j++)
        {
                printf("           Process %d",j);
        }
        printf("\n");
        for(j=0;j<n;j++)
        {
                printf(" Priority   CPU count");
        }
        printf("\n");
        for(j=0;j<n;j++)
        {
                printf("    %d          %d    ",p[j].priority,p[j].count);
        }
        for(i=1;i<=t;i++)
        {
                high=p[0].priority;
                high_index=0;
 	     for(j=1;j<n;j++)
                {
                        if(p[j].priority<high)
                        {
                                high=p[j].priority;
                                high_index=j;
                        }
                        if(p[j].v!=1)
                        	p[j].v=0;
                }
                for(j=0;j<n;j++)
                {
                        if(j==high_index)
                        {
                                p[high_index].count=cpu_count(p[high_index].count+base_p);
                                p[high_index].priority=priority(p[high_index].count);
                                p[high_index].v=1;
                                //printf("%d v %d\n",high_index,p[high_index].v);
                        }
                        else 
                        {	if(p[j].v==1){
                        	//printf("Eh=%d\n",j);
                                p[j].count=cpu_count(p[j].count);
                                p[j].priority=priority(p[j].count);
                                }
   		  }
   		  
                }
                printf("\n");
                for(j=0;j<n;j++)
                {
                        printf("    %d          %d    ",p[j].priority,p[j].count);
                }
        }
        printf("\n\n");

}

