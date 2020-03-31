#include <stdio.h>
#include <math.h>


int main(){
    float a,b,c;
    printf("Inserisci a b c: ");
    scanf("%f %f %f",&a,&b,&c);
    float delta;

    delta = (b*b)-(4*(a*c));

    if (delta>=0){
        float x1 = (-b-sqrt(delta))/2;
        float x2 = (-b+sqrt(delta))/2;
        printf("Le soluzioni di %fx^2+%fx+%f sono:\n",a,b,c);
        printf(" x1 = %f, x2 = %f\n",x1,x2);
    }else if( delta<0){
        float r = -b/2;
        float x1i = -sqrt(fabs(delta));
        float x2i = sqrt(fabs(delta));
        printf("Le soluzioni di %fx^2+%fx+%f sono:\n",a,b,c);

        
        printf(" x1 = %f %fi, x2 = %f %fi\n",r,x1i,r,x2i);
    }

    
}