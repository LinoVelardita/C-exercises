#include <stdio.h>
#include <stdlib.h>

typedef struct _graph{
    int grado;
    int *adiacenti;
}graph;

typedef struct _coda{
    int capacity;
    int head;
    int tail;
    int *valori;
}coda;

void read_graph(graph** G, int n);
int BFS(graph* G, int n, int src);
void init(coda *q, int n);
void accoda(coda* q, int k);
int decoda(coda* q);
void deinit(coda* q);
int codavuota(coda* q);
int max_walk(graph* G, int n);

int main(){
    int n, i;
    scanf("%d", &n);
    graph* G = (graph*)malloc(sizeof(graph)*n);
    read_graph(&G, n);
    printf("%d\n", max_walk(G, n));
    return 0;
}

void read_graph(graph** G, int n){
    int i, j, g;
    for(i=0;i<n;i++){
        scanf("%d", &g);
        (*G)[i].grado=g;
        (*G)[i].adiacenti=(int*)malloc(sizeof(int)*g);
        for(j=0;j<g;j++){
            scanf("%d", (*G)[i].adiacenti+j);
        }
    }

}

int max_walk(graph* G, int n){
    int max, i, tmp;
    max=-1;
    for(i=0;i<n;i++){
        tmp=BFS(G, n, i);
        if(tmp==-1) return -1;
        if(tmp>max) max=tmp;
    }
    return max;
}

int BFS(graph* G, int n, int src){
    int i, u, v;
    int* colori=(int*)malloc(sizeof(int)*n);
    int* distance=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        colori[i]=0;
        distance[i]=-1;
    }
    coda q;
    init(&q, n);
    accoda(&q, src);
    colori[src]=1;
    distance[src]=0;
    while(!codavuota(&q)){
        u=decoda(&q);
        for(i=0;i<G[u].grado;i++){
            v=G[u].adiacenti[i];
            if(colori[v]==0){
                distance[v]=distance[u]+1;
                colori[v]=1;
                accoda(&q, v);
            }
        }
    }
    deinit(&q);
    for(i=0;i<n;i++){
        if(colori[i]==0) return -1;
    }
    return distance[u];
}

void init(coda *q, int n){
    q->capacity=n;
    q->head=0;
    q->tail=0;
    q->valori=malloc(sizeof(int)*q->capacity);
}

void accoda(coda* q, int k){
    q->valori[q->tail++]=k;
}

int decoda(coda* q){
    return q->valori[q->head++];
}

void deinit(coda* q){
    free(q->valori);
    q->capacity=0;
    q->head=0;
    q->tail=0;
}

int codavuota(coda* q){
    if(q->head==q->tail){
        return 1;
    }
    return 0;
}
