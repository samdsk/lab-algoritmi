#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void){
  char token[10];
  scanf("%s",token);
  int cursor = 0,a,b;
  int l = strlen(token);
  printf("%d items read.\n",l);
  while(cursor<l){
    switch(token[cursor]){
      case '+':
        a = pop();
        b = pop();
        push(a+b);
        cursor++;
        break;
      case '-':
        a = pop();
        b = pop();
        push(a-b);
        cursor++;
        break;
      case '*':
        a = pop();
        b = pop();
        push(a*b);
        cursor++;
        break;
      case '/':
        a = pop();
        b = pop();
        push(a/b);
        cursor++;
        break;
      default:
        push(token[cursor]-48);
        //printf("pushing %d\n",token[cursor]-48);
        cursor++;
        break;
    }
  }

  printf("Result: %d\n",top());

}
