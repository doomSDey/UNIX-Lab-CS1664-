#include<stdio.h>

struct ele{
  int value,age;
};

int main(){
  int s,n,i,seq[100],j=0,hit=0,temp,g=0;
  struct ele win[100];
  printf("Enter the frame size\n");
  scanf("%d",&s);
  printf("Enter the no. of elements\n");
  scanf("%d",&n);
  printf("Enter the sequence\n");
  for(i=0;i<n;i++){
    scanf("%d",&seq[i]);
  }
  while(j!=n){
    int flag=0;
    for(i=0;i<s;i++){
      if(win[i].value==seq[j])
      {
        //printf("win[i].value=%d\t",win[i].value);
        win[i].age=0;

        flag++;
        hit++;
      }
      else
        win[i].age++;
    }
    if(j<s){
        win[j].value=seq[j];
        for(i=0;i<=j;i++){
            if(i==j)
                win[i].age=0;
            else
                win[i].age++;
        }
       /* for(i=0;i<=j;i++)
        {
            if(j==s-1)
            printf("val=%d age=%d",win[i].value,win[i].age);
        }
        printf("\n");*/
    }
    else if(flag==0){
      for(i=0;i<s;i++){
        if(i==0){
          g=win[i].age;
          temp=i;
        }
        if(g<win[i].age)
        {  g=win[i].age;
           temp=i;
        }
      }
    win[temp].value=seq[j];
    win[temp].age=0;
      for(i=0;i<s;i++){
        if(i!=temp)
            win[i].age++;
      }
    }
    printf("%d\t\t",seq[j]);
    if(j<s)
    {
      for(i=0;i<=j;i++){
        printf("%d\t\t",win[i].value);
      }
    }
    else{
        for(i=0;i<s;i++){
          printf("%d\t\t",win[i].value);
        }
    }
    printf("\n");
    j++;
  }
  printf("\nPage hits=%d and Page faults=%d\n",hit,n-hit);
  return 0;
}
