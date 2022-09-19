//legge una lista da tastiera di 10 elementi//
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

}
