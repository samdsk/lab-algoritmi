#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

typedef struct node* Node;

Node insert(int n,Node l){
  Node new = (Node)malloc(sizeof(Node));
  new->info = n;

  Node current = l;
  Node prev = NULL;

  if(current == NULL){
    printf("Creating a new list: %d.\n",n);
    new->next = NULL;
    return new;
  }

  while(current != NULL){
    if(current->info>n){
      printf("Adding: %d<%d ",n,current->info);
      new->next = current;
      if(prev!=NULL){
        printf("in the middle.\n");
        prev->next = new;
        return l;
      }else{
        printf("as first.\n");
        return new;
      }
    }
    prev = current;
    current = current->next;
  }

  printf("Adding as last: %d\n",n);
  prev->next=new;
  new->next=NULL;

  return l;      if(prev == NULL){
        return NULL;
      }
}

Node search(int n,Node l){
  Node current=l,prev=NULL;
  while(current != NULL){
    if(current->info==n){
      return current;
    }
    prev = current;
    current = current->next;
  }
  return NULL;
}


void print(Node list){
  printf("Printing...\n");
  for ( Node curr = list; curr != NULL;curr = curr -> next ) {
    printf("%d\n",curr->info);
  }
  return;
}

int main(void){

  Node ol = insert(5,NULL);
  ol = insert(3,ol);
  ol = insert(4,ol);
  ol = insert(7,ol);

  //print(ol);

  Node r = search(7,ol);
  printf("7:%d\n",r->info);

  r = search(6,ol);
  printf("6:%d\n",r==NULL?-1:r->info);

  r = search(5,ol);
  printf("5:%d\n",r->info);
  return 0;
}
