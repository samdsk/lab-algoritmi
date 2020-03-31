#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int val;
};

typedef struct node *Node;

Node newNode( int val, Node p );
int f1 ( Node p );
Node f2 ( Node p );
Node f3 ( Node p, Node q );

int main(){
	Node x = newNode( 1, NULL );
	Node head = newNode( 2, x );
}


Node newNode( int val, Node p ){
	Node new = malloc( sizeof (struct node));
	new -> val = val;
	new -> next = p;
	return new;
}

int f1 ( Node p ){
	getchar();
	if ( p -> next == NULL )
		return 1;
	else
		if ( p -> val < p -> next -> val )
			return 0;
		else
			return f1( p -> next );
}

Node f2 ( Node p ){
	getchar();
	if (  p -> next == NULL ) 
		return p;
	else 
		return f3( p -> next, p );
}


Node f3 ( Node p, Node q ){
	Node temp;
	if ( p -> val < q -> val )
		temp = p;
	else
		temp = q;
	if ( p -> next == NULL )
		return temp;
	else 
		return f3( p -> next, temp );
	
}


