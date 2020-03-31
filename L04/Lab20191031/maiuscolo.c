#include <stdio.h>
#include <ctype.h>
#define N 100

char *maiuscolo(char *stringa){
  char *p=stringa;
  while(*p!='\0'){
    *p = toupper(*p);
    p++;
  }
  return stringa;
}

int main(void){
  char s[N];
  scanf("%s",s);
  char *stringa = maiuscolo(s);
  printf("%s\n",stringa);
  return 0;
}
