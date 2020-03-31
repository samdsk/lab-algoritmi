#include <stdio.h>

void stampa(int[],int);
void mergeSort(int[],int,int);
void merge(int[],int,int,int);

int main(void){
  int n;
  printf("Inserisci dimensione dell'array: ");
  scanf("%d",&n);

  int a[n];
  printf("Inserisci %d numeri interi:",n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  mergeSort(a,0,n);
  stampa(a,n);
  return 0;
}

void mergeSort(int a[],int sx,int dx){
  if(dx-sx>1){
    #ifdef DEBUG
    printf("mergesort sx:%d dx:%d\n",sx,dx);
    #endif

    int m = (dx+sx)/2;

    mergeSort(a,sx,m);
    mergeSort(a,m,dx);
    merge(a,sx,m,dx);
  }
}

void merge(int x[],int sx,int m,int dx){
  int i1=0,i2=0,k=sx;
  #ifdef DEBUG
  printf("merge sx:%d m:%d dx:%d\n",sx,m,dx);
  #endif

  int n1 = m-sx;
  int n2 = dx-m;

  #ifdef DEBUG
  printf("n1:%d n2:%d\n",n1,n2);
  #endif

  #ifdef DEBUG
  printf("Riempio array b\n");
  #endif

  int b[n1];
  for(int i=0;i<n1;i++){
    #ifdef DEBUG
    printf("%d= <- %d \n",i,x[sx+i]);
    #endif

    b[i]=x[sx+i];
  }

  #ifdef DEBUG
  printf("Riempio array c\n");
  #endif

  int c[n2];
  for(int i=0;i<n2;i++){
    #ifdef DEBUG
    printf("%d= <- %d \n",i,x[m+i]);
    #endif
    c[i]=x[m+i];

  }

  while(i1<n1 && i2<n2){
    if(b[i1]<=c[i2]){
      #ifdef DEBUG
      printf("b:%d <= c:%d\n",b[i1],c[i2]);
      #endif

      x[k]=b[i1];
      i1++;
    }else{
      #ifdef DEBUG
      printf("b:%d > c:%d\n",b[i1],c[i2]);
      #endif

      x[k]=c[i2];
      i2++;
    }
    k++;
  }

  while(i1<n1){
    #ifdef DEBUG
    printf("i1<n1 %d\n",i1);
    #endif

    x[k]=b[i1];
    i1++;
    k++;
  }
  while(i2<n2){
    #ifdef DEBUG
    printf("i2<n2 %d\n",i2);
    #endif

    x[k]=c[i2];
    i2++;
    k++;
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
