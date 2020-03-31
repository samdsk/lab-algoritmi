#include <stdio.h>
#include <ctype.h>

int main(){
    char c,letter;
    int arr[26] = {0}; 

    int len = sizeof(arr)/sizeof(arr[0]);

    while ((c = getchar()) !='.'){
        if(isalpha(c)){
            letter = toupper(c);
            arr[letter-65]++;
        }
    }

    for(int i=0;i<len;i++){
        if (arr[i]!=0){
            printf("%c ",i+65);
            for(int j = arr[i];j>0;j--){
                printf("*");
            }
            printf("\n");
        }        
    }
    
}