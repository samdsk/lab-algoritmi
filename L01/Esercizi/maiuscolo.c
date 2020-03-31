#include <stdio.h>
#include <ctype.h>

int main(void){
  char c;
  int k;

  printf("Inserisc chiave di cifratura:");
  scanf("%d",&k);


  while((c = getchar()) != '.'){
    if (isalpha(c)){
      if (c<=90){
        if (c+k >90){
          int temp = 90-c;

          putchar(64-temp+k);
        }else{
          putchar(c+k);
        }
        //ABCD...WXYZ
      }else{
        if (c+k >122){
          int temp = 122-c;
          putchar(96-temp+k);
        }else{
          putchar(c+k);
        }
      }

    }else{

      putchar(c);
    }
  }

  printf("\n");
  return 0;
}
