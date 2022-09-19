#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* next;
}node;

void insert_tail(node** l, int el){
    node* new=malloc(sizeof(node));
    new->value=el;
    new->next=NULL;
    if(*l==NULL){
        *l=new;
    }
    else{
        node* tmp=*l;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=new;
    }
}



int avg(node* l, int n){
    int i, sum=0;
    for(i=0;i<n;i++){
        sum=sum+(l->value);
        l=l->next;
    }
    int c=(int)(sum/n);
    return c;
}

void stampa(node* l){
    while(l!=NULL){
        printf("%d ", l->value);
        l=l->next;
    }
}

void elimina(node**l, int media){               //elimina da l tutti gli elementi inferiori o uguali a media
    if((*l)->value<=media){
        node* tmp=(*l);
        (*l)=(*l)->next;
        free(tmp);
        elimina(l, media);
    }
    else{
        node* tmp=(*l);
        node* del=tmp;
        while(tmp->next!=NULL){
            if(tmp->next->value<=media){
                del=tmp->next;
                tmp->next=tmp->next->next;
                free(del);
            }
            else{
                tmp=tmp->next;
            }
        }
    }
}

int main(){
    int n, i, el;
    scanf("%d", &n);
    node* l=NULL;
    for(i=0;i<n;i++){
        scanf("%d", &el);
        insert_tail(&l, el);
    }
    int media=avg(l, n);
    printf("%d\n", media);
    stampa(l);
    elimina(&l, media);
    printf("\n");
    stampa(l);
    return 0;
}
