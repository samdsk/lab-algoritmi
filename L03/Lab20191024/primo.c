#include <stdio.h>

int primo(int);

int main(){
    int n;
    printf("Inserisci N:");
    scanf("%d",&n);

    if(primo(n)){
        printf("E' un numero primo.\n");
    }else{
        printf("Non e' un numero primo.\n");
    }

    return 0;
}

int primo(int n){
  int i = 2;
  while(i<=n/2){
    if(n%i==0){
      return 0;
    }
    i++;
  }
  return 1;
}
