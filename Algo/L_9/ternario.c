#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* left;
    struct _node* center;
    struct _node* right;
}node;

void insert_tree(node** t, int el){
    if(*t==NULL){
        *t=(node*)malloc(sizeof(node));
        (*t)->value=el;
        (*t)->left=NULL;
        (*t)->center=NULL;
        (*t)->right=NULL;
    }
    else{
        if(el % ((*t)->value) == 0) insert_tree(&(*t)->center, el);
        else{
            if(el < (*t)->value) insert_tree(&(*t)->left, el);
            else insert_tree(&(*t)->right, el);
        }
    }
}

int conta_nodi(node* t){
    if(t==NULL) return 0;
    if(t->left!=NULL && t->center!=NULL && t->right!=NULL){
        return (1+conta_nodi(t->left)+conta_nodi(t->center)+conta_nodi(t->right));
    }
    else return (conta_nodi(t->left)+conta_nodi(t->center)+conta_nodi(t->right));
}

int main(){
    int i, n, el;
    scanf("%d", &n);
    node* t=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tree(&t, el);
    }
    printf("%d", conta_nodi(t));
    return 0;
}
