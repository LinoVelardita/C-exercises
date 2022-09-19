#include <stdio.h>



int sub_sum(int a[], int dim_a){
    int sum=0, max=0;
    int i;
    for(i=0;i<dim_a;i++){
        if(sum>0){
            sum=sum+a[i];
        }
        else{
            sum=a[i];
        }
        if(sum>max){
            max=sum;
        }
    }
    return max;
}


int main(){
    int dim_a, i;
    scanf("%d", &dim_a);
    int a[dim_a];
    for(i=0;i<dim_a;i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", sub_sum(a, dim_a));
    return 0;
}
