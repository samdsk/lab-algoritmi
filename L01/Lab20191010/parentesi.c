#include <stdio.h>

int main(){
  char c;
  int count=0,pos=0,err=0;

  while((c = getchar())!= '.'){
    pos++;
    if(c == '('){
      count++;
    }else if(c==')'){
      count--;
    }
    if(count>0){
      err = pos;
    }
    if(count==-1){
      err = pos;
      break;
    }
  }

  if(count==0){
    printf("La string e' un'espressione ben parentesizzata\n");
  }else if(count>0 && pos == err){
    printf("La string non e' un'espressione ben parentesizzata\n");
    printf("Carattere %d: mancano parentesi chiuse alla fine!\n",err);
  }else if(count>0){
    printf("La string non e' un'espressione ben parentesizzata\n");
    printf("Carattere %d: troppe parentesi aperte!\n",err);
  }else if(count<0){
    printf("La string non e' un'espressione ben parentesizzata\n");
    printf("Carattere %d: troppe parentesi chiuse!\n",err);
  }

}
