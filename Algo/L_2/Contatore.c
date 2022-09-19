#include <stdio.h>
#include <stdlib.h>

void reset(int array[], int len){
    int i;
    for(i=0;i<len;i++){
        array[i]=0;
    }
}

void add(int array[], int len, int val){
    if(val>=0 && val<=9){
        array[val]++;
    }
}


int main(){
    int a[10];
    reset(a, 10);
    int n;
    scanf("%d", &n);
    while(n!=-1){
        add(a, 10, n);
        scanf("%d", &n);
    }
    for(n=0;n<10;n++){
        printf("%d\n", a[n]);
    }
    return 0;
}
