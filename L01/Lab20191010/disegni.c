#include <stdio.h>

int main(){
  int n,i,j;
  //char simbolo;

  scanf("%d",&n);

  /*for(i=0;i<n;i++){
    if(i%2){
      for(j=0;j<n;j++){
        simbolo = (j%2)?'o':'+';
        printf("%c ",simbolo);
      }
    }else{
      for(j=0;j<n;j++){
        simbolo = (j%2)?'+':'o';
        printf("%c ",simbolo);
      }
    }
    printf("\n");
  }*/

  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j){
        printf("|");
      }
      else if(j<i){
        printf("o");
      }else{
        printf("+");
      }
    }
    printf("\n");
  }*/

  for(i=0;i<n;i++){
    for(j=0;j<n+2;j++){
      if(j==n+1-i){
        printf("*");
      }else if(i==n-3 && (j==0)){
        printf("*");
      }else if(i==n-2 && (j==1)){
        printf("*");
      }else{
        printf(".");
      }
    }
    printf("\n");
  }
}
