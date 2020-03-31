#include <stdio.h>
#include <stdlib.h>

int latoCristallo(int);
char** creaMatrice(int);
void stampaMatrice(char**,int);
void crist(char**,int,int,int);
void cristallo(char**,int);

int main(void){
  char** matrix;
  int t,lato;
  printf("Inserisci t:");
  scanf("%d",&t);
  if(t>=0){
    lato = latoCristallo(t);
    printf("lato: %d\n",lato);

    matrix = creaMatrice(lato);
    cristallo(matrix,lato);
    stampaMatrice(matrix,lato);
  }
  return 0;
}

int latoCristallo(int t){
  if(t==0){
    return 1;
  }else{
    return 1+2*latoCristallo(t-1);
  }
}

char** creaMatrice(int n){
  char** m;
  m = malloc(n*sizeof(char*));
  for(int i=0;i<n;i++){
    m[i] = malloc(n*sizeof(char*));
    for(int j=0;j<n;j++){
      m[i][j]='.';
    }
  }
  printf("Matrix created.\n");
  return m;
}

void stampaMatrice(char* m[],int n){
  printf("stampo...\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%c ",m[i][j]);
    }
    printf("\n");
  }
  return;
}

void crist(char** m, int r0,int c0,int l){
  if(l==1){
    m[r0][c0]='X';
    printf("l==1\n");
    return;
  }else{
    if((r0>l || c0>l)){
      return;
    }
    int rc = (l+r0)/2;
    int cc = (l+c0)/2;

    m[rc][cc]='X';
    for(int r=r0;r<r0+l;r++){
      for(int c=c0;c<c0+l;c++){
        crist(m,r,c,l/2);
      }
    }
    //crist(m,r0,c0,l/2);
    /*crist(m,r0,cc+1,l/2);
    crist(m,rc+1,c0,l/2);
    crist(m,rc+1,cc+1,l/2);
*/
    printf("Finished\n");
    return;

  }
}
/*
void copiaSottoMatrice(char** m,int l,int r0,int c0,int r1,int c1){

}
*/
void cristallo(char** m,int l){
  printf("Working...\n");


  crist(m,0,0,l);
  //crist(m,c,c,l);
  //crist(m,rc+1,c0,l/2);
  //crist(m,rc+1,cc+1,l/2);

  return;
}
