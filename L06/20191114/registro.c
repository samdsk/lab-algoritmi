#include <stdio.h>
#include <stdlib.h>

#define N 50

char** newBook(char**,int);
void book(char*[],int,int,char*);
void cancel(char**,int,int);
void move(char**,int,int,int);
void printBook(char**,int);

int main(void){
  char** registro=NULL;
  int n,k,f,t;
  char c, name[N];

  while((c=getchar())!='f'){
    switch(c){
      case 'b':
        scanf(" %d",&n);
        registro = newBook(registro,n);
        break;
      case '+':
        scanf(" %d",&k);
        scanf(" %s",name);
        book(registro,n,k,name);
        break;
      case '-':
        scanf(" %d",&k);
        cancel(registro,n,k);
        break;
      case 'm':
        scanf(" %d %d",&f,&t);
        move(registro,n,f,t);
        break;
      case 'p':
        printBook(registro,n);
        break;
    }
  }
  return 0;
}

void printBook(char *registro[],int n){
  for(int i=0;i<n;i++){
    printf("%d-->%s\n",i,registro[i]);
  }
  return;
}

void move(char** registro,int n,int from,int to){
  if((from>=n && from<0) || (to>=n && to<0)){
    printf("Error: from or to.\n");
    return;
  }else{
    if(registro[to]!=NULL){
      printf("Error: move to:%d Occupato!\n",to);
      return;
    }else{
      registro[to]=registro[from];
      registro[from]=NULL;
      printf("Ok: freed and set to null.\n");
      return;
    }
  }
}

void cancel(char** registro,int n,int k){
  if(k>=n && k<0){
    printf("Error: k:%d.\n",k);
    return;
  }else{
    if(registro[k] != NULL){
      registro[k]=NULL;
      printf("Ok: k:%d cancelled and freed!.\n",k);
      return;
    }else{
      printf("Warn: already null.\n");
      return;
    }
  }

}

void book(char* registro[],int n,int k, char* name){
  if(k>=n && k<0){
    printf("Error: k:%d.\n",k);
    return;
  }else{
    if(registro[k]!=NULL){
      printf("Error: Occupato!\n");
      return;
    }else{
      registro[k]=malloc(sizeof(name)*sizeof(char)+1);
      registro[k]=name;
      printf("Ok: %d = %s.\n",k,registro[k]);
      return;
    }
  }
}

char** newBook(char** registro,int n){
  free(registro);
  registro = malloc(n*sizeof(char));

  for(int i=0;i<n;i++){
    registro[i] = malloc(N*sizeof(char));
    registro[i] = NULL;
    printf("%s ",registro[i]);
  }
  printf("\nOk: creato un registro da %d\n",n);
  return registro;
}
