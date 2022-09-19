#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101

typedef struct _node{
    char* info;
    struct _node* next;
}node;

typedef struct _coda{
    node* head;
    node* tail;
    int dim;
}coda;

int cmp(const void* a, const void* b){
    char** x=(char**)a;
    char** y=(char**)b;
    return strcmp(*x, *y);
}

void accoda(coda* q, char* value){
    node* new=malloc(sizeof(node));
    new->info=malloc(LEN*sizeof(char));
    strcpy(new->info, value);
    new->next=NULL;
    q->dim++;
    if(q->head==NULL && q->tail==NULL){
        q->head=new;
        q->tail=new;
    }
    else{
        q->tail->next=new;
        q->tail=new;
    }
}

void deaccoda(coda* q){
    if(q->head!=NULL){
        q->dim--;
        node* save=q->head;
        if(q->head==q->tail){
            q->head=q->tail=NULL;
        }
        else{
            q->head=q->head->next;
        }
        free(save);
    }
}

void init(coda* q){
    q->head=NULL;
    q->tail=NULL;
    q->dim=0;
}

int codavuota(coda* q){
    if(q->head==NULL && q->tail==NULL){
        return 1;
    }
    return 0;
}

void intoarray(coda *q, char** array){
    int i;
    int dimaccodati=q->dim;
    for(i=0;i<dimaccodati;i++){
        array[i]=malloc(LEN*sizeof(char));
        strcpy(array[i], q->head->info);
        deaccoda(q);
    }
}

int main(){
    coda ambulatorio;
    char* read;
    int e, i;
    scanf("%d", &e);
    init(&ambulatorio);
    while(e!=0){
        switch(e){
            case(1):
                read=(char*)malloc(LEN*sizeof(char));
                scanf("%s", read);
                accoda(&ambulatorio, read);
                free(read);
            break;
            case(2):
                deaccoda(&ambulatorio);
            break;
        }
        scanf("%d", &e);
    }

    if(!codavuota(&ambulatorio)){
        char** accodati;
        int dimaccodati=ambulatorio.dim;
        accodati=malloc(dimaccodati*sizeof(char*));
        intoarray(&ambulatorio, accodati);
        qsort(accodati, dimaccodati, sizeof(char*), cmp);
        for(i=0;i<dimaccodati;i++){
            printf("%s\n", accodati[i]);
            free(accodati[i]);
        }
        free(accodati);
    }
    printf("$\n");
    return 0;
}
