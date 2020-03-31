#include <stdio.h>

int power(int,int);

int main(void){
  int b,e;
  printf("Inserire base ed esponente: ");
  scanf("%d %d",&b,&e);

  printf("%d\n",power(b,e));
  return 0;

}

int power(int b, int e){
  if(e==0){
    return 1;
  }else{
    return b*power(b,e-1);
  }
}
