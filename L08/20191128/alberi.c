#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bit_node.h"


int main(void){
  BitNode root;
  root = malloc(sizeof(struct bit_node));
  root->item = 78;
  root->l = malloc(sizeof(struct bit_node));
  root->r = malloc(sizeof(struct bit_node));
  root->l->item=54;
  root->r->item=21;
  root->l->l=NULL;
  root->l->r=malloc(sizeof(struct bit_node));
  root->l->r->item=90;
  root->l->r->l=malloc(sizeof(struct bit_node));
  root->l->r->l->item=19;
  root->l->r->l->l=NULL;
  root->l->r->l->r=NULL;
  root->l->r->r=malloc(sizeof(struct bit_node));
  root->l->r->r->item=95;
  root->l->r->r->l=NULL;
  root->l->r->r->r=NULL;

  root->r->l=malloc(sizeof(struct bit_node));
  root->r->l->item=16;
  root->r->l->l=malloc(sizeof(struct bit_node));
  root->r->l->l->item=5;
  root->r->l->l->l=NULL;
  root->r->l->l->r=NULL;
  root->r->l->r=NULL;
  root->r->r=malloc(sizeof(struct bit_node));
  root->r->r->item=19;
  root->r->r->l=malloc(sizeof(struct bit_node));
  root->r->r->l->item=56;
  root->r->r->l->l=NULL;
  root->r->r->l->r=NULL;
  root->r->r->r=malloc(sizeof(struct bit_node));
  root->r->r->r->item=43;
  root->r->r->r->l=NULL;
  root->r->r->r->r=NULL;

  Item a[10] = {69,89,28,39,66,44,12,2,71,50};

  BitNode p = bitArr2Tree(a,10,0);
  printSommario(p,0);
  //printSommario(root,0);
  return 0;
}
