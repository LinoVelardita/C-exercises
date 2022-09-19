//it acquires a succession of positive integers and inserts them increasingly within a list
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;


void addhead(node **l, int el) {
  node *head=malloc(sizeof(node));
  head->info=el;
  head->next=*l;
  *l=head;
}


void ord_list(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  node *curr=*l;
  node *prev=NULL;
  while(curr!=NULL && curr->info < el){
    prev=curr;
    curr=curr->next;
  }
  if(prev!=NULL){
    prev->next=new;
    new->next=curr;
  }
  else{
    addhead(l, el);
  }
}


void print_list(node *l){
  node *corr=l;
  while(corr!=NULL){
    printf("%d\n", corr->info);
    corr=corr->next;
  }
}


int main() {
  node *l=NULL;
  int n;
  int stop=0;
  while(!stop) {
    scanf("%d", &n);
    if(n>=0){
      ord_list(&l, n);
    }
    else{
      if(n<0){
        stop=1;
        print_list(l);
      }
    }
  }
  return 0;
}
