#include <stdio.h>

int mese(int m){
  switch (m){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 2:
      return 28;
    default:
      return 30;
  }
}

int main(){
  int m,g;
  printf("Inserisci il numero del mese (1=gennaio,...,12=dicembre)");
  scanf("%d",&m);

  printf("Inserisci il numero del mese (1=lunedi,...,7=domenica)");
  scanf("%d",&g);

  printf("L\tM\tM\tG\tV\tS\tD\n");

  int diff = 7-g;
  for (int i=1;i<g;i++){
    printf("\t");
  }

  for(int i=1;i<=diff+1;i++){
    printf("%d\t",i);

  }

  int n = diff;
  int nm = mese(m);
  for(int i=1;i<=nm;i++){
    if(n>=nm){
      break;
    }
    if(i%7==1){
      printf("\n");
    }
    printf("%d\t",++n);
  }

  printf("\n");
}
