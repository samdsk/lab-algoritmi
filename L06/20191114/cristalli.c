#include<stdio.h>
#include<stdlib.h>

int latoCristallo(int);
char** creaMatrice(int);
void stampaMatrice(char**,int);
void crist(char**,int,int,int);
void copiaSottoMatrice(char**,int,int,int,int,int);
void cristallo(char**,int);

int main(void){
    char** m; //matrice m
    int t,l; //tempo t, lato l

    printf("Inserisci t:");
    scanf("%d",&t);

    if(t>=0){
        l = latoCristallo(t);
        printf("lato %d\n",l);
        m = creaMatrice(l);
        cristallo(m,l);
        stampaMatrice(m,l);
    }
    return 0;
}

void copiaSottoMatrice(char** m,int n,int r0,int c0,int r1,int c1){
    for(int i=r1;i<=r1+n;i++){
        int c = c0;
        //printf("r1: %d, c1: %d, r0: %d, c0: %d\n",r1,c1,r0,c0);
        for(int j=c1;j<=c1+n;j++){
            //printf("r1: %d, c1: %d, r0: %d, c0: %d\n",i,j,r0,c);
            m[i][j]=m[r0][c];
            c++;
        }
        r0++;
    }
}

void crist(char** m, int r0, int c0,int l){
    if(l==1){
        m[r0][c0]='X';
        return;
    }else{
        if(r0>l || c0>l){
            return;
        }
        int rc = (l+r0)/2;
        int cc = (l+c0)/2;

        m[rc][cc]='X';

        crist(m,r0,c0,l/2);
        crist(m,rc+1,c0,l/2);
        crist(m,r0,cc+1,l/2);
        crist(m,rc+1,cc+1,l/2);
    }
    return;
}

void cristallo(char** m,int l){
    crist(m,0,0,l);

    int r0=0,c0=0,r1=0,c1=0,i=2,offset=4;

    while(i<l/2){
        copiaSottoMatrice(m,i,r0,c0,r1,c1+offset);
        copiaSottoMatrice(m,i,r0,c0,r1+offset,c1);
        copiaSottoMatrice(m,i,r0,c0,r1+offset,c1+offset);
        i=(i+1)*2;
        offset*=2;
    }
    return;
}

void stampaMatrice(char** m,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           printf("%c ",m[i][j]);
        }
        printf("\n");
    }
    return;
}

char** creaMatrice(int n){
    char** m;
    m = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        m[i] = malloc(n*sizeof(char*));
        for(int j=0;j<n;j++){
            m[i][j]='.';
        }
    }
    return m;
}

int latoCristallo(int t){
    if(t==0){
        return 1;
    }else{
        return 1+2*latoCristallo(t-1);
    }
}
