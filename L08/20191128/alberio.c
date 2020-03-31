#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bit_node.h"


int main(void){
  BitNode root = NULL;
  root = bitNew(30);
  bistInsert(&root,10);
  bistInsert(&root,70);
  bistInsert(&root,20);
  bistInsert(&root,50);
  bistInsert(&root,40);
  bistInsert(&root,60);

  printAsSummery(root,0);

  bistDelete(&root,30);

  printAsSummery(root,0);

  return 0;
}
