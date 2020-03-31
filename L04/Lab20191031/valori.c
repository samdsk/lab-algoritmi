#include <stdio.h>

void max_secondomax(int[],int,int*,int*);

int main(){
    int max=0, max2=0, n[6]={1,4,67,8,45,4};
    max_secondomax(n,6,&max,&max2);
    printf("max:%d max2:%d\n",max,max2);
}

void max_secondomax(int a[],int n, int *max,int *max2){
    int *l = a+n;
    *max = *a;
    *max2 = *a;
    while(++a<l){
        if(*a>*max){
            *max2 = *max;
            *max = *a;
        }else if(*a<*max && *a>*max2){
            *max2 = *a;
        }
    }
    return;   
}