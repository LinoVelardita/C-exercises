//non scambia i valori

#include <stdio.h>
#include <stdlib.h>

struct El{
    int info;
    int count;
    struct El* next;
    struct El* prev;
};
typedef struct El el;

el* create(int x){
    el* l=(el*)malloc(sizeof(el));
    l->info=x;
    l->count=0;
    l->next=NULL;
    l->prev=NULL;
    return l;
}

el* add_tail(el* tmp, int x){
    tmp->next=(el*)malloc(sizeof(el));
    tmp->next->info=x;
    tmp->next->count=0;
    tmp->next->next=NULL;
    tmp->next->prev=tmp;
    return tmp->next;
}

void add_list(el** l, int index){           //aggiunge un elemento in fondo alla lista
    el* new=(el*)malloc(sizeof(el));
    new->info=index;
    new->next=NULL;
    if((*l)==NULL){
        (*l)=new;
    }
    else{
        el* tmp=(*l);
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=new;
    }
}

void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void principale(el* l){
    int index=0;
    int i;
    el* curr=l;
    el* limit=NULL;
    int found=0;
    while(index!=-1){
        scanf("%d", &i);
        while(!found && curr!=NULL){
            if(curr->info==i){
                found=1;
                curr->count++;
                printf("%d\n", index);
                limit=curr;
                while(limit->prev!=NULL && limit->count > limit->prev->count){

                    swap(&limit->count, &limit->prev->count);
                    swap(&limit->info, &limit->prev->info);
                    limit=limit->prev;
                }
            }
            else{
                index++;
                curr=curr->next;
            }
        }

        if(curr==NULL){
            index=-1;
        }
        else{
            index=0;
            curr=l;
            found=0;
        }
    }

    printf("%d", index);
}

int main(){
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    el* l=create(x);
    el* l2=NULL;
    el* tmp=l;
    while(n>1){
        scanf("%d", &x);
        tmp=add_tail(tmp, x);
        n--;
    }

    principale(l);

    return 0;
}
