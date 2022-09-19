#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

void push_descending (NodeList *head,int el){
  NodeList cur;
  NodeList prev;
  NodeList new=malloc(sizeof(Node));
  new->info=el;
  if (*head==NULL){
    new->next=*head;
    *head=new;}
  else{
      cur=*head;
      prev=NULL;
      while (cur!=NULL && cur->info>=el ){
        prev=cur;
        cur=cur->next;}
      if (prev==NULL){
        new->next=*head;
        *head=new;}
      else{
        prev->next=new;
        new->next=cur;}}
}

void push_missing (NodeList head){
  if (head!=NULL && head->next!=NULL){
      if ((head->info)-(head->next->info)>1){
        NodeList new=malloc(sizeof(Node));
        new->info=(head->info)-1;
        new->next=head->next;
        head->next=new;
        push_missing(head->next);}
      else{
        push_missing(head->next);}}
}

void printList (NodeList head){
  NodeList cur=head;
  while (cur!=NULL){
    printf("%d ",cur->info);
    cur=cur->next;}
  }

void main(){
  NodeList list=NULL;
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      push_descending(&list,n);
    else
        end=1;}
  push_missing(list);
  printList(list);
}
