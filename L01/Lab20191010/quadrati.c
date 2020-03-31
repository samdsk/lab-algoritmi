#include <stdio.h>


#define FINO 10


int main(){
    printf("Quadrati perfetti fino %d\n",FINO);
    for (int i=1;i<FINO;i++){
        printf("%d\n",i*i);
    }
}