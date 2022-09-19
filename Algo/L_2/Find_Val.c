#include <stdio.h>
#include <stdlib.h>

int *FindVal(int a[], int dim, int val){
    int i=0;
    int *p=NULL;
    while(i<dim && p==NULL){
        if(a[i]==val){
            p=&a[i];
        }
        i++;
    }
    return p;
}


int main(){
    int a[10];
    int i, val;
    for(i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &val);
    int *x=NULL;
    x=FindVal(a, 10, val);

    if(x==NULL){
        printf("non trovato\n");
    }
    else{
        printf("trovato\n");
    }

    return 0;
}
