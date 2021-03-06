#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>



struct Process{

    int priority;

    int cpu;

    int group;

};



struct Group{

    int n;

    int selected_process;

    struct Process P[10];

};



void init_Group(struct Group *g,int n){

    g->n = n;

    g->selected_process = 0;

}



void init_Process(struct Process *x,int priority,int group){

    x->cpu = 0;

    x->priority = priority;

    x->group = group;

}

void cal_cpu_time(struct Process *x,int base,int selected){

    if (selected==0){

        x->cpu = x->cpu/2;

    }else if(selected==1){

        x->cpu = (x->cpu + base)/2;

    }

}

void cal_group(struct Process *x,int base,int selected){

    if (selected==0){

        x->group = x->group/2;

    }else{

        x->group = (x->group + base)/2;

    }

}

void cal_priority(struct Process *x,int base){

    x->priority = base + (x->cpu/2) + (x->group/2);

}



void display(struct Group G[],int g){

    int i=0,j=0;

    for(i=0;i<g;i++){



        for(j=0;j<G[i].n;j++){

            printf("|%d\t\t%d\t%d|\t",G[i].P[j].priority,G[i].P[j].cpu,G[i].P[j].group);

        }



}



    printf("\n");

}



int main(){



    struct Group G[10];



    int selected_process=0,selected_group=0,g=0,n=0,t=0;

    int base=0,i,j,k,l1;



	printf("Enter Base Priority:");

    scanf("%d",&base);

    printf("Enter the no of Groups:");

    scanf("%d",&g);

	printf("\n");

    for(i=0;i<g;i++){

        printf("Enter the no of Processes in Group %d:",i+1);

        scanf("%d",&n);

        init_Group(&G[i],n);

        //process init()

        for(j=0;j<n;j++){

            init_Process(&G[i].P[j],base,i);

        }

    	printf("\n");

    }

    printf("Enter the number of timesteps:");

    scanf("%d",&t);



    for(i=0;i<g;i++){

        printf("\tGroup %d\t\t\t",i+1);

    }

    printf("\n\nTime\t");

    for(i=0;i<g;i++){

        for(j=0;j<G[i].n;j++)

            printf("\tProcess %d\t",i+j+1);

    }

	printf("\n\n ");

    for(i=0;i<n;i++){

        for(j=0;j<G[i].n;j++)

            printf("\tPriority  Cpu_Time  Group");

    }

	printf("\n\n");

    //iterate for t timesteps

    for(i = 0; i < t; i++)

    {

        printf("Time %d s: ",i);

	display(G,g);

        l1 = i % g;

        for(j=0;j<g;j++){



            if (j==l1){

                selected_group=1;

            }else{

                selected_group=0;

            }



            for(k=0;k<G[j].n;k++)

            {

                if (selected_group==1 && k==G[j].selected_process){

                    selected_process=1;

                }else{

                    selected_process=0;

                }

                cal_cpu_time(&G[j].P[k],base,selected_process);

                cal_group(&G[j].P[k],base,selected_group);

                cal_priority(&G[j].P[k],base);

            }



            if(selected_group==1){

                G[j].selected_process = (G[j].selected_process + 1) % G[j].n;

            }

        }

      //  display(G,g);

    }



}
