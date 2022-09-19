#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int divide(int a[], int sx, int dx){
    int key=a[dx];
    int i, j;
    i=sx-1;
    for(j=sx;j<dx;j++){
        if(a[j]<=key){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[dx], &a[i+1]);
    
    return i+1;
}

void quicksort(int a[], int sx, int dx){
    if(sx<dx){
        int cx=divide(a, sx, dx);

        quicksort(a, sx, cx-1);
        quicksort(a, cx+1, dx);
    }
}

int main(){
    int dim, i;
    scanf("%d", &dim);
    int *a=malloc(sizeof(int)*dim);
    for(i=0;i<dim;i++){
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, dim-1);
    for(i=0;i<dim;i++){
        printf("%d ", a[i]);
    }
    return 0;

}
