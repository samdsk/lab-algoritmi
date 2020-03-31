#include <stdio.h>

int hanoi(int,int,int,int);

int main(void){
  int n;
  printf("Inserire N: ");
  scanf("%d",&n);
  printf("Numero di mosse: %d\n",hanoi(n,0,1,2));
  return 0;
}

int hanoi(int n,int from,int temp,int to){
    if(n==1){
      #ifdef DEBUG
      printf("%d -> %d\n",from,to);
      #endif
      return 1;
    }else{
      #ifdef DEBUG
      printf("%d -> %d\n",from,to);
      #endif
      return 1 + hanoi(n-1,from,to,temp) + hanoi(n-1,temp,from,to);
    }
}
