#include<stdio.h>

int main(){
  int s,n,i,temp,seq[100],k=0,j=0,hit=0,arr[100];
  printf("Enter the frame size\n");
  scanf("%d",&s);
  printf("Enter the no. of elements\n");
  scanf("%d",&n);
  printf("Enter the sequence\n");
  for(i=0;i<n;i++){
    scanf("%d",&seq[i]);
  }
  printf("\nPage number\t\tTable\n");
  while(j!=n){
    int flag=0;
    for(i=0;i<s;i++){
      if(arr[i]==seq[j]){
        flag++;
        hit++;
      }
    }
    if(flag==0)
    {  arr[k%s]=seq[j];
       k++;
    }
    printf("%d\t\t",seq[j]);
    if(j<s){
      for(i=0;i<j;i++){
        printf("%d\t",arr[i]);
      }
      printf("\n");
    }
    else{
      for(i=0;i<s;i++){
        printf("%d\t",arr[(i+k)%s]);
       //  printf("K=%d and i=%d\t",k,i);
      }
      printf("\n");
    }
    j++;
  }
  printf("\nPage hits=%d and Page faults=%d\n",hit,n-hit);
  return 0;
}
