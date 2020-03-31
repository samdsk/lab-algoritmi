#include <stdio.h>
#define LENGHT 100

void scambia(int *p, int *q){
  int temp = *p;
  *p=*q;
  *q=temp;
}
int main(void){
  int p,q;
  printf("Inserire n e q: ");
  scanf("%d %d",&p,&q);
  printf("p:%d q:%d\n",p,q);
  scambia(&p,&q);
  printf("p:%d q:%d\n",p,q);
  return 0;
}
