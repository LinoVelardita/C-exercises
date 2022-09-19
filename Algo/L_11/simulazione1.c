#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct _node{
    char* name;
    struct _node* next;
}node;

int compare(const void* a, const void* b){
	char* x=*(char**)a;
	char* y=*(char**)b;
	return strcmp(x, y);
}

void print_list(node* l){
    while(l!=NULL){
        printf("%s\n", l->name);
        l=l->next;
    }
}

int ambulanza(node** l, node* tail){
    int e;
    node *tmp=NULL;
    scanf("%d", &e);
    if(*l==NULL){
        switch(e){
            case(0):    return 0;
            case(2):    return ambulanza(l, tail);
            case(1):    (*l)=malloc(sizeof(node));
                        (*l)->name=(char*)malloc(sizeof(char)*MAX);
                        scanf("%s", (*l)->name);
                        (*l)->next=NULL;
                        node* tail=(*l);
                        //print_list(*l);
                        return 1+ambulanza(l, tail);
        }
    }
    else{
        switch(e){
            case(0):    return 0;
            case(1):    tail->next=malloc(sizeof(node));
                        tail->next->name=(char*)malloc(sizeof(char*)*MAX);
                        scanf("%s", tail->next->name);
                        tail->next->next=NULL;
                        //print_list(*l);
                        return 1+ambulanza(l, tail->next);
            case(2):    tmp=(*l);
                        (*l)=(*l)->next;
                        if((*l)==NULL){
                            tail=(*l);
                        }
                        free(tmp);
                        //print_list(*l);
                        return 1-ambulanza(l, tail);
        }
    }
}


int main(){
    node *l=NULL;
    node* tail=l;
    int dim=ambulanza(&l, tail);
    //printf("%s", l->name);
    //print_list(l);

    if(dim>0){
        char** a=(char**)malloc(sizeof(char*)*dim);
        int i;
        node *tmp=l;

        for(i=0;i<dim;i++){
            a[i]=malloc(sizeof(char)*MAX);
            strcpy(a[i], tmp->name);
            tmp=tmp->next;
        }

        qsort(a, dim, sizeof(char*), compare);

        for(i=0;i<dim;i++){
            printf("%s\n", a[i]);
        }
    }

    printf("$");
    return 0;
}
