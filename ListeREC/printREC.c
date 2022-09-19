#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};
typedef struct Node node;

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

void addhead(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  if((*l)==NULL){
    new->next=NULL;
  }
  else new->next=(*l);
  (*l)=new;
}



int main(){
  node *l=NULL;
  node *corr=l;
  int n, stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addhead(&l, n);
    }
    else stop=1;
  }
  Rec_print(&l);
  return 0;
}
