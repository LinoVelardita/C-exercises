#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int dim, i, val;
    scanf("%d", &dim);
    int a[dim];
    for(i=0;i<dim;i++){
        scanf("%d", &val);
        a[i]=val;
    }
    i=0;
    while(i<dim/2){
        swap(&a[i], &a[(dim-i)-1]);
        i++;
    }
    i=0;
    for(i=0;i<dim;i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
