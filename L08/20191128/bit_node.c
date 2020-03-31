#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bit_node.h"

BitNode bitArr2Tree(Item a[],int n,int i){
  BitNode p = malloc(sizeof(struct bit_node));
  p->item=a[i];
  printf("%d--%d\n",p->item,i);
  if(i*2+1<n){
    p->l=bitArr2Tree(a,n,i*2+1);
    if(i*2+2<n){
      p->r=bitArr2Tree(a,n,i*2+2);
    }
  }
  return p;
}

void printNode(BitNode p){
  if(p){
    printf("%d\n",p->item);
  }
}

void inorder(BitNode p){
  if(p){
    inorder(p->l);
    printNode(p);
    inorder(p->r);
  }
}

void preorder(BitNode p){
  if(p){
    printNode(p);
    preorder(p->l);
    preorder(p->r);
  }
}

void postorder(BitNode p){
  if(p){
    postorder(p->l);
    postorder(p->r);
    printNode(p);
  }
}

void printAsSummery(BitNode p,int n){
  if(p){
    printAsSummeryNode(p,n);
    printAsSummery(p->l,n+1);
    printAsSummery(p->r,n+1);
    return;
  }
}

void printAsSummeryNode(BitNode p,int n){

  for(int i=0;i<n;i++){
    printf("-");
  }
  printf("*");
  if(p){
    printf("%d",p->item);
  }
  printf("\n");
}

BitNode bitNew(Item i){
  BitNode p = malloc(sizeof(struct bit_node));
  p->item = i;
  p->l = NULL;
  p->r = NULL;
  return p;
}

void bitDestroy(BitNode *p){
  if(*p == NULL){
    return;
  }

  bitDestroy(&((*p)->l));
  bitDestroy(&((*p)->r));
  printf("Deleteing:%d\n",(*p)->item);
  free(*p);

  *p=NULL;

  return;
}

Item bitItem(BitNode p){
  return p->item;
}

BitNode bitLeft(BitNode p){
  return p->l;
}

BitNode bitRight(BitNode p){
  return p->r;
}

Item bistMin(BitNode p){
  if(p->l==NULL){
    return p->item;
  }else{
    bistMin(p->l);
  }
}

Item bistMax(BitNode p){
  if(p->r==NULL){
    return p->item;
  }else{
    bistMax(p->r);
  }
}

Item bistSearch(BitNode root, Key k){
  if (root->item == k){
    Item i = root->item;
    return i;
  }
  if(root == NULL){
    return -1;
  }
  if (root->item < k){
    return bistSearch(root->r, k);
  }
  return bistSearch(root->l, k);
}

void bistInsert(BitNode *p,Item i){
  if(*p==NULL){
    *p = bitNew(i);
    return;
  }

  if(i<(*p)->item){
    bistInsert(&((*p)->l),i);
  }else if(i>(*p)->item){
    bistInsert(&((*p)->r),i);
  }
}

int bistDelete(BitNode* p,Key k){
  if(*p == NULL){
    return 0;
  }

  if(k<(*p)->item){
    return bistDelete(&((*p)->l),k);
  }else if(k>(*p)->item){
    return bistDelete(&((*p)->r),k);
  }else{
    printf("Found: %d\n",(*p)->item);
    if((*p)->l==NULL && (*p)->r==NULL){
      printf("Left and Right are NULL\n");
      free(*p);
      *p = NULL;
      return 1;
    }else if((*p)->l==NULL){
      printf("Left is NULL\n");
      (*p)->item = (*p)->r->item;
      free(&((*p)->r));
      (*p)->r = NULL;
      return 1;
    }else if((*p)->r==NULL){
      printf("Right is NULL\n");
      (*p)->item = (*p)->l->item;
      free(&((*p)->l));
      (*p)->l = NULL;
      return 1;
    }
    printf("Found: %d with 2 children\n",(*p)->item);
    Item min = bistMin((*p)->r);
    (*p)->item = min;
    bistDelete(&((*p)->r),(Key)min);
    return 1;
  }


}
