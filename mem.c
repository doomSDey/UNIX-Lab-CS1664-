#include<stdio.h>

struct map {
  int addr,size;
};

int tot,k,k2;

int main(){

  struct map m[1000],h[1000];
  k=0,k2=1;
  int chk,g,i,n;
  printf("Enter the total block size and the address\n");
  scanf("%d%d",&tot,&h[0].addr);
  h[0].size=tot;
  chk==tot;
  while(1){
    printf("1.Add 2.Remove 3.Display 4.Exit\n");
    scanf("%d",&n);
    if(n==4)
      break;
    else if(n==1){
      printf("Enter the size and the address\n");
      scanf("%d%d",&m[k].size,&m[k].addr);
      //scanf("%d",);
      if(g==0)
        g=m[k].addr;
      else if(m[k].addr>g)
        g=m[k].addr;
      if(m[k].size>tot)
        printf("Can't allocate\n");
      else{
        tot-=m[k].size;
        h[0].size-=m[k].size;
        k++;
      }
    }
    else if(n==2){
      printf("Enter the starting address to deallocate\n");
      int temp,flag=0;
      struct map temp1;
      scanf("%d",&temp);
      for(i=0;i<k;i++){
        if(temp==m[i].addr){
          temp1=m[i];
          m[i].addr=-1;
          printf("Success\n");
          flag=1;
        }
      }
      if(flag==0)
        printf("Not found\n");
      if(temp1.addr==g){
        h[0].size+=temp1.size;
        tot+=temp1.size;
        for(i=0;i<k;i++){
          if(i==0)
            g=m[i].addr;
          else
          {
            if(m[i].addr>g)
              g=m[i].addr;
          }
        }
      }
      else{
        h[k2].addr=temp1.addr;
        h[k2].size=temp1.size;
        tot+=temp1.size;
        k2++;
        //h[0].size+=temp.size;
      }
    }
    else if(n==3){
      if(tot==chk){
        printf("\nEmpty allocated.\n");
        printf("\nHoles\nAddr\t\tSize\n\n");
      }
      else{
        for(i=0;i<k2;i++){
          printf("%d\t\t%d\n",h[i].addr,h[i].size);
        }
        printf("\nallocated\nAddr\t\tSize\n\n");
        for(i=0;i<k;i++){
          if(m[i].addr!=-1)
            printf("%d\t\t%d\n",m[i].addr,m[i].size);
        }
        printf("Holes\nAddr\t\tSize\n\n");
        for(i=0;i<k2;i++){
          printf("%d\t\t%d\n",h[i].addr,h[i].size);
        }
      }
    }
  }
  return 0;
}
