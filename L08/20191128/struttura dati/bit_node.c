#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "bit_node.h"

BitNode bitNew(Key k){
  BitNode p = malloc(sizeof(struct bit_node));
  p->item = malloc(sizeof(struct occorrenza));
  strcpy(p->item->word,k);
  p->item->n = 1;
  p->l = NULL;
  p->r = NULL;
  return p;
}

void bistInsert(BitNode *p,Key k){
  if(*p==NULL){
    printf("Inserting as new.\n");
    *p = bitNew(k);
    return;
  }
  if(strcmp(k,(*p)->item->word)==0){
    printf("Already exits ");
    ((*p)->item->n)++;
    printf("%d.\n",(*p)->item->n);
  }else if(strcmp(k,(*p)->item->word)<0){
    printf("Going left\n");
    bistInsert(&((*p)->l),k);
  }else{
    printf("Going right\n");
    bistInsert(&((*p)->r),k);
  }
}

Item bistSearch(BitNode root, Key k){
  printf("Calling search...\n");
  if(root == NULL){
    printf("Non ho trovato niente.\n");
    return NULL;
  }
  Item temp = malloc(sizeof(struct occorrenza));
  if (strcmp(root->item->word,k)==0){
    printf("Trovato: %s\n",k);
    temp = root->item;
    return temp;
  }

  if (strcmp(root->item->word,k)>0){
    return bistSearch(root->r, k);
  }
  return bistSearch(root->l, k);
}

void printOrder(BitNode p){
  //printf("Calling print....\n");
  if(p){
    printOrder(p->l);
    printNode(p);
    printOrder(p->r);

  }
  return;
}

void printInvOrder(BitNode p){
  //printf("Calling print....\n");
  if(p){
    printInvOrder(p->r);
    printNode(p);
    printInvOrder(p->l);

  }
  return;
}

void printNode(BitNode p){
  if(p){
    printf("Word:%s %d\n",p->item->word,p->item->n);
  }
  return;
}
