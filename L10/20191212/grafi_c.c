#include <stdlib.h>
#include <stdio.h>

struct list{
    int key;
    struct list *next;
};
typedef struct list* List;

struct graph_m{
    int V,E;
    int **A;
};
typedef struct graph_m *Graph_m;

struct graph_l{
    int V,E;
    List *L;
};
typedef struct graph_l *Graph_l;

struct queue{
    List head, rear;
};
typedef struct queue *Queue;

struct stack{
    List S;
};
typedef struct stack *Stack;

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

Stack createStack(void);
int top(Stack);
int pop(Stack);
void push(Stack,int);
void stackDestroy(Stack);
int stackIsEmpty(Stack);

Graph_l graphNew_l(int);
void graphDestroy_l(Graph_l);
void graphEdgeInsert_l(Graph_l,int,int);
Graph_l graphRead_l(void);
void graphPrint_l(Graph_l);
void DFS_l(Graph_l);
void BFS_l(Graph_l);

int main(void){

/*    Graph_m g = graphRead_m();
    graphPrint_m(g);
    DFS_m(g);
    BFS_m(g);
*/
    Graph_l g = graphRead_l();
    graphPrint_l(g);
    DFS_l(g);
    BFS_l(g);

    return 0;
}

void BFS_l(Graph_l g){
    printf("BFS_l\n");

    Queue q = createQueue();
    int n = g->V;

    int *aux = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) aux[i]=0;

    enqueue(q,0);

    while(!isEmpty(q)){
        int x = dequeue(q);
        if(aux[x]==0){
            aux[x]=1;
            printf("%d ",x);
        }

        for(List curr = g->L[x];curr!=NULL;curr = curr->next){
            if(aux[curr->key]==0){
                printf("%d ",curr->key);
                enqueue(q,curr->key);
                aux[curr->key]=1;
            }
        }
    }
    printf("\n");
}

int stackIsEmpty(Stack s){
    return !(s->S)?1:0;
}

void stackDestroy(Stack s){
    for(List curr = s->S;curr!=NULL;curr = curr->next){
        free(curr);
    }
    free(s->S);
    free(s);
}

void push(Stack s,int key){
    s->S = listInsert(s->S,key);
}

int pop(Stack s){
    int key = s->S->key;
    s->S = s->S->next;
    return key;
}

Stack createStack(void){
    Stack s = malloc(sizeof(Stack));
    s->S = NULL;
    return s;
}

int top(Stack s){
    return s->S->key;
}

void DFS_l(Graph_l g){
    int n = g->V;
    int *aux = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) aux[i]=0;

    Stack s = createStack();
    push(s,0);
    printf("%d\n",0);

    while(!stackIsEmpty(s)){
        int x = pop(s);
        printf("%d ",x);
        aux[x]=1;

        for(List curr = g->L[x];curr!=NULL;curr = curr->next){
            if(aux[curr->key]==0) push(s,curr->key);
        }
    }

}

void graphPrint_l(Graph_l g){
    for(int i=0;i<g->V;i++){
        printf("%d :",i);
        for(List curr = g->L[i];curr!=NULL;curr = curr->next){
            printf("%d ",curr->key);
        }
        printf("\n");
    }
}

Graph_l graphRead_l(){
    Graph_l g = NULL;
    int n=0,e=0,u=0,v=0;

    printf("Inserisci #nodi: ");
    scanf("%d",&n);

    g = graphNew_l(n);

    printf("Inserisci #archi: ");
    scanf("%d",&e);

    printf("Inserisci archi %d:\n",e);

    for(int i=0;i<e;i++){
        scanf("%d %d",&u,&v);
        //printf("Read: %d %d\n",u,v);
        graphEdgeInsert_l(g,u,v);
    }

    return g;
}

void graphEdgeInsert_l(Graph_l g,int u,int v){
    //printf("Inserting: %d %d\n",u,v);
    List curr = NULL;
    for(curr = g->L[u];curr!=NULL;curr = curr->next){
        if(curr->key==v) return;
    }
    curr = NULL;
    for(curr = g->L[v];curr!=NULL;curr = curr->next){
        if(curr->key==u) return;
    }

    g->L[u] = listInsert(g->L[u],v);
    g->L[v] = listInsert(g->L[v],u);



    g->E++;

    //printf("Inserted: %d %d\n",u,v);

}

void graphDestroy_l(Graph_l g){
    for(int i=0;i<g->V;i++){
        for(List curr = g->L[i];curr != NULL;curr = curr->next){
            free(curr);
        }
    }
    free(g->L);
    free(g);
    printf("Deleted all!\n");
}

Graph_l graphNew_l(int n){
    Graph_l g = malloc(sizeof(Graph_l));
    g->V = n;
    g->L = calloc(n,sizeof(List));
    g->E = 0;
    printf("Graph List created!\n");
    return g;
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
    l->next = lo;

    return l;
}

int dequeue(Queue q){
    if(isEmpty(q)) return -1;

    List tmp = q->head;

    int x = q->head->key;
    q->head = q->head->next;

    if(!q->head) q->rear = NULL;

    if(!tmp) free(tmp);
    return x;
}

void enqueue(Queue q,int x){
    List l = malloc(sizeof(List));
    l->key = x;
    l->next = NULL;

    if(isEmpty(q)){
        //printf("è vuoto\n");
        q->head = l;
        q->rear = l;
        return;
    }

    q->rear->next = l;
    q->rear = l;

    return;
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
    g->E++;
    return;
}

Graph_m graphRead_m(void){
    Graph_m g = NULL;
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
    for(int i=0;i<=v;i++){
        if(i>0) printf("%d ",i-1);
        else printf("  ");
    }
    printf("\n");
    for(int i=0;i<v;i++){
        printf("%d:",i);
        for(int j=0;j<v;j++){
            printf("%d ",g->A[i][j] ? 1:0);
        }
        printf("\n");
    }
    return;
}
