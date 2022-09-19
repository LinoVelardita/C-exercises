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
  new->next=*l;
  *l=new;
}



void Reverse(node **l){
  node *aus;
  if(*l!=NULL){
    if((*l)->next!=NULL){
      aus=*l;
      *l=(*l)->next;
      Reverse(l);
      aus->next->next=aus;
      aus->next=NULL;
    }
  }
}


void printlist(node *l){
  node *corr=l;
  while(corr!=NULL){
    printf("%d -> ", corr->info);
    corr=corr->next;
  }
  printf("NULL");
}


int main() {
  node *l=NULL;
  int n, stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addhead(&l, n);
    }
    else stop=1;
  }
  Reverse(&l);
  printlist(l);
}
