#include <stdio.h>
#include <stdlib.h>
#define P 999149

typedef struct _node{
    int value;
    struct _node* next;
}node;

typedef struct _res{
    int max;
    int tot;
}res;

int hash(int a, int b, int dim, int x){
    return ((a*x + b) % P) % (2*dim);
}

void insert_list(node** l, int x){
    while(*l!=NULL){
        if((*l)->value==x) return;
        l=&((*l)->next);
    }
    node* new=(node*)malloc(sizeof(node));
    new->value=x;
    new->next=NULL;
    *l=new;
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

void insert_table(node** tab, int dim){
    int a, b, i, x, index;
    scanf("%d", &a);
    scanf("%d", &b);
    for(i=0;i<dim;i++){
        scanf("%d", &x);
        index=hash(a, b, dim, x);
        insert_list(&tab[index], x);
    }
}

int el_dist(node** t, int dim){
    int i, count=0;
    for(i=0;i<(dim*2);i++){
        count=count+len(t[i]);
    }
    return count;
}

int main(){
    int i, dim;
    scanf("%d", &dim);
    node** tab=(node**)malloc(sizeof(node*)*2*dim);
    for(i=0;i<(2*dim);i++){
        tab[i]=NULL;
    }
    insert_table(tab, dim);
    res x=trova_max(tab, dim);
    printf("%d\n%d\n", x.tot, x.max);
    printf("%d", el_dist(tab, dim));
    return 0;
}
