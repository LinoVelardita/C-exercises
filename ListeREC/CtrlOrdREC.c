#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;


void addbottom(node **l, int n){
  node *new=malloc(sizeof(node));
  new->info=n;
  if(*l==NULL){
    new->next=NULL;
    *l=new;
  }
  else{
    node *corr=*l;
    while(corr->next!=NULL){
      corr=corr->next;
    }
    new->next=NULL;
    corr->next=new;
  }
}


int orderbool(node *l){
    int ord=1;
    if(l->next!=NULL){
      if(l->info<(l->next)->info){
        ord=orderbool(l->next);
      }
      else ord=0;
    }
    return ord;
}

void truefalse(node *l){
  if(orderbool(l)==1){
    printf("True");
  }
  else printf("False");
}

int main(){
  node *l=NULL;
  int n, stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addbottom(&l, n);
    }
    else stop=1;
  }
  truefalse(l);
}
