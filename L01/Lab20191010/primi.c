#include <stdio.h>

int main(){
    int n;
    printf("Inserisci N:");
    scanf("%d",&n);
    int count = 0;
    int i = n;

    while(i>0){
        if (n%i == 0){
            count++;
        }
        i--;
    }

/*
    for (int i = n;i>0;i--){
        if(n%i == 0){
            count++;
        }
    }
*/
    if(count==2){
        printf("E' un numero primo.\n");
    }else{
        printf("Non e' un numero primo.\n");
    }
    
}