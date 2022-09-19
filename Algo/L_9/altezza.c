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
        if((*t)->value < el){
            insert_tree(&(*t)->right, el);
        }
        else insert_tree(&(*t)->left, el);
    }
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int height_tree(node* t){
    if(t==NULL) return 0;
    else return max(height_tree(t->left)+1, height_tree(t->right)+1);
}

int main(){
    int n, el, i;
    scanf("%d", &n);
    node *t=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el),
        insert_tree(&t, el);
    }
    printf("%d", height_tree(t));

    return 0;
}
