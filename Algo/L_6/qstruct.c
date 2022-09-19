#include <stdio.h>
#include <stdlib.h>

struct cartesyan{
    int x;
    int y;
};
typedef struct cartesyan cord;

int combare(const void* a1, const void* b1){
    cord a = *(cord*)a1;
    cord b = *(cord*)b1;
    if(a.x == b.x){
        return b.y - a.y;
    }
    else return a.x - b.x;

}

int main(){
    int n, i;
    scanf("%d", &n);
    cord* a=malloc(sizeof(cord)*n);
    for(i=0;i<n;i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    qsort(a, n, sizeof(cord), combare);
    for(i=0;i<n;i++){
        printf("%d %d\n", a[i].x, a[i].y);
    }

}
