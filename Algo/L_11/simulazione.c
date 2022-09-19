#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct _node {
	char* name;
	struct _node* next;
	struct _node* prev;
}node;

int compare(const void* a, const void* b){
	char* x=*(char**)a;
	char* y=*(char**)b;
	return strcmp(x, y);
}

int ambulanza(node** l, node* tail){
	int e;
	scanf("%d", &e);
	if(*l==NULL){
		switch(e){
			case 0: return 0;
			case 2: return ambulanza(l, tail);
			case 1:  (*l)=malloc(sizeof(node));
					(*l)->name=(char*)malloc(sizeof(char)*MAX);

					scanf("%s", (*l)->name);


					(*l)->next=NULL;
					(*l)->prev=NULL;
					node* tail=(*l);
					return 1+ambulanza(l, tail);
		}
	}
	else{
		switch(e){
			case 0: return 0;
			case 1:  tail->next=malloc(sizeof(node));
					tail->next->name=(char*)malloc(sizeof(char)*MAX);

					scanf("%s",  tail->next->name);
					node* tmp=tail;
					tail=tail->next;
					tail->prev=tmp;
					tail->next=NULL;
					return 1+ambulanza(l, tail);
			case 2: if(tail->prev==NULL){
						free(tail);
						(*l)=NULL;
						tail=(*l);
						return 1-ambulanza(l, tail);
					}
					else{
						node* tmp=tail;
						tail=tail->prev;
						free(tmp);
						tail->next=NULL;
						return 1-ambulanza(l, tail);
					}
		}
	}

}

int main(){
	node* l=NULL;
	node* tail=l;
	int dim=ambulanza(&l, tail);
	char** a=(char**)malloc(sizeof(char)*dim);
	int i;
	for(i=0;i<dim;i++){
		a[i]=malloc(sizeof(char)*MAX);
		strcpy(a[i], l->name);
		l=l->next;
	}
	qsort(a, dim, sizeof(char*), compare);
	for(i=0;i<dim;i++){
		printf("%s\n", a[i]);
	}
    printf("$");

	return 0;
}
