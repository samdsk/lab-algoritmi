#include <stdio.h>
#include "item.h"

#ifndef BITNODE_H
#define BITNODE_H

struct bit_node{
  Item item;
  struct bit_node *l,*r;
};

typedef struct bit_node* BitNode;

typedef char* Key;

BitNode bitNew(Key);

void bistInsert(BitNode*,Key);

Item bistSearch(BitNode,Key);

void printOrder(BitNode);
void printInvOrder(BitNode);

void printNode(BitNode);
#endif
