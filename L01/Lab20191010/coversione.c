#include <stdio.h>

int main(){
  int h,m;
  printf("Inserisci l'ora hh:mm ");
  scanf("%d:%d",&h,&m);
  int ora = h%12==0?12:h%12;
  if(h>11){
    printf("%d:%d PM\n",ora,m);
  }else{
    printf("%d:%d AM\n",ora,m);
  }

}
