#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* left;
    struct _node* right;
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

int comparison(node* t1, node* t2, int k){
    while(t1->value!=k || t2->value!=k){
        if(t1->value!=t2->value) return 0;

        if(k < t1->value) t1=t1->left;
        else t1=t1->right;

        if(k < t2->value) t2=t2->left;
        else t2=t2->right;
    }
    return 1;
}

int main(){
    int n, i, el;
    int k;
    scanf("%d %d", &n, &k);

    node* t1=(node*)malloc(sizeof(node)*n);
    node* t2=(node*)malloc(sizeof(node)*n);
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tree(&t1, el);
    }
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tree(&t2, el);
    }
    printf("%d", comparison(t1, t2, k));
    return 0;
}
