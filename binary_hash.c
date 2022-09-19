#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* sx;
    struct s* dx;
}node;

void insert(int x, node **T);
int hash(int k, int n);
void read_tree(node* T);

int main(){
    int n, k, i;
    node** T;

    scanf("%d", &n);
    T=(node**)malloc(sizeof(node*)*n*2);
    for(i=0;i<(2*n);i++){
        T[i]=NULL;
    }
    scanf("%d", &k);
    while(k>=0){
        insert(k, &T[hash(k, n)]);
        scanf("%d", &k);
    }

    for(i=0;i<2*n;i++){
        read_tree(T[i]);
        printf("\n");
    }

    return 0;
}

int hash(int k, int n){
    return(k%(2*n));
}

void insert(int x, node** T){
    if(*T==NULL){
        node* new=malloc(sizeof(node));
        new->key=x;
        new->sx=NULL;
        new->dx=NULL;
        *T=new;
    }
    else{
        if(x > (*T)->key){
            insert(x, &(*T)->dx);
        }
        else insert(x, &(*T)->sx);
    }
}

void read_tree(node* T){
    if(T!=NULL){
        read_tree(T->sx);
        printf("%d -> ", T->key);
        read_tree(T->dx);
    }
}
