#include <stdio.h>

void insertion_sort(int a[], int dim){
    int i, j, key;
    for(j=1;j<dim;j++){
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}

int main(){
    int dim, i;
    scanf("%d", &dim);
    int a[dim];
    for(i=0;i<dim;i++){
        scanf("%d", &a[i]);
    }
    insertion_sort(a, dim);
    for(i=0;i<dim;i++){
        printf("%d\n", a[i]);
    }

    return 0;
}
