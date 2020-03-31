#include<stdio.h>

int main(){
  char parola[20];

  char c;
  int i=0, fine=0;

  while(i<20){
    c = getchar();

    if(c == '.'){
      parola[i]='\0';
      fine = i;
      break;
    }

    parola[i]=c;
    i++;
  }


  for(int j=0;j<fine;j++){
    if(parola[j]!=parola[fine-j-1]){
      printf("Non e' palindroma\n");
      return 0;
    }
  }

  printf("E' palindroma\n");
  return 0;
}
