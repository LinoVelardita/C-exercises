//create a list of 10 elemets
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node *next;
};
typedef struct Node node;

int main() {

  node *l=malloc(sizeof(node));
  node *corr;
  int i;
  corr=l;
  for(i=1;i>=10;i++) {
    corr->info=i;
    corr->next=malloc(sizeof(node));
    corr=corr->next;
  }
  corr->next=NULL;
}
