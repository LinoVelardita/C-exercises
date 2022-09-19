//create an ordered list of elements
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};
typedef struct Node node;

void crealista(node **l, int n) {
  l=NULL;                                   //PAY ATTENTION **l//
    if(n>0) {
      int i;
      node *corr;
      *l=malloc(sizeof(node));
      corr=*l;
      for(i=0;i<=n;i++) {
        corr->info=i;
        corr->next=malloc(sizeof(node));
        corr=corr->next;
      }
      corr->next=NULL;
    }
}


int main() {
  node* lista;
  int m;
  scanf("%d", &m);
  crealista(&lista, m);                   //chiamata di funzione//
  return 0;
}
