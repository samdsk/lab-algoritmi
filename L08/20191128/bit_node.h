#include <stdio.h>
#include "item.h"

#ifndef BITNODE_H
#define BITNODE

struct bit_node{
  Item item;
  struct bit_node *l,*r;
};

typedef struct bit_node *BitNode;

typedef int Key;

void printNode(BitNode);
void inorder(BitNode);
void preorder(BitNode);
void postorder(BitNode);
void printAsSummery(BitNode,int);
void printAsSummeryNode(BitNode,int);

BitNode bitArr2Tree(Item[],int,int);

BitNode bitNew(Item);
void bitDestroy(BitNode*);
Item bitItem(BitNode);
BitNode bitLeft(BitNode);
BitNode bitRight(BitNode);

Item bistMin(BitNode);
Item bistMax(BitNode);

void bistOrderPrint(BitNode);
void bistInvPrint(BitNode);

Item bistSearch(BitNode, Key);
void bistInsert(BitNode*,Item);

int bistDelete(BitNode*,Key);

#endif
