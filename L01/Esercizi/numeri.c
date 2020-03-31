#include <stdio.h>

int main(void){
  int n,x,count=0;
  printf("Inserisci una serie di numeri:");

  do{
    if (count == 10){
      break;
    }
    scanf("%d",&n);
    x += n;
    count++;
  }while (n!=0);

  printf("%d\n",x);
  printf("la media: %d",x/count);
  return 0;
}
