//add an element "el" to the head of the list
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};
typedef struct Node node;


void addhead(node **l, int el) {
  node *head=malloc(sizeof(node));
  head->info=el;
  head->next=*l;
  *l=head;
}

int main() {
  node *list=NULL;
  int n;
  scanf("%d", &n);
  addhead(&list, n);
}
