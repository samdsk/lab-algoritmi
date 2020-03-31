#include<stdio.h>
#include<ctype.h>
int main(){
        
   char parola1[20];
   char parola2[20];
   printf("Inserisci due parole da confrontare: ");
   scanf("%s %s",parola1,parola2);

   printf("%s,%s\n",parola1,parola2);

    //char c,letter;
    int arr1[26] = {0}; 
    int arr2[26] = {0};

    //int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<20;i++){ 
        if(isalpha(parola1[i])){            
            arr1[toupper(parola1[i])-65]++;
        }

        if(isalpha(parola2[i])){
            arr2[toupper(parola2[i])-65]++;
        }
    }

    for(int i=0;i<20;i++){
        if (arr1[i]!=arr2[i]){
            printf("Non e' un anagramma!.\n");
            return 0;
        }
    }
    
    printf("E' un anagramma!\n");
}