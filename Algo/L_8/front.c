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

void search(el** l){
    int i, index=0;
    int found=0;

    el* curr=NULL;

    while(index!=-1){
        scanf("%d", &i);
        curr=(*l);
        while(curr!=NULL && !found){
            if(curr->info==i){
                found=1;
                printf("%d\n", index);
                mtf(l, curr->info);
            }
            curr=curr->next;
            index++;
        }
        if(!found){
            index=-1;
            printf("%d", index);
        }
        else{
            found=0;
            index=0;
        }
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
    search(&l);
    return 0;
}
