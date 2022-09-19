//add a element at the bottom of the list (not empty)

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;

void addbottom(node *l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=NULL;
  if(*l!=NULL){
    node *corr=*l;
    while(corr->next!=NULL){
      corr=corr->next;
    }
    corr->next=new;
  }
  else{
    *l=new;
  }
}

int main() {
  node *list=NULL;
  int n;
  scanf("%d", &n);
  addbottom(list, n);
  return 0;
}
