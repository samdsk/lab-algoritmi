#include <stdio.h>

int main(void){
  int a,b;

  printf("Inserisci due numeri interi:");
  scanf("%d%d",&a,&b);
  printf("Il massimo tra %d e %d e' %d.\n",a,b,a>b?a:b);
  return 0;
}
