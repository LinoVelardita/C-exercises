//add an element "v" in a list after the first occurrence of "el"

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;

void add_aft_el(node* l, int v, int el){
  int found=0;
  node *corr=l;
  while(!found && corr!=NULL) {
    if(corr->info==el) found=1;
    else corr=corr->next;
  }
  if(found) {
    node *aus=malloc(sizeof(node));
    aus->info=v;
    aus->next=corr->next;
    corr->next=aus;
  }
}

int main() {

  node *l=malloc(sizeof(node));
  node *curr;
  curr=l;
  int i;
  for(i=1;i<=10;i++) {                      //scan a list of 10 elements
    scanf("%d", &(curr->info));
    curr->next=malloc(sizeof(node));
    curr=curr->next;
  }
  curr->next=NULL;

  int add, after;
  scanf("%d%d", &add, &after);
  add_aft_el(l, add, after);

  node *curr2=l;
  while((curr2->next)!=NULL) {
    printf("%d\n", curr2->info);
    curr2=curr2->next;
  }
  return 0;
}
