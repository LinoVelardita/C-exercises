#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    swap(&a, &b);
    printf("%d\n%d", a, b);
    return 0;
}
