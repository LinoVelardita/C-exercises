//funzione h(x)=((ax + b) % p) % 2n
//p=999149

#include <stdio.h>
#include <stdlib.h>

#define P 999149

typedef struct Node{
    int value;
    struct Node* next;
}node;

typedef struct _res{
    int max;
    int tot;
}res;

int hash(int a, int b, int dim, int x){
    return ((a*x + b) % P) %(2*dim);
}

void insert(node** l, int x){
    node* new=(node*)malloc(sizeof(node));
    new->value=x;
    new->next=*l;
    *l=new;
}

void insert_table(node** tab, int dim){
    int a, b, i, x, index;
    scanf("%d", &a);
    scanf("%d", &b);

    for(i=0;i<dim;i++){
        scanf("%d", &x);
        index=hash(a, b, dim, x);
        insert(&tab[index], x);
    }
}

int len(node* l){
    if(l==NULL) return 0;
    else return (len(l->next)+1);
}

res trova_max(node** tab, int dim){
    int max=0;
    int tot=0;
    int tmp, i;
    for(i=0;i<(2*dim);i++){
        tmp=len(tab[i]);
        if(tmp!=0) tot=tot+tmp-1;
        if(tmp>max) max=tmp;
    }
    res x;
    x.tot=tot;
    x.max=max;
    return x;
}

int main(){
    int dim, i;
    scanf("%d", &dim);
    node** tab=(node**)malloc(sizeof(node*)*2*dim);
    for(i=0;i>(2*dim);i++){
        tab[i]=NULL;
    }
    insert_table(tab, dim);


    res x=trova_max(tab, dim);
    printf("%d\n%d", x.max, x.tot);
    return 0;
}
