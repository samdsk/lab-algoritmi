#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "bit_node.h"
#include <ctype.h>

char *readWord(void);

int main(void){
  char* w;
  BitNode root=NULL;

  while(1){
    w = readWord();

    if(w!=NULL){
      if(!(strcmp(w,"STOP"))){
        printf("Stop\n");
        break;
      }

      bistInsert(&root,w);
    }else{
      printf("Non alnum char\n");

    }


  }
  printf("\nOccorrenze di parole nel testo in ordine alfabetico:\n");
  printOrder(root);

  printf("\nOccorrenze di parole nel testo in ordine alfabetico inverso:\n");
  printInvOrder(root);

  printf("\nRicerca di parole:\n");

  while(1){
    w = readWord();

    if(w!=NULL){
      if(!(strcmp(w,"STOP"))){
        printf("Stop\n");
        break;
      }

      Item temp = bistSearch(root,w);

      if(temp!=NULL){
        printf("%s %d\n",temp->word,temp->n);
      }else{
        printf("%s:not found!",w);
      }
    }
  }

  return 0;
}

char *readWord(void){
  char c = getchar();
  char *parola;

  int n=1;
  parola = malloc(n*sizeof(char));

  if(!isalnum(c)){
    printf("First letter fault:%d\n",(int)c);
    return NULL;
  }

  *parola = c;

  while(1){
    c = getchar();
    if(!isalnum(c)){
      break;
    }
    parola[n]=c;
    n++;
    parola = realloc(parola,n*sizeof(char));
  }

  parola[n]='\0';
  printf("Inserted word: %s\n",parola);
  return parola;
}
