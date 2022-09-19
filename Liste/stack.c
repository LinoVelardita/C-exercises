#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;

void addhead(node **l, int v){
  node *head=malloc(sizeof(node));
  head->info=v;
  head->next=*l;
  *l=head;
}

void remove_head(node **l){
  if(*l!=NULL){
  node *head=*l;
  *l=(*l)->next;
  free(head);
  }
}

void print_list(node *l){
  node* curr=l;
  while(curr!=NULL){
    printf("%d\n", curr->info);
    curr=curr->next;
  }
}

int main() {
  node *l=NULL;
  int stop=1;
  int n;
  while(stop!=0){
    scanf("%d", &n);
    if(n>0){
      addhead(&l, n);
    }
    else{ if(n==0){
            remove_head(&l);
         }
         else{ if(n<0){
                print_list(l);
                stop=0;
              }
         }
    }
  }
  return 0;
}
