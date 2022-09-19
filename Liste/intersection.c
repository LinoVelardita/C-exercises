//acquire two sequences of positive integers, terminated by a negative number, and inserts them into two lists...
//creates a third list containing the intersection ordered between the two lists...
//there must be no repeated elements and the values ​​must be stored in ascending order...
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* next;
};
typedef struct Node node;


void add_head(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=*l;
  *l=new;
}


void ord_list(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  node *curr=*l;
  node *prev=NULL;
  while(curr!=NULL && curr->info < el){
    prev=curr;
    curr=curr->next;
  }
  if(prev!=NULL){
    prev->next=new;
    new->next=curr;
  }
  else{
    add_head(l, el);
  }
}


void addbottom(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  new->next=NULL;
  if(*l!=NULL){
    node *corr=*l;
    while(corr->next!=NULL){
      corr=corr->next;
    }
    corr->next=new;
  }
  else *l=new;
}


node* union_list(node **l, node **l2){  //principal function
  node *l3=NULL;
  node *curr=*l;
  while(curr->next!=NULL){
    curr=curr->next;
  }
  curr->next=*l2;
  l3=*l;
  return l3;
}


int member(node *l, int el){
  node *curr=l;
  int ok=0;
  while(curr!=NULL && ok==0){
    if(curr->info==el) ok=1;
    else curr=curr->next;
  }
  return ok;
}


void remove_idem(node **l){
  node *corr=*l;
  if(*l==NULL || (*l)->next==NULL){
    return;
  }
  if((*l)->info==((*l)->next)->info){
    corr=(*l)->next;
    (*l)->next=corr->next;
    free(corr);
    remove_idem(l);
  }
  else {
          (*l)=(*l)->next;
          remove_idem(l);
        }
}


void print_list(node *l){   //print the third list
  node *corr=l;
  while(corr!=NULL){
    printf("%d\n", corr->info);
    corr=corr->next;
  }
}

int main(){
  node *l=NULL;
  node *l2=NULL;
  node *l3=NULL;
  int n;
  int stop=0;
  while(!stop){          //add an element as long as it's not less than 0
    scanf("%d", &n);
    if(n>=0){
      addbottom(&l, n);
    }
    else stop=1;
  }
  stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addbottom(&l2, n);
    }
    else stop=1;
  }
  l3=union_list(&l, &l2);
  node *cur=l3;
  while(cur!=NULL){
    if(member(l3, (cur->info))){
      ord_list(&l3, cur->info);
      cur=cur->next;
    }
    else cur=cur->next;
  }
  print_list(l3);
  return 0;
}
