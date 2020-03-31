#include <stdio.h>

int main(void){
  float a,b,c;

  printf("Inserisci tre numeri separati da spazi:");
  scanf("%f %f %f",&a,&b,&c);


  if (a < b+c && b < a+c && c < a+b){
    if (a == b && a == c){
      print("Il triangolo e' equilatero\n");
    }else if (a==b || a==c || b==c){
      printf("Il triangolo e' isoscele\n");
    }else{
      printf("Il triangolo e' scaleno\n");
    }
  }else{
    printf("Non e' un triangolo\n");
  }


  return 0;
}
