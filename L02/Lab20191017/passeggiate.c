#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int next(char arr[][N], char lettere[],int i,int *j,int *k,int check[4]){
  int d = rand();
  d %= 4;

  #ifdef DEBUG
  printf("d:%d j:%d k:%d i:%d\n",d,*j,*k,i);
  #endif

  if(d==0 && *k+1<10 && *k!=9 ){
    if(arr[*j][*k+1]=='.' ){
      arr[*j][*k+1]=lettere[i];
      *k=*k+1;
      check[0]=0;
      return 1;
    }else{
      check[0]=1;
      return 0;
    }
  }else if(d==1 && *j+1<10 && *j!=9){
    if(arr[*j+1][*k]=='.'){
      arr[*j+1][*k]=lettere[i];
      *j=*j+1;
      check[1]=0;
      return 1;
    }else{
      check[1]=1;
      return 0;
    }
  }else if(d==2 && *k-1>=0 && *k!=0){
    if(arr[*j][*k-1]=='.'){
      arr[*j][*k-1]=lettere[i];
      *k=*k-1;
      check[2]=0;
      return 1;
    }else{
      check[2]=1;
      return 0;
    }
  }else if(d==3 && *j-1>=0 && *j!=0){
    if(arr[*j-1][*k]=='.'){
      arr[*j-1][*k]=lettere[i];
      *j=*j-1;
      check[3]=0;
      return 1;
    }else{
      check[3]=1  ;
      return 0;
    }
  }else{
    check[0]=1;
    check[1]=1;
    check[2]=1;
    check[3]=1;
    return 0;
  }
}


int main(void){
  char arr[N][N]={
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'}
  };

  char lettere[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  srand(time(NULL));
  int j=0,k=0,i=0;
  /* j=righe k=colonne*/
  arr[j][k] = lettere[i];

  for(i=1;i<26;i++){
    if(j>9||k>9){
      break;
    }

    int check[4] = {0};
    while(!next(arr,lettere,i,&j,&k,check)){

      #ifdef DEBUG
      printf("riprovo\n");
      #endif

      int count = 0;
      for(int z=0;z<4;z++){
        if(check[z]==1){
          count++;
        }

        #ifdef DEBUG
        printf("errors: %d %d\n",z,check[z]);
        #endif
      }
      if(j>0 && j<9 && k>0 && k<9){
        if(count>3){
          break;
        }
      }else if(((k==0 || k==9) && j>0 && j<9) || ((j==0 || j==9) && k>0 && k<9)){
        if(count>2 ){
          break;
        }
      }else if(j==k){
        if(count>1){
          break;
        }
      }
    }
  }

  for(int k=0;k<10;k++){
    for(int l=0;l<10;l++){
      printf("%c  ",arr[k][l]);
    }
    printf("\n");
  }
  return 0;

}
