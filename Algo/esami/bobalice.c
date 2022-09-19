#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101

typedef struct _oggetto{
    unsigned char* nome;
    int value;
}oggetto;

typedef struct _node{
    oggetto key;
    struct _node* next;
}node;


void insert(oggetto x, node** T){
    node* corr=*T;
    while(corr!=NULL){
        if(strcmp((char*)corr->key.nome, (char*)x.nome)==0){
            if(corr->key.value >= x.value){
                return;
            }
            else{
                corr->key.value=x.value;
                return;
            }
        }
        corr=corr->next;
    }
    node* new=(node*)malloc(sizeof(node));
    new->key=x;
    new->next=*T;
    *T=new;
}

int hash(unsigned char* x, int n){
    int num=0;
    int i=0;
    while(x[i]!='\0'){
        num+=(int)x[i++];
    }
    return num%(2*n);
}

void delete(node** list, node* todelete){
    if(*list==NULL){
        return;
    }
    if((*list)==todelete){
        node* curr=(*list);
        *list=(*list)->next;
        delete(list, todelete);
        free(curr);
    }
    else{
        delete(&((*list)->next), todelete);
    }
}

node* listbest(node* T){
    node* corr=T->next;
    node* best=T;
    while(corr!=NULL){
        if(corr->key.value > best->key.value){
            best=corr;
        }
        else if(corr->key.value==best->key.value && strcmp((char*)corr->key.nome, (char*)best->key.nome) < 0){
                best=corr;
             }
        corr=corr->next;
    }
    return best;
}

void print_best(node** T, int n){
    node* best=NULL;
    node* curr;
    int bestindex;
    int i;
    for(i=0;i<2*n;i++){
        if(T[i]!=NULL){
            if(best==NULL){
                best=listbest(T[i]);
                bestindex=i;
            }
            else{
                curr=listbest(T[i]);
                if(curr->key.value > best->key.value){
                    best=curr;
                    bestindex=i;
                }
                else if(curr->key.value==best->key.value && strcmp((char*)curr->key.nome, (char*)best->key.nome) < 0){
                        best=curr;
                        bestindex=i;
                     }
            }
        }
    }
    if(bestindex==-1) return;
    printf("%s\n", best->key.nome);
    delete(&T[bestindex], best);
}

int main(){
    int i, n;
    oggetto ins;
    node** T;
    int indice;
    scanf("%d", &n);
    T=(node**)malloc(2*n*sizeof(node*));
    for(i=0;i<2*n;i++){
        T[i]=NULL;
    }
    for(i=0;i<n;i++){
        ins.nome=malloc(LEN*sizeof(unsigned char));
        scanf("%s", ins.nome);
        scanf("%d", &(ins.value));
        indice=hash(ins.nome, n);
        insert(ins, &T[indice]);
    }
    if(n!=0){
        for(i=0;i<15;i++){
            print_best(T, n);
        }
    }
    return 0;
}
