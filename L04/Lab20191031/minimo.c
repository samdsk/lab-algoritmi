#include <stdio.h>

int *smallest(int a[],int n){
  int *p = a;
  int *min = &a[0];
  for(p=a;p<a+n;p++){
    if(*min>*p){
      min = p;
    }
  }

  return min;
}

int main(void){
  int n = 10;
  int arr[10];

  for(int i=0;i<10;i++){
    scanf("%d ",&arr[i]);
  }

  printf("minimo: %d\n",*smallest(arr,n));
  return 0;

}
