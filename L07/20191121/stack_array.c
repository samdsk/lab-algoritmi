#include <stdio.h>

#define N 10

int stack[N];
int t=-1;

void make_empty(void){
  t = -1;
  return;
}

int is_empty(void){
  if (t==-1){
    return 1;
  }
  return 0;
}

int top(void){
  return stack[t];
}

int pop(void){
  if(!is_empty()){
    int r = stack[t];
    t--;
    return r;
  }else{
    printf("Error: Stack is empty.\n");
    return 0;
  }
}

void push(int n){
  if(t<N){
    t++;
    stack[t] = n;
    return;
  }else{
    printf("Error: Stack is full.\n");
    return;
  }
}

void print_stack(void){
  if(!is_empty()){
    for(int i=t;i>=0;i--){
      printf("%d ",stack[i]);
    }
    printf("\n");
  }

  return;
}
