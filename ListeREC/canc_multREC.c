#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;


void addhead(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  if((*l)==NULL){
    new->next=NULL;
    (*l)=new;
  }
  else{
    new->next=(*l);
    (*l)=new;
  }
}

void canc_mult(node **l, int n){
  if((*l)!=NULL){
    if((*l)->info%n==0){
      node *corr=*l;
      *l=corr->next;
      free(corr);
      canc_mult(l, n);
    }
    else{
      canc_mult(&(*l)->next, n);
    }
  }
}


void Rec_print(node **l){
  node *curr=(*l);
  if(curr!=NULL){
    printf("%d -> ", curr->info);
  }
  if((*l)!=NULL){
  Rec_print(&(*l)->next);
  }
  else if((*l)==NULL){
    printf("NULL");
  }
}


int main() {
  node *l=NULL;
  int multiplo, n, stop=0;
  scanf("%d", &multiplo);
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addhead(&l, n);
    }
    else stop=1;
  }
  canc_mult(&l, multiplo);
  Rec_print(&l);
}
