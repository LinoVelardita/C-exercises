#include <stdio.h>
#include <stdlib.h>

struct El{
    int info;
    struct El* prev;
    struct El* next;
};
typedef struct El el;

el* create(int x){
    el* l=(el*)malloc(sizeof(el));
    l->info=x;
    l->next=NULL;
    return l;
}

el* add_tail(el* tmp, int x){
    tmp->next=(el*)malloc(sizeof(el));
    tmp->next->info=x;
    tmp->next->next=NULL;
    return tmp->next;
}

void mtf(el** l, int x){
    if((*l)->info!=x){
        el* tmp=(*l);
        while(tmp->next->info!=x){
            tmp=tmp->next;
        }
        free(tmp->next);
        tmp->next=tmp->next->next;
        el* new=(el*)malloc(sizeof(el));
        new->info=x;
        new->next=(*l);
        (*l)=new;
    }
}

void add_list(el** l, int index){
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

void search(el** l, el** l2){
    int i, index=0;
    int found=0;

    el* curr=NULL;

    while(index!=-1){
        scanf("%d", &i);
        curr=(*l);
        while(curr!=NULL && !found){
            if(curr->info==i){
                found=1;
                //printf("%d\n", index);
                add_list(l2, index);
                mtf(l, curr->info);
            }
            curr=curr->next;
            index++;
        }
        if(!found){
            index=-1;
            //printf("%d", index);
            add_list(l2, index);
        }
        else{
            found=0;
            index=0;
        }
    }

}

void print_list(el* l){
    while(l!=NULL){
        printf("%d\n", l->info);
        l=l->next;
    }
}

int main(){
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    el* l=create(x);
    el* tmp=l;
    while(n>1){
        scanf("%d", &x);
        tmp=add_tail(tmp, x);
        n--;
    }
    el* l2=NULL;
    search(&l, &l2);
    print_list(l2);
    return 0;
}
