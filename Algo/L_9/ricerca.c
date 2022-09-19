#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *left;
    struct _node *right;
}node;



void insert_tree(node **t, int el){
    if(*t==NULL){
        *t=malloc(sizeof(node));
        (*t)->right=NULL;
        (*t)->left=NULL;
        (*t)->value=el;
    }
    else{
        if((*t)->value<el){
            insert_tree(&(*t)->right, el);
        }
        else insert_tree(&(*t)->left, el);
    }
}

void search_tree(node* t){
    int el;
    scanf("%d", &el);
    int count=0;
    while(el!=-1){
        node* tmp=t;
        while(tmp!=NULL){
            if(tmp->value==el){
                printf("%d\n", count);
                break;
            }
            count++;
            if(el > tmp->value) tmp=tmp->right;
            else tmp=tmp->left;
        }
        if(tmp==NULL) printf("NO\n");
        count=0;
        scanf("%d", &el);
    }
}

int main(){
    int n, i, el;
    scanf("%d", &n);
    node *t=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tree(&t, el);
    }
    search_tree(t);

    return 0;
}
