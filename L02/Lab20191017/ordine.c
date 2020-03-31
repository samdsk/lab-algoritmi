#include<stdio.h>
#define N 100
int main(void){
  int n[N]={0},i=0,temp=1;

  scanf("%d",&n[0]);

  while(1){
    scanf("%d",&temp);
    if(temp == 0){
      break;
    }
    i++;
    if(n[i-1]<=temp){
      n[i] = temp;
    }else{
      int found = 0;

      for(int j=0;j<i;j++){
        if(n[j]>temp){
          found =j;
          break;
        }
      }
      int arrTemp[100]={0};
      for(int j=found;j<i;j++){
        arrTemp[j] = n[j];
      }
      n[found]=temp;
      for(int j=found;j<i;j++){
        n[j+1] = arrTemp[j];
      }
    }
  }

  for(int j=0;j<=i;j++){
    printf("%d ",n[j]);
  }
  printf("\n");
  return 0;
}
