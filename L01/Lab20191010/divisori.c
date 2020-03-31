#include <stdio.h>

int main(){
    int n;
    printf("Inserisci N:");
    scanf("%d",&n);
    int count = 0;
    for (int i = n;i>0;i--){
        if(n%i == 0){
            printf("%d\n",i);
            count++;
        }
    }
    
    printf("Numero di divisori: %d\n",count);
}