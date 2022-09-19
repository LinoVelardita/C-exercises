//add an element to the head of the list, and return the pointer of the 1st element

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node* next;
};
typedef struct Node node;

node* add(node* l, int n) {
  node* new=malloc(sizeof(node));
  new->info=n;
  new->next=l;
  return l;
}

int main() {
  node* list=NULL;
  int a;
  scanf("%d", &a);
  list=add(list, a);
  return 0;
}
