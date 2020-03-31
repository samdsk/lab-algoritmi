#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node* Node;

Node list_insert( int n, Node l ){
  Node new = malloc(sizeof(Node));
  new -> info = n;
  new -> next = l;
  return new;
}

void list_delete( int n, struct node *l){
  struct node *curr, *prev;
  for ( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
    if (curr -> info == n ){
      printf("Trovato %d\n",curr->info);
      break;
    }
  }
  if (curr == NULL){
    return;
  } else if (prev == NULL){
    printf("l:%p l->next:%p\n",(void*)l,(void*)l->next);
    *l = *l -> next;
    return;
  }else{
    prev -> next = curr -> next;
    free(curr);
    return;
  }

}
void list_print(Node list){
  printf("List:\n");
  for ( Node curr = list; curr != NULL;curr = curr -> next ) {
    printf("%d\n",curr->info);
  }
  return;
}

void printListRec(Node list){
  if(list->next==NULL){
    printf("%d\n",list->info);
    return;
  }else{
    printListRec(list->next);
    printf("%d\n",list->info);
  }
}

int* listToArray(Node l){
  int *arr = malloc(sizeof(int));
  int i=0;
  while(l!=NULL){
    arr[i] = l->info;
    i++;
    if(l->next!=NULL){
      arr = realloc(arr,sizeof(int)*i+1);
    }
    l = l->next;
  }
  return arr;
}

void list_destroy(Node *l){
  if(*l==NULL){  
    free(*l);
    return;
  }else{
    *l = (*l)->next;
    list_destroy(l);
    free(*l);
  }
}


int main() {
  Node list = list_insert(5,NULL);
  list = list_insert(6,list);
  list = list_insert(3,list);
  list = list_insert(7,list);

  int *arr = listToArray(list);

  printListRec(list);

  list_destroy(&list);
  list_print(list);
  return 0;
}
