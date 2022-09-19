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
int BFS(graph* G, int n, int inizio, int fine);
void init(coda *q, int n);
void accoda(coda* q, int k);
int decoda(coda* q);
void deinit(coda* q);
int codavuota(coda* q);

int main(){
    int n;
    scanf("%d", &n);
    graph* G = (graph*)malloc(sizeof(graph)*n);
    read_graph(&G, n);
    int query, i, inizio, fine;
    scanf("%d", &query);
    for(i=0;i<query;i++){
        scanf("%d", &inizio);
        scanf("%d", &fine);
        printf("%d\n", BFS(G, n, inizio, fine));
    }
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

int BFS(graph* G, int n, int inizio, int fine){
    int i, u, v;
    int* colori=(int*)malloc(sizeof(int)*n);
    int* distance=malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        colori[i]=0;
        distance[i]=-1;
    }
    coda q;
    init(&q, n);
    accoda(&q, inizio);
    colori[inizio]=1;
    distance[inizio]=0;
    while(!codavuota(&q)){
        u=decoda(&q);
        for(i=0;i<G[u].grado;i++){
            v=G[u].adiacenti[i];
            if(colori[v]==0){
                distance[v]=distance[u]+1;
                if(v==fine){
                    return distance[v];
                }
                colori[v]=1;
                accoda(&q, v);
            }
        }
    }
    deinit(&q);
    return distance[fine];
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
