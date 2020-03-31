#include <stdio.h>

int main(void){
  int n;

  printf("Inserire n: ");
  scanf("%d",&n);

  int arr[n];

  int temp,i=0,f=n,k=0;
  printf("Inserire la sequenza:\n");

  while(k<n){
    scanf("%d",&temp);
    if(temp>0){
      arr[f-1]=1;
      f--;
    }else{
      arr[i]=0;
      i++;
    }
    k++;
  }

  int j=0;
  while(j<n){
    printf("%d ",arr[j]);
    j++;
  }

  printf("\n");
  return 0;

}
