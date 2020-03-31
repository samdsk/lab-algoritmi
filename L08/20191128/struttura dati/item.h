#ifndef ITEM_H
#define ITEM_H
#define WORD 20

struct occorrenza{
  char word[WORD];
  int n;
};


typedef struct occorrenza* Item;

#endif
