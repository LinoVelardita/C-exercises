#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int div=2;
    int ok=1;
    while(ok && div<x){
        if(x%div==0){
            ok=0;
        }
        else div++;
    }
    printf("%d", ok);
    return 0;
}
