#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int a[], int dim){
    int i, j, min;
    for(i=0;i<dim-1;i++){
        min=i;
        for(j=i+1;j<dim;j++){
            if(a[j]<a[min]) min=j;
        }
        if(min!=i) swap(&a[i], &a[min]);
    }
}

int main(){
    int dim, i;
    scanf("%d", &dim);
    int a[dim];
    for(i=0;i<dim;i++){
        scanf("%d", &a[i]);
    }
    selection_sort(a, dim);
    for(i=0;i<dim;i++){
        printf("%d\n", a[i]);
    }

    return 0;
}
