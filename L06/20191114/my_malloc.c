#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t n){
  void *p;
  p = malloc(n);
  if (p == NULL){
    prtinf("Errore durante allocamento della memoria.\n");
    exit(EXIT_FAILURE);
  }
}

void *my_realloc(void *p,size_t n){
  p = realloc(p,n);
  if (p == NULL){
    prtinf("Errore durante allocamento della memoria.\n");
    exit(EXIT_FAILURE);
  }
}

int main(void){

  return 0;
}
