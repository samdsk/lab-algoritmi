#include <stdio.h>

void stampa(int[],int);
void scambia(int[],int,int);
void selectionSort(int[],int);


int main(void){
  int n;
  printf("Inserisci dimensione dell'array: ");
  scanf("%d",&n);

  int a[n];
  printf("Inserisci %d numeri interi:",n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  selectionSort(a,n);
  stampa(a,n);
  return 0;
}

void selectionSort(int a[],int n){
  if(n==1){
    return;
  }else{
    int i=1;
    int max = *a;
    int pos = 0;

    while(i < n){
      if(a[i] > max){
        max = a[i];
        pos = i;
      }
      i++;
    }
    scambia(a,pos,n-1);
    selectionSort(a,n-1);
  }
}

void stampa(int a[],int l){
  int *i=a+l;
  printf("%d ",*a);
  while(++a<i){
    printf("%d ",*a);
  }
  printf("\n");
}

void scambia(int a[],int i,int j){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  
  #ifdef DEBUG
  printf("Scambiato %d con %d\n",a[i],a[j]);
  #endif
}
