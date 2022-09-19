//prende una lista da tastiera di 10 elementi, e la stampa//
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;


int main() {

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
  node *curr2=l;
  while(curr2!=NULL) {
    printf("%d\n", curr2->info);
    curr2=curr2->next;
  }
  return 0;
}
