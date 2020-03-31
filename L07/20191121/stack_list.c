#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *next;
};

typedef struct node* Node;

Node head = NULL;

void push(int n){
  Node new = malloc(sizeof(Node));
  new->info = n;
  new->next = head;
  head = new;
  return;
}

int is_empty(void){
  if(head==NULL){
    return 1;
  }
  return 0;
}

void make_empty(void){
  while(head!=NULL){
    free(head);
    head = (head)->next;
  }
  return;
}

int top(void){
  if(!is_empty()){
    return head->info;
  }
  printf("Error: stack is empty.\n");
  return -1;
}

int pop(void){
  if(!is_empty()){
    int r = head->info;
    head = head->next;
    return r;
  }else{
    printf("Error: Stack is empty.\n");
    return -1;
  }
}

void print_stack(void){
  Node temp = head;
  if(!is_empty()){
    while(temp!=NULL){
      printf("%d ",temp->info);
      temp=temp->next;
    }
    printf("\n");
  }
  return;
}
