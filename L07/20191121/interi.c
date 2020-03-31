#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node* Node;

Node insert(int,Node);
void delete(int,Node);
void print(Node);
void printInv(Node);
Node search(int,Node);
void destroy(Node*);

int main(void){
  Node head = NULL;

  char c;
  int n,count=0;

  while((c=getchar())!='f'){
    switch(c){
      case '+':
        scanf(" %d",&n);
        if(search(n,head)==NULL){
          head = insert(n,head);
          count++;
        }else{
          printf("%d already exists.\n",n);
        }
        break;
      case '-':
        scanf(" %d",&n);
        if(search(n,head)!=NULL){
          delete(n,head);
          count--;
        }else{
          printf("Didn't find %d.\n",n);
        }
        break;
      case '?':
        scanf(" %d",&n);
        if(search(n,head)==NULL){
          printf("%d non appartiene all'insieme.\n",n);
        }else{
          printf("%d appartiene all'insieme.\n",n);
        }
        break;
      case 'c':
        printf("#Elementi dell'insieme: %d\n",count);
        break;
      case 'p':
        print(head);
        break;
      case 'o':
        printInv(head);
        break;
      case 'd':
        destroy(&head);
        break;
    }
  }
  return 0;
}

Node insert(int n,Node l){
  Node new = malloc(sizeof(Node));
  new -> info = n;
  new -> next = l;
  return new;
}

void delete( int n, struct node *l){
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

void destroy(Node *l){
  if(*l==NULL){
    free(*l);
    return;
  }else{
    *l = (*l)->next;
    list_destroy(l);
    free(*l);
  }
}

void print(Node list){
  printf("Printing...\n");
  for ( Node curr = list; curr != NULL;curr = curr -> next ) {
    printf("%d\n",curr->info);
  }
  return;
}

void printInv(Node list){
  if(list->next==NULL){
    printf("%d\n",list->info);
    return;
  }else{
    printInv(list->next);
    printf("%d\n",list->info);
  }
}

Node search(int n,Node l){
  Node current=l;

  while(current != NULL){
    if(current->info==n){
      return current;
    }
    current = current->next;
  }

  return NULL;
}
