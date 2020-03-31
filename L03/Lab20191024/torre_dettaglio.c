#include <stdio.h>

void hanoi(int,char[],char[],char[],int);
void stampa(char*,char*,char*,int);

int main(void){
  int n;
  printf("Inserire (n<=26) N: ");
  scanf("%d",&n);

  char alpha[26+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char from[n];
  char temp[n];
  char to[n];

  for(int i=0;i<n;i++){
    from[i]=alpha[n-i-1];
    to[i]='.';
    temp[i]='.';

  }

  hanoi(n-1,from,temp,to,n);

  return 0;
}

void hanoi(int n,char *from,char *temp,char *to,int l){

  if(n==0){
    to[n]=from[n];
    from[n]='-';
    printf("n=%d ",n);
    stampa(from,temp,to,l);
  }else{
    hanoi(n-1,from,to,temp,l);
    to[n]=from[n];
    from[n]='-';
    printf("n=%d ",n);
    stampa(from,to,temp,l);
    hanoi(n-1,temp,from,to,l);


  }

}

void stampa(char *from,char *temp,char *to,int l){

  for(int i=0;i<l;i++){
    printf("%c",from[i]);
  }
  printf(",");
  for(int i=0;i<l;i++){
    printf("%c",temp[i]);
  }
  printf(",");
  for(int i=0;i<l;i++){
    printf("%c",to[i]);
  }
  printf("\n");

}
