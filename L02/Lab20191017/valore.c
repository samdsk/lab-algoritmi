#include <stdio.h>

int main(void){
  int n=0,i=0,temp=0,err=-1;

  printf("Inserire numero di interi: \n");
  scanf("%d",&n);

  printf("Inserire %d interi: \n",n);

  while(i<n){
    scanf("%d",&temp);
    if(i!=temp){
      err = i;
    }
    i++;
  }

  if(err != -1){
    printf("%d\n",err);
  }
}

/*
int sq(int,int);

int main(void){
  int n;
  printf("Inserisci un numero intero: ");
  scanf("%d",&n);

  int i=0;
  int temp = sq(i,n);
  printf("%d\n",temp);

}

int sq(int i,int n){
  int temp;
  printf("Inserisci un intero: ");
  scanf("%d",&temp);
  if(i<n){
    if(i!=temp){
      return i;
    }else{
      return sq(++i,n);
    }
  }else{
    return -1;
  }
}
*/
