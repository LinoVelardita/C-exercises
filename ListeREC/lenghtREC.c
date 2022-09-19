#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};
typedef struct Node node;


int Rec_Lenght(node *l, int count){
  if(l!=NULL){
  l=l->next;
  count+=1;
  Rec_Lenght(l, count);
  }
  else return count;
}


void addbottom(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=NULL;
  if((*l)!=NULL){
    node *curr=*l;
    while(curr->next!=NULL){
      curr=curr->next;
    }
    curr->next=new;
  }
  else (*l)=new;
}


int main(){
  node *l=NULL;
  node *corr;
  int n, stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addbottom(&l, n);
    }
    else stop=1;
  }
  int count=0;
  int leng=Rec_Lenght(l, count);
  printf("%d", leng);
  return 0;
}
