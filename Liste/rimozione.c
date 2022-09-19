#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;

void addbottom(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=NULL;
  if(*l!=NULL){
  node *corr;
  corr=*l;
  while(corr->next!=NULL){
    corr=corr->next;
  }
  corr->next=new;
  }
  else {
    *l=new;
  }
}

void addhead(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=*l;
  *l=new;
}

void remove_el(node **l, int v){
  if(v>0){
    if(*l!=NULL){
      if((*l)->info==v){
        node *head=*l;
        (*l)=(*l)->next;
        free(head);
      }
      else {
        int found=0;
        node *corr=*l;
        node *prec=corr;
        corr=corr->next;
        while(corr!=NULL && !found){
          if(corr->info==v){
            found=1;
            prec->next=corr->next;
            free(corr);
          }
          else {
            corr=corr->next;
            prec=prec->next;
          }
        }
      }
    }
  }
}

void print_list(node *l){
  node *curr=l;
  while(curr!=NULL){
    printf("%d\n", curr->info);
    curr=curr->next;
  }
}

int main() {
  node *l=NULL;
  int stop=0;
  int n;
  while(!stop) {
    scanf("%d", &n);
    if(n<0) {
      remove_el(&l, (-1)*n);
    }
    else{
      if(n>0 && n%2==0){
        addhead(&l, n);
      }
      else{
        if(n>0 && n%2!=0){
          addbottom(&l, n);
        }
        else{
          if(n==0){
            print_list(l);
            stop=1;
          }
        }
      }
    }
  }
  return 0;
}
