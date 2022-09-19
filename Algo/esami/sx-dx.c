#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}node;

int leftvisit(node* t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+leftvisit(t->left);
    }
}

int rightvisit(node* t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+rightvisit(t->right);
    }
}

void stampe(node* t){
    if(t!=NULL){
        stampe(t->left);
        if(leftvisit(t->left)>rightvisit(t->right)){
            printf("%d\n", t->key);
        }
        stampe(t->right);
    }
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

int main(){
    node* T;
    T=NULL;
    int n, i, k;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        insert(&T, k);
    }
    stampe(T);
    return 0;

}
