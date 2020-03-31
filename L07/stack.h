#ifndef STACK_H
#define STACK_H

/* svuota la pila */
void make_empty( void );

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty( void );

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int top( void );

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int pop( void );

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( int n );

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( void );

#endif
