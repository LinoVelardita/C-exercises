#include <stdio.h>


int count(int a[], int dim_a, int b[], int dim_b){
    int i=0, k=0, c=0;
    while(i<dim_a && k<dim_b){
        if(a[i]==b[k]){
            c++;
            i++;
            k++;
        }
        else{
            if(a[i]<b[k]){
                i++;
            }
            else k++;
        }

    }
    return c;
}


int main(){
    int dim_a, dim_b, i;
    scanf("%d", &dim_a);
    int a[dim_a];
    for(i=0;i<dim_a;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &dim_b);
    int b[dim_b];
    for(i=0;i<dim_b;i++){
        scanf("%d", &b[i]);
    }

    printf("%d\n", count(a, dim_a, b, dim_b));

    return 0;
}
