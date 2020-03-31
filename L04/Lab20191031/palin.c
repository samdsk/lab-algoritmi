#include <stdio.h>
#include <string.h>

int palin(int l,char *arr){
  if(l%2!=0){
    return 0;
  }

  char *f=arr+l-1;
  for(char *i=arr;i<=arr+l;i++){
    if(*i!=*f--){
      return 0;
    }
  }
  return 1;
}

int main(void){
  int l=0;
  char arr[50];

  for(;;){
    scanf("%s",arr);
    if((int)arr[0]=='0'){
      break;
    }
    l=(int)strlen(arr);
    if(palin(l,arr)){
      printf(" \"%s\" e' palindroma\n",arr);
    }else{
      printf(" \"%s\" non e' palindroma\n",arr);
    }

  }
  return 0;
}
