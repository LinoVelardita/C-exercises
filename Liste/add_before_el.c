//add an element "v" in a list, before the first occurence of "el"

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;

void addhead(node **le, int n) {
  node *head=malloc(sizeof(node));
  head->info=n;
  head->next=*le;
  *le=head;
}

void add_before_el(node **l, int v, int el){
  if((*l)!=NULL) {
    if((*l)->info==el) {
      addhead(l, el);
    }
  }
  else {
    int found=0;
    node *corr=*l;
    node *prec=NULL;

    while(!found && corr->next!=NULL) {
      if(corr->info==el) found=1;
      else {
        prec=corr;
        corr=corr->next;
      }
      if(found) {
        node *aus=malloc(sizeof(node));
        aus->info=v;
        prec->next=aus;
        aus->next=corr;
      }
    }
  }
}

int main(){

  node *l=malloc(sizeof(node));
  node *curr;
  curr=l;
  int i;
  for(i=1;i<=10;i++) {
    scanf("%d", &(curr->info));
    curr->next=malloc(sizeof(node));
    curr=curr->next;
  }
  curr->next=NULL;
  add_before_el(&l, 2, 5);
  node *curr2=l;
  while((curr2->next)!=NULL) {
    printf("%d\n", curr2->info);
    curr2=curr2->next;
  }
  return 0;
}
