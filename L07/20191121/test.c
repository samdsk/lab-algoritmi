#include <stdio.h>
#include "stack.h"

int main(void){
  push(1);
  push(2);
  push(3);

  print_stack();
  printf("%d\n",top());
  pop();
  print_stack();

  make_empty();
  print_stack();

  

  return 0;
}
