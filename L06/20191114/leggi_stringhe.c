#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *read_line(char c){
  char lett = getchar();
  int n=1;

  char *parola;
  parola = malloc(n*sizeof(char));
  *parola = lett;

  while((lett = getchar()) != c){
    parola[n]=lett;
    n++;
    parola = realloc(parola,n * sizeof(char));
  }

  parola[n]='\0';

  return parola;
}

char *read_word(void){
  char c = getchar();
  char *parola;

  int n=1;
  parola = malloc(n*sizeof(char));

  if(!isalnum(c)){
    return parola;
  }

  *parola = c;

  while(1){
    c = getchar();
    if(!isalnum(c)){
      return parola;
    }
    parola[n]=c;
    n++;
    parola = realloc(parola,n*sizeof(char));
  }

  parola[n]='\0';
  return parola;
}

int main(void){

  char *parola = read_word();

  printf("%s\n",parola);

  return 0;
}
