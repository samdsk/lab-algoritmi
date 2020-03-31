struct list{
  int v;
  struct list *next;
};
typedef struct list* List;

struct graph_m{
  int v,e;
  int **a;
};
typedef struct graph_m* Graph_m;

struct graph_l{
  int v,e;
  List *a;
};
typedef struct graph_l* Graph_l;

struct queue{
  List b,f;
  int size;
};
typedef struct queue* Queue;

List listInsert(int v,List old);
void printList(List l);

Queue createQueue(void);
Queue enqueue(Queue old, int i);
int dequeue(Queue old);

Graph_m graphNew_m(int n);
void graphDestroy_m(Graph_m g);
void graphEdgeInsert_m(Graph_m g,int v,int w);
Graph_m graphRead_m(void);
void graphPrint_m(Graph_m g);
void DFS_m(Graph_m g);
void DFSu_m(Graph_m g, int i, int *aux);
void BFS_m(Graph_m g);
void BFSu_m(Graph_m g, int i, int *aux);

Graph_l graphNew_l(int n);
void graphDestroy_l(Graph_l g);
void graphEdgeInsert_l(Graph_l g,int v,int w);
Graph_l graphRead_l(void);
void graphPrint_l(Graph_l g);
void DFS_l(Graph_l g);
void DFSu_l(Graph_l g, int i, int *aux);
void BFS_l(Graph_l g);
void BFSu_l(Graph_l g, int i, int *aux);

List listInsert(int v, List old){
  List l = malloc(sizeof(struct list));
  l->v = v;
  l->next = old;

  return l;
}
void printList(List l){
  while(l != NULL){
    printf("%d ",l->v);
    l=l->next;
  }
  printf("\n");
}
Queue createQueue(void){
  Queue q = malloc(sizeof(struct queue));
  q->b = NULL;
  q->f = NULL;
  q->size = 0;
  return q;
}
Queue enqueue(Queue old, int i){
  List l = listInsert(i,NULL);

  if(old->size == 0){
    old->f = old->b = l;
  }else{
    old->f->next = l;
    old->f = l;
  }

  old->size++;
  return old;
}
int dequeue(Queue old){
  List l = NULL;
  if(old->size==0){
    return -1;
  }
  l = old->b;
  old->b = old->b->next;
  old->size--;
  return l->v;
}

Graph_l graphNew_l(int v){
  Graph_l = malloc(sizeof(struct graph_l));
  g->v = v;
  g->e = 0;
  g->a = calloc(v,sizeof(List));
  return g;
}
void graphDestroy(Graph_l g){
  free(g->a);
  free(g);
}
void graphEdgeInsert_l(Graph_l g, int v, int w){
  List l = NULL;
  for(l = g->a[v];l!=NULL;l->next){
    if(q->v == w){
      return;
    }
  }

  if(!g->a[v])
    g->a[v]=listInsert(v,g->a[v]);

  if(!g->a[w])
    g->a[w]=listInsert(w,g->a[w]);

  g->e++;

  if(v!=w){
    g->a[v]= listInsert(w,g->a[v]);
    g->a[w]= listInsert(v,g->a[w]);
  }
}
Graph_l graphRead_l(void){
  int v=0,e=0,a=0,b=0;
  Graph_l g;

  printf("Inserire numero di vertici: ");
  scanf("%d",&v);

  g = graphNew_l(v);

  printf("Inserire numero di archi: ");
  scanf("%d",&e);

  g->e = e;

  while(e>0){
    printf("Inserire due vertici di cui vuoi aggiungere arco: ");
    if(2 != scanf("%d %d",&a,&b)){
      printf("Errore: devi inserire due vertici.\n");
      break;
    }else if(a>v || b>v){
      printf("Errore: grafo non contiene questi vertici.\n");
      continue;
    }else if(a!=b){
      printf("Inserting...\n");
      e--;
      graphEdgeInsert_l(g,a,b);
    }else{
      printf("Errore: Input non valido.\n");
      break;
    }
  }
  return g


}
void graphPrint_l(Graph_l g){
  List l;
  for(int i=0;i<g->v;i++){
    printf("%d: ",i);
    for(l=g->a[i];l;l=l->next){
      printf("%d ",l->v);
    }
    printf("\n");
  }
}
void DFS_l(Graph_l g){
  int i,*aux=calloc(g->v,sizeof(int));

  for(i=0;i<g->v;i++){
    if(!aux[i]){
      printf("\n%d ",i+1);
      DFSu_l(g,i,aux);
    }
  }

  free(aux);
}
void DFSu_l(Graph_l g,int i,int *aux){
  List l;
  aux[i]=1;
  for(l=g->a[i];l;l=l->next){
    printf("%d ",l->v);
    DFSu_l(g,l->v-1,aux);
  }
}
void BFS_l(Graph_l g){
  int i,*aux=calloc(g->v,sizeof(int));
  for(i=0;i<g->v;i++){
    if(!aux[i]){
      printf("\n%d",i+1);
      BFSu_l(g,i,aux);
    }
  }
}
void BFSu_l(Graph_l g, int i, int* aux){
  List l;
  Queue q = createQueue();

  enqueue(q,i);
  while(q->size){
    i = dequeue(q);
    aux[i]=1;
    for(l=g->a[i];l;l=l->next){
      if(!aux[l->v-1]){
        enqueue(q,l->v-1);
        printf("%d ",l->v);
        aux[l->v-1]=1;
      }
    }
  }
}

