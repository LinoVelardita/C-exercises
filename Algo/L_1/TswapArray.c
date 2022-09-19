#include <stdio.h>          //CORREGGERE(LIMITE: 568 Ki)

void tswap(int *x, int *y, int *z){
    short temp;
    temp=*x;
    *x=*z;
    *z=*y;
    *y=temp;
}

int main(){
    int a[2];
    scanf("%d", &a[0]);
    scanf("%d", &a[1]);
    scanf("%d", &a[2]);
    tswap(&a[0], &a[1], &a[2]);
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d", a[2]);
    return 0;
}
