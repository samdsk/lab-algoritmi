#include <stdio.h>

void hanoi(int,int,int,int);

int main(void){
  int n;
  printf("Inserire N: ");
  scanf("%d",&n);
  hanoi(n,0,1,2);
  return 0;
}

void hanoi(int n,int from,int temp,int to){
    if(n==1){
      printf("n=%d, %d -> %d\n",n,from,to);
    }else{
      hanoi(n-1,from,to,temp);
      printf("n=%d, %d -> %d\n",n,from,to);
      hanoi(n-1,temp,from,to);
    }
}
