#include <stdio.h>
#include <stdlib.h>

//qsort( void *array, dimensione_array, sizeof(elemento dell'array), compare() )

int compare(const void *x, const void *y){
    int valx = *((int*)x);
    int valy = *((int*)y);
    if(valx%2 == 0){
        if(valy%2 == 0){
            return valx - valy;
        }
        else return -42;
    }
    else{
        if(valy%2 == 0){
            return (42);
        }
        else return valy - valx;
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    int *a=malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), combare);
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
