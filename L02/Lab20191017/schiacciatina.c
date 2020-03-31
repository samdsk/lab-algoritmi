#include <stdio.h>
#define DEBUG

int main(void){
  int r,c;

  printf("Inserire numero di righe e colonne:");
  scanf("%d %d",&r,&c);
  #ifdef DEBUG
  printf("righe:%d colonne:%d",r,c);
  #endif
  char matrice[r][c];
  int i,k;

  for(i=0;i<r;i++){
    for(k=0;k<c;k++){
      #ifdef DEBUG
      printf("i:%d k:%d\n",i,k);
      #endif
      char temp;
      scanf(" %c",&temp);
      matrice[i][k]=temp;
    }
  }

  int x,y,l=0;
  while(l<4){
    for(y=0;y<r-1;y++){
      for(x=0;x<c;x++){
        if(matrice[y][x]!='*' && matrice[y+1][x]=='*' ){
          #ifdef DEBUG
          printf("%c %c\n",matrice[y][x],matrice[y+1][x]);
          #endif
          matrice[y+1][x]=matrice[y][x];
          matrice[y][x]='*';
        }
        #ifdef DEBUG
        printf("else %c %c\n",matrice[y][x],matrice[y+1][x]);
        #endif
      }
    }
    l++;
  }

  for(int i=0;i<r;i++){
    for(int k=0;k<c;k++){
      printf("%c ",matrice[i][k]);
    }
    printf("\n");
  }
  return 0;
}
