#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101
#define LENUM 21

typedef struct _number{
    unsigned char* nome;
    unsigned char* numero;
}number;

typedef struct _node{
    number key;
    struct _node* next;
}node;

void insert(number x, node **T){
    node* new=(node*)malloc(sizeof(node));
    new->key=x;
    if(*T==NULL){
        new->next=NULL;
        *T=new;
        return;
    }
    node * corr=*T;
    node* prec=NULL;
    int bil;
    while(corr!=NULL){
        bil=strcmp((char*)x.nome, (char*)corr->key.nome);
        if(bil<0){
            if(prec!=NULL){
                prec->next=new;
            }
            else *T=new;
            new->next=corr;
            return;
        }
        else if(bil==0 && strcmp((char*)x.numero,(char*)corr->key.numero) < 0){
                if(prec!=NULL) prec->next=new;
                else *T=new;
                new->next=corr;
                return;
             }
        prec=corr;
        corr=corr->next;
    }
    prec->next=new;
}

void print_list(node* T){
    if(T!=NULL){
        printf("%s %s\n", T->key.nome, T->key.numero);
        print_list(T->next);
    }
}

int hash(unsigned char* x, int n){
    int num=0;
    int i=0;
    while(x[i]!='\0'){
        num+=(int)x[i++];
    }
    return num%(2*n);
}

int main(){
    int i;
    number ins;
    node** T;
    int n;
    int indice;
    scanf("%d", &n);
    T=(node**)malloc(2*n*sizeof(node*));
    for(i=0;i<2*n;i++){
        T[i]=NULL;
    }
    for(i=0;i<n;i++){
        ins.nome=malloc(LEN*sizeof(unsigned char));
        scanf("%s", ins.nome);
        ins.numero=malloc(LENUM*sizeof(unsigned char));
        scanf("%s", ins.numero);
        indice=hash(ins.nome, n);
        insert(ins, &T[indice]);
    }
    int k;
    scanf("%d", &k);
    if(n!=0){
        print_list(T[k]);
    }
    return 0;
}
