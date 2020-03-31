#include <stdio.h>
#include <ctype.h>

int main(){
  char c;
  printf("Inserisci un carattere:");
  scanf("%c",&c);

  if (!isalpha(c)){
    printf("%c non e' una lettera dell'alfabeto italiano\n",c);
  }else{
    switch(tolower(c)){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        printf("%c e' una vocale dell'alfabeto italiano\n",c);
        break;
      case 'x':
      case 'y':
      case 'w':
      case 'k':
      case 'j':
        printf("%c non e' una lettera dell'alfabeto italiano\n",c);
        break;
      default:
        printf("%c e' una consonante dell'alfabeto italiano\n",c);
        break;
    }
  }


  return 0;
}
