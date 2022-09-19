#include <stdio.h>

int sum_odd(int x){
    if(x>1){
        return ( (x*2) - 1 ) + sum_odd(x-1);
    }
    else{
        return 1;
    }
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", sum_odd(x));
    return 0;
}
