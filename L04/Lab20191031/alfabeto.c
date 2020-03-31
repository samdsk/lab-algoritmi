#include <stdio.h>



int main(int args_n,char **args){
    
    if(args_n<2){
        printf("usage: ./farf <parola>\n");
        return 0;
    }

    char *word = args[1];
    while(*word!='\0'){
        switch(*word){
            case 'a':
                printf("afa");
                break;
            case 'e':
                printf("efe");
                break;
            case 'i':
                printf("ifi");
                break;
            case 'o':
                printf("ofo");
                break;
            case 'u':
                printf("ufu");
                break;
            default:
                printf("%c",*word);
                break;         
        }
        word++;
        
    }

    printf("\n");

    return 0;
}