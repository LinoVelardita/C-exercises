#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* right;
    struct _node* left;
}node;

void insert_tree(node** t, int el){
    if(*t==NULL){
        *t=malloc(sizeof(node));
        (*t)->value=el;
        (*t)->right=NULL;
        (*t)->left=NULL;
    }
    else{
        if(el > (*t)->value){
            insert_tree(&(*t)->right, el);
        }
        else insert_tree(&(*t)->left, el);
    }
}



void print_ord(node* t){
    if(t!=NULL){
        print_ord(t->left);
        printf("%d\n", t->value);
        print_ord(t->right);
    }
}

int main(){
    int n, i, el;
    scanf("%d", &n);
    node* t=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tree(&t, el);
    }
    print_ord(t);
    return 0;
}
