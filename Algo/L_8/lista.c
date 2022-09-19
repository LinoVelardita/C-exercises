#include <stdio.h>
#include <stdlib.h>

struct El{
    int info;
    struct El* next;
};
typedef struct El el;





void print_reverse(el* list){
    if(list->next!=NULL){
        print_reverse(list->next);
        printf("%d\n", list->info);
    }
}

int main(){
    int n, x;
    scanf("%d", &n);

    el* list=malloc(sizeof(el));

    el* tmp=list;

    while(n>0){
        scanf("%d", &x);
        tmp->info=x;
        tmp->next=malloc(sizeof(el));
        tmp=tmp->next;
        n--;
    }
    tmp=NULL;



    print_reverse(list);
    return 0;
}
