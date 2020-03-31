#include <stdio.h>

int main(){
    int n;
    printf("Inserisci N:");
    scanf("%d",&n);

    int i=2;
    while(i<=n){
        if (n%i==0){
          n = n/i;
          printf("%d\n",i);
        }else{
            i++;
        }
    }
}
