#include <stdio.h>              //segmentatio fault
#include <stdlib.h>

typedef struct _node{
    int grado;
    int* edge;
}node;



node* read_graph(int n){
    int i, g, j;
    node* E = (node*)malloc(n*sizeof(node));
    for(i=0;i<n;i++){
        scanf("%d", &g);
        E[i].grado = g;
        E[i].edge = malloc(g*sizeof(int));
        for(j=0;j<g;j++){
            scanf("%d", E[i].edge+j);
       }
    }
    return E;
}

void DFS(node* E, int src, int** colore){
    int i, el;
    for(i=0;i<E[src].grado;i++){
        el=E[src].edge[i];
        if((*colore)[el]==0){
            (*colore)[el]=1;
            DFS(E, el, &(*colore));
        }
    }
}

int connesso(node* E, int n){
    int i;
    int *colore=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        colore[i]=0;
    }
    int src=0;
    colore[src]=1;
    DFS(E, src, &colore);
    for(i=0;i<n;i++){
        if(!colore[i]) return 0;
    }
    return 1;
}


int main(){
    int n;
    scanf("%d", &n);
    node* E = read_graph(n);
    printf("%d", connesso(E, n));

    return 0;
}
