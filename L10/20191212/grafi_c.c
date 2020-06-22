#include <stdlib.h>
#include <stdio.h>
struct list{
    struct list *next;
    int key;
};
typedef struct list* List;

struct graph_m{
    int V,E;
    int **A;
};
typedef struct graph_m *Graph_m;

struct graph_l{
    int V,E;
    List *A;
};
typedef struct graph_l *Graph_l;

struct queue{    
    List head, rear;
    List l;
};
typedef struct queue *Queue;

Graph_m graphNew_m(int);
void graphDestroy_m(Graph_m);
void graphEdgeInsert_m(Graph_m,int,int);
Graph_m graphRead_m(void);
void graphPrint_m(Graph_m);
void DFS_m(Graph_m);
void DFS2_m(Graph_m,int*,int);
void BFS_m(Graph_m);

List listInsert(List,int);

Queue createQueue();
int isEmpty(Queue);
void enqueue(Queue,int);
int dequeue(Queue);
void destroyQueue(Queue);


int main(void){

    Graph_m g = graphRead_m();
    DFS_m(g);
    BFS_m(g);
    
    graphDestroy_m(g);

    return 0;
}

void BFS_m(Graph_m g){
    printf("BFS_m\n");

    Queue q = createQueue();
    int n = g->V;
    int *aux = (int*)malloc(n*sizeof(int));    

    for(int i=0;i<n;i++){
        aux[i]=0;          
    }
    
    enqueue(q,0);

    while(!isEmpty(q)){
        
        int x = dequeue(q);        
        //printf("x = %d \n",x);
        if(aux[x]==0){
            aux[x]=1;
            printf("%d",x);
        }
        
        
        for(int i=0;i<n;i++){
            if(aux[i]==0){
                if(g->A[x][i]==1){
                    aux[i]=1;
                    printf("%d",i);
                    enqueue(q,i);
                }
                
            }
        }
    }

    printf("\n");

}

List listInsert(List lo,int key){
    List l = malloc(sizeof(List));
          
    l->key = key;
    l->next = NULL;
    if(!lo) return l;
    else lo->next = l;

    return lo;
}

int dequeue(Queue q){
    if(isEmpty(q)) return -1;

    List tmp = q->head;

    int x = q->head->key;
    q->head = q->head->next;

    if(!q->head) q->rear = NULL;

    //if(!tmp) free(tmp);
    return x;
}

void enqueue(Queue q,int x){
    if(isEmpty(q)){
        //printf("è vuoto\n");
        q->l = listInsert(NULL,x);
        q->head = q->l;
        q->rear = q->l;
    }else{
        //printf("non è vuoto\n");
        q->l = listInsert(q->l,x);
        q->rear = q->l; 
    }
       
}

int isEmpty(Queue q){    
    return (q->head == NULL && q->rear == NULL );
}

Queue createQueue(){
    Queue q = malloc(sizeof(Queue));   

    if(!q) printf("Error: malloc\n");

    q->head = q->rear = NULL; 
    printf("Queue created.\n");
    return q;
}

void DFS_m(Graph_m g){
    printf("DFS_m\n");
    int n = g->V;
    int *aux = malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        aux[i]=0;
    }
    for(int i=0;i<n;i++){    
        if(aux[i]==0){
            printf("%d",i);
            aux[i]=1;
        }    
        DFS2_m(g,aux,i);
    }
    printf("\n");
    free(aux);
}

void DFS2_m(Graph_m g,int *a,int pos){
    int n = g->V;

    for(int i=0;i<n;i++){
        if(g->A[pos][i]==1 && a[i]==0){
            printf("%d",i);
            a[i]=1;
            DFS2_m(g,a,i);
        }
    }
}

Graph_m graphNew_m(int n){
    int i;
    Graph_m g;
    g = malloc(sizeof(struct graph_m));
    g->A = calloc(n,sizeof(int*));

    for(i=0;i<n;i++){
        g->A[i] = calloc(n,sizeof(int));
    }
    g->V = n;
    return g;
}

void graphDestroy_m(Graph_m g){
    int n = g->V;    
    for(int i=0;i<n;i++){
        free(g->A[i]);    
    }

    free(g);    
    return;
}

void graphEdgeInsert_m(Graph_m g, int v, int w){
    g->A[v][w]=1;
    g->A[w][v]=1;
    return;
}

Graph_m graphRead_m(void){
    Graph_m g;
    int n=0,e=0,v=0,w=0;

    printf("Inserisci #nodi: ");
    scanf("%d",&n);

    g = graphNew_m(n);

    printf("Inserisci #archi: ");
    scanf("%d",&e);

    g->E = e;

    printf("Inserisci archi %d: ",e);
    for(int i=0;i<e;i++){        
        scanf("%d %d\n",&v,&w);
        graphEdgeInsert_m(g,v,w);
    }
    printf("\n");
    return g;
}

void graphPrint_m(Graph_m g){
    int v = g->V;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",g->A[i][j]);
        }
        printf("\n");
    }
    return;
}






