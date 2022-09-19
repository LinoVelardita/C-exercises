#include <stdio.h>

int main(){
    int x;
    int a=0;
    while(x!=0){
        scanf("%d", &x);
        a=a+x;
    }
    printf("%d\n", a);
    return 0;
}
