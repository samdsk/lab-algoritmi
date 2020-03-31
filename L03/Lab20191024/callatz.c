#include <stdio.h>

int collatz(int);

int main(void){
  int n;
  printf("Inserire N: ");
  scanf("%d",&n);

  int l = collatz(n);

  printf("\nLunghezza: %d\n",l);
  return 0;
}

int collatz(int n){
  printf("%d ",n);
  if(n==1){
    return 1;
  }else if(n%2==0){
    n/=2;
  }else{
    n*=3;
    n++;
  }
  return 1+collatz(n);
}
