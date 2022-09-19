#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};
typedef struct Node node;


void addhead(node **l, int el){
  node *new=malloc(sizeof(node));
  new->info=el;
  if(*l==NULL){
    new->next=NULL;
  }
  else{
    new->next=*l;
  }
  *l=new;
}



int pari(int a){
  int found=0;
  if(a%2==0){
    found=1;
  }
  return found;
}

void insert(node **l){        //REC:inserisce -1 prima di ogni elemento pari//
  if((*l)!=NULL){
    if(pari((*l)->info)){
      node *new=malloc(sizeof(node));
      new->info=-1;
      new->next=*l;
      *l=new;
      insert(&(*l)->next->next);
    }
    else{
      insert(&(*l)->next);
    }
  }
}

void printlist(node *l){
  node *corr=l;
  while(corr!=NULL){
    printf("%d -> ", corr->info);
    corr=corr->next;
  }
  printf("NULL");
}


int main(){
  node *l=NULL;
  int n, stop=0;
  while(!stop){
    scanf("%d", &n);
    if(n>=0){
      addhead(&l, n);
    }
    else stop=1;
  }
  insert(&l);
  printlist(l);
  return 0;
}
