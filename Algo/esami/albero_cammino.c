#include <stdio.h>
#include <stdlib.h>

typedef struct _soluzione{
    int somma;
    int min;
}soluzione;

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}node;


soluzione maxofsums(soluzione a, soluzione b){
    if(a.somma>b.somma){
        return a;
    }
    else if(a.somma<b.somma) return b;
    else if(a.min<b.min) return a;
    return b;
}

void insert(node** t, int k){
    if(*t==NULL){
        node* new=malloc(sizeof(node));
        new->key=k;
        new->right=new->left=NULL;
        *t=new;
        return;
    }
    if((*t)->key<k){
        insert(&(*t)->right, k);
    }
    else insert(&(*t)->left, k);
}

void libera(node* t){
    if(t!=NULL){
        libera(t->left);
        libera(t->right);
        free(t);
    }
}

int min(int a, int b){
    if(a>b) return b;
    return a;
}

soluzione minmaxsum(node* t){
    if(t==NULL){
        soluzione nil;
        nil.somma=0;
        nil.min=0;
        return nil;
    }
    else if(t->left==NULL && t->right==NULL){
        soluzione foglia;
        foglia.somma=t->key;
        foglia.min=t->key;
        return foglia;
        }
        else{
            soluzione sx=minmaxsum(t->left);
            soluzione dx=minmaxsum(t->right);
            soluzione best;
            best=maxofsums(sx, dx);
            best.somma+=t->key;
            best.min=min(t->key, best.min);
            return best;
        }
}

int main(){
    node* T;
    T=NULL;
    int n, i, k;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        insert(&T, k);
    }
    soluzione minofmax=minmaxsum(T);
    printf("%d\n", minofmax.min);

    return 0;
}
