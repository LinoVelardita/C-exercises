//UN GRAFO SI DICE EULERIANO SE È CONNESSO E TUTTI I SUOI VERTICI HANNO GRADO PARI
//LA FUNZIONE BFS MODIFICATA RITORNA 1 SE IL GRAFO È EULERIANO, 0 ALTRIMENTI

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
int BFS(graph* G, int n);
void init(coda *q, int n);
void accoda(coda* q, int k);
int decoda(coda* q);
void deinit(coda* q);
int codavuota(coda* q);

int main(){
    graph* G;
    int n;
    scanf("%d", &n);
    G=malloc(sizeof(graph)*n);
    read_graph(&G, n);
    int a=BFS(G, n);
    printf("%d", a);

    return 0;
}

void read_graph(graph** G, int n){
    int i, j, g;
    for(i=0;i<n;i++){
        scanf("%d", &g);
        (*G)[i].grado=g;
        (*G)[i].adiacenti=(int*)malloc((*G)[i].grado*sizeof(int));
        for(j=0;j<g;j++){
            scanf("%d", (*G)[i].adiacenti+j);
        }
    }
}

int BFS(graph* G, int n){
    int i, u, v;
    int* colori=(int*)malloc(sizeof(int)*n);
    int* gradi=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        colori[i]=0;
        gradi[i]=0;
    }
    coda q;
    init(&q, n);
    accoda(&q, 0);
    colori[0]=1;
    while(!codavuota(&q)){
        u=decoda(&q);
        for(i=0;i<G[u].grado;i++){
            v=G[u].adiacenti[i];
            gradi[u]++;
            if(colori[v]==0){
                colori[v]=1;
                accoda(&q, v);
            }
        }
        if(gradi[u]%2!=0) return 0;


    }
    for(i=0;i<n;i++){
        if(colori[i]==0) return 0;
    }
    return 1;
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
