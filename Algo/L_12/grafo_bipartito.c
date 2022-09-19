#include <stdio.h>
#include <stdlib.h>

typedef struct _edges{
    int grado;
    int* edge;
}edges;

edges* read_graph(int n){
    int i, g, j;
    edges* E = (edges*)malloc(n*sizeof(edges));
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

int dfs(edges* E, int s, int* colore){
    int i, v;
    for(i=0;i<E[s].grado;i++){
        v = E[s].edge[i];
        if(colore[v]==0){
            colore[v] = -colore[s];
            if(dfs(E, v, colore) == 0) return 0;
        }
        else if(colore[s] == colore[v]) return 0;
    }
    return 1;
}

int bipartito(edges* E, int n){
    int i;
    int *colore = malloc(n*sizeof(int));
    for(i=0;i<n;i++) colore[i] = 0;
    for(i=0;i<n;i++){
        if(colore[i]==0){
            colore[i]=1;
            if(dfs(E, i, colore)==0) return 0;          //restituisce 0 se non è possibile colorarlo, 1 altrimenti
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    edges* E = read_graph(n);
    printf("%d", bipartito(E,n));

    return 0;
}
