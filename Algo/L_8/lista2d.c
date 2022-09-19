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
    l->next=NULL;
    l->prev=NULL;
    l->info=x;
    return l;
}

el* add_tail(el* tmp, int x){
    tmp->next=(el*)malloc(sizeof(el));
    tmp->next->info=x;
    tmp->next->next=NULL;
    tmp->next->prev=tmp;
    return tmp->next;
}

void print_rev(el* last){
    while(last!=NULL){
        printf("%d\n", last->info);
        last=last->prev;
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
    print_rev(tmp);

    return 0;
}
