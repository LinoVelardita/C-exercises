#include <stdio.h>
#include <stdlib.h>

struct  El{
    int info;
    struct El* next;
};
typedef  struct  El   ElementoLista ;
typedef  ElementoLista *ListaDiElementi;

//  Functions /Procedure   to  be implemented :

// add  definition  of  procedure / function  readList ()
void readList(ElementoLista **l){
    int n;
    scanf("%d", &n);
    *l=malloc(sizeof(ElementoLista));
    (*l)->info=n;
    (*l)->next=NULL;
    ElementoLista *curr=(*l);
    int stop=0;
    while(!stop){
        scanf("%d", &n);
        if(n>=curr->info){
            ElementoLista *new=malloc(sizeof(ElementoLista));
            new->info=n;
            new->next=NULL;
            curr->next=new;
            curr=curr->next;
        }
        else stop=1;
    }
}

// add  definition  of  procedure / function  cancellaDuplicates ()
void cancellaDuplicates(ElementoLista **l){
    ElementoLista *curr=(*l);
    ElementoLista *prev=(*l);
    curr=curr->next;
    while(curr!=NULL){
        while(prev->info==curr->info){
            ElementoLista *tmp=curr;
            curr=curr->next;
            prev->next=curr;
            free(tmp);
        }
        prev=prev->next;
        if(curr!=NULL){
            curr=curr->next;
        }
    }
}

// add  definition  of  procedure / function  filterLists ()
void filterLists(ElementoLista **l1, ElementoLista **l2){

}

// Function  to  print  all  the  elements  of  the  list :
void printList(ListaDiElementi list){
    printf("(");
    ElementoLista *curr=list;
    while(curr!=NULL){
        printf("%d", curr->info);
        curr=curr->next;
    }
    printf(")\n");
}

int main(){
    ListaDiElementi first_list, second_list;

    //Read and print the first list:
    //add call to procedure/function readList()//
    readList(&first_list);

    printf("Prima lista\n");
    printList(first_list);

    //Eliminates duplicates from the first list:
    //add call to procedure/function cancellaDuplicates()//
    cancellaDuplicates(&first_list);
    printf("Prima lista senza duplicati\n");
    printList(first_list);

    //Read and print the second list:
    //add call to procedure/function readList()//
    readList(&second_list);

    printf("Seconda lista\n");
    printList(second_list);

    //Eliminates duplicates from the second list:
    //add call to procedure/function cancellaDuplicates()//
    cancellaDuplicates(&second_list);
    printf("Seconda lista senza duplicati\n");
    printList(second_list);

    //Filter the first list using the elements of the second list:
    //add call to procedure/function filterLists()//
    filterLists(&first_list, &second_list);

    //print the filtered list:
    printf("Lista filtrata\n");
    printList(first_list);

    return 0;

}
