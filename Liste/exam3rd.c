#include <stdio.h>
#include <stdlib.h>
#define DIM_ARRAY 9

//List structure:
typedef struct s{
    int info;
    struct s* next;
} Elementodilista;

typedef Elementodilista* Listadielementi;

//Function to be implemented:
int lettura_lossy(float arr[]);
Listadielementi lista_interi(float arr[], int len);
void inverti_lista(Listadielementi* list);

//Function to print all the elements of the list:
void printList(Listadielementi list){
    printf("(");
    while(list!=NULL){
        printf("%d ", list->info);
        list=list->next;
    }
    printf(")\n");
}

int main(){
    int len, i;
    float arr[DIM_ARRAY];
    Listadielementi list;

    //Legge array
    len=lettura_lossy(arr);

    //Stampa array
    printf("Array:\n");
    for(i=0;i<len;i++){
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    //Costruisce la lista senza ripetizioni
    list=lista_interi(arr, len);
    //Stampa
    printf("Lista:\n");
    printList(list);

    //Inverte la lista
    inverti_lista(&list);
    //Stampa
    printf("Lista inversa:\n");
    printList(list);

    return 0;
}

int position(int i){
    if(i<9){
        return i;
    }
    else{
        position(i-9);
    }
}

int lettura_lossy(float arr[]){
    float a;
    int i=0;
    int ctrl=1;
    while(ctrl){
        scanf("%f", &a);
        if(a==0){
            ctrl=0;
        }
        else{
            arr[position(i)]=a;
            i++;
        }
    }
    if(i<9){
        return i;
    }
    else{
        return DIM_ARRAY;
    }
}

int convert(float x){
    if((x - (int)x) >= 0.5){
        x=(int)x+1;
    }
    else{
        x=(int)x;
    }
    return x;
}

int there(int a, Elementodilista *l){
    int ok=0;
    if(l!=NULL){
        Elementodilista *curr=l;
        while(curr!=NULL){
            if(curr->info==a){
                ok=1;
            }
            curr=curr->next;
        }
    }
    return ok;
}

void addbottom(Elementodilista **l, int el){
  Elementodilista *new=malloc(sizeof(Elementodilista));
  new->info=el;
  new->next=NULL;
  if((*l)!=NULL){
    Elementodilista *corr=(*l);
    while(corr->next!=NULL){
      corr=corr->next;
    }
    corr->next=new;
  }
  else{
    (*l)=new;
  }
}

Listadielementi lista_interi(float arr[], int len){
    Listadielementi l=NULL;
    int i;
    for(i=0;i<len;i++){
        if(!there(convert(arr[i]), l)){
            addbottom(&l, convert(arr[i]));
        }
    }
    return l;
}

int pippo(Elementodilista *l){      //pippo=1 -> dispari
    Elementodilista *curr=l;
    int count=0;                    //pippo=0 -> pari
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    return (count%2);
}

int length(Elementodilista *l){
    Elementodilista *curr=l;
    int count=0;
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    return count;
}

void swap(int *a, int *b){      //!!ricorda di chiamare con &!!
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void inverti_lista(Listadielementi* list){
    if( !pippo(*list) ){
        int i=0;
        int j=0;
        int rev=length((*list));
        Elementodilista *curr=(*list);
        Elementodilista *curr2=(*list);
        while(i <= ( length(*list)/2 )){
            while(j<rev){
                curr=curr->next;
                j++;
            }
            swap(&(curr->info), &(curr2->info));
            i++;
            j=0;
            rev--;
            curr2=curr2->next;
        }
    }
    else{
        int i=0;
        int j=0;
        int rev=length((*list));
        Elementodilista *curr=(*list);
        Elementodilista *curr2=(*list);
        while(i < ( (length((*list))+1)/2 )){
            while(j<rev){
                curr=curr->next;
                j++;
            }
            swap(&(curr->info), &(curr2->info));
            i++;
            j=0;
            rev--;
            curr2=curr2->next;
        }
    }
}
