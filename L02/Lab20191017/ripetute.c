#include <stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  int i,check=0,arr[10]={0};
  //printf("%d",n);
  while(n>0){
    int temp=n%10;
      //printf("%d %d",temp,check);
      arr[temp]++;
      if(arr[temp]>1){
        check = 1;
      }
      n/=10;
  }
  if(check){
    printf("Cifre ripetute:");
    for(i=0;i<10;i++){
      if(arr[i]>1){
        printf("%d,",i);
      }
    }
    printf("\n");
  }else{
    printf("Non ci sono cifre ripetute\n");
  }

  return 0;

}