Graph_m graphNew_m(int n){
  int i;
  Graph_m g;
  g = malloc(sizeof(struct graph_m));
  g->a = calloc(n, sizeof(int*));

  for(i=0;i<n;i++){
    g->a[i] = calloc(n,sizeof(int));
  }

  g->v = n;
  g->e = n*n;
  return g;
}
void graphDestroy_m(Graph_m g){
  for(int i=0;i<g->v;i++){
    free(g->a[i]);
  }
  free(g);
}
void graphEdgeInsert_m(Graph_m g,int v,int w){
  g->a[v][w]=1;
  g->a[w][v]=1;
}
Graph_m graphRead_m(void){
  int v=0,e=0,a=0,b=0;
  Graph_m g;

  printf("Inserire numero di vertici: ");
  scanf("%d",&v);

  g = graphNew_m(v);

  printf("Inserire numero di archi: ");
  scanf("%d",&e);

  g->e = e;

  while(e>0){
    printf("Inserire due vertici di cui vuoi aggiungere arco: ");
    if(2 != scanf("%d %d",&a,&b)){
      printf("Errore: devi inserire due vertici.\n");
      break;
    }else if(a>v || b>v){
      printf("Errore: grafo non contiene questi vertici.\n");
      continue;
    }else if(a!=b){
      printf("Inserting...\n");
      e--;
      graphEdgeInsert_m(g,a,b);
    }else{
      printf("Errore: Input non valido.\n");
      break;
    }
  }
  return g
}
void graphPrint_m(Graph_m g){
  for(int i=0;i<g->v;i++){
    for(int j=0;j<g->v;j++){
      printf("%d ",g->a[i][j]);
    }
    printf("\n");
  }
}
void DFS_m(Graph_m g){
  int i, *aux = calloc(g->v,sizeof(int));

  for(i=0;i<g->v;i++){
    aux[i]=0;
  }
  for(i=0;i<g->v;i++){
    if(!aux[i]){
      DFSu_m(g,i,aux);
    }
  }

  free(aux);
}
void DFSu_m(Graph_m g, int i, int *aux){

  for(int j=0;j<g->v;j++){
    if(g->a[i][j]){
      if(!aux[i]){
        printf("\n%d",i);
        aux[i]=1;
      }

      if(i!=j && !aux[j]){
        printf("\n%d",j);
        aux[j]=1;
        DFSu_m(g,j,aux);
      }
    }
  }

}
void BFS_m(Graph_m g){
  int i, *aux = calloc(g->v,sizeof(int));

  for(i=0;i<g->v;i++){
    aux[i]=0;
  }
  for(i=0;i<g->v;i++){
    if(!aux[i]){
      BFSu_m(g,i,aux);
    }
  }

  free(aux);
}
void BFSu_m(Graph_m g, int i, int *aux){
  Queue q = createQueue();
  aux[i] = 1;

  printf("\n%d",i);
  while(q->size){
    i = dequeue(q);
    for(int j=0;j<g->v;j++){
      if(!aux[j] && g->a[i][j]){
        aux[j]=1;
        enqueue(q,j);
        printf("\n%d",j);
      }
    }
  }

}
