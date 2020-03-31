#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
    char x,y;

    printf("Inserisci due lettere del alfabeto:");
    scanf("%c %c",&x,&y);
    
    int dis;
    dis = (int) fabs((float)tolower(x)-(float)tolower(y));
    printf("Distanza tra le due lettere è %d\n",dis+1);
}