#include <stdio.h>

void minmax(int a[], int dim, int *min, int *max){
    int i;
    *min=0;
    *max=0;
    for(i=1;i<dim;i++){
        if(a[i] > a[*max]){
            *max=i;
        }
        if(a[i] < a[*min]){
            *min=i;
        }
    }
}

int main(){
    int i, min, max, pmin, pmax;
    int a[10];
    for(i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    min=a[0];
    max=a[0];
    for(i=1;i<10;i++){
        if(a[i] > max){
            max=a[i];
        }
        if(a[i] < min){
            min=a[i];
        }
    }
    minmax(a, 10, &pmin, &pmax);
    printf("%d\n%d\n%d\n%d", pmin, min, pmax, max);
    return 0;
}
