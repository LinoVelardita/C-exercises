#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* next;
}node;

void insert_tail(node** l, int el){
    node* new=(node*)malloc(sizeof(node));
    new->value=el;
    new->next=NULL;
    if(*l==NULL){
        (*l)=new;
    }
    else{
        node* tmp=(*l);
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=new;
    }
}

void stampa(node* l){
    while(l!=NULL){
        printf("%d ", l->value);
        l=l->next;
    }
}

int sum_list(node* l){
    if(l==NULL){
        return 0;
    }
    return (l->value)+sum_list(l->next);
}

void stack_stampa(node* l, int somma){
    if(l==NULL) return;
    somma-=(l->value);
    printf("%d ", somma);
    stack_stampa(l->next, somma);
}

int main(){
    int n, i, el;
    scanf("%d", &n);
    node* l=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tail(&l, el);
    }
    stampa(l);
    int somma=sum_list(l);
    printf("\n");
    stack_stampa(l, somma);

    return 0;
}
