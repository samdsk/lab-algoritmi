#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node* Node;

void list_insert( int n, Node list ){
  Node new = malloc(sizeof(Node));
  new -> info = n;
  new -> next = list;
  list->next = new;

}

/*
Node list_insert( int n, Node l ){
  Node new = malloc(sizeof(Node));
  new -> info = n;
  new -> next = l;
  return new;
}

Node list_search( int n, Node l ){
  while ( l != NULL && l -> info != n )
    l = l -> next;
  return l;
}
*/

Node list_search( int n, Node l ){
  for(;;){
    if(l==NULL || l->info == n){
      break;
    }
    l = l->next;
  }
  return l;
}
Node listSearchRec(int n,Node l){
  if(l==NULL || l->info == n){
    return l;
  }
  return listSearchRec(n,l->next);
}

void destroy(Node *l){
  Node current = NULL;
  while(l!=NULL){
    current = *l;
    *l = *l->next;
    free(current);
  }
}
int main(void){

  Node list = malloc(sizeof(Node));
  list -> info = 5;
  list -> next = NULL;
  list_insert(2,list);
  list_insert(4,list);
  list_insert(7,list);

  Node key = list_search(7,list);

  printf("trovato: %d\n",key->info);

  return 0;
}
