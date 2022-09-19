#include <stdio.h>
#include <stdlib.h>

typedef struct El{
    int x;
    int y;
    int c;
}el;


int mbare(const void* a, const void* b){
    el x=*(el*)a;
    el y=*(el*)b;
    if (x.c == y.c) return 1;
    else return (x.c - y.c);
}



void question(el* a, int dim_a, int quest){

    int x1, y1, x2, y2;
    int i, j;
    int count=0;
    int colour=-1;



    for(i=0;i<quest;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(j=0;j<dim_a;j++){

            if(a[j].x >= x1 && a[j].x <=x2 && a[j].y >= y1 && a[j].y <= y2){
                if(a[j].c!=colour){
                    count++;
                    colour=a[j].c;
                }
            }
        }
        printf("%d\n", count);
        count=0;
        colour=-1;

    }
}

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    el* arr=(el*)malloc(sizeof(el)*n);
    for(i=0;i<n;i++){
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].c);
    }
    qsort(arr, n, sizeof(el), mbare);


    question(arr, n, m);


    return 0;
}
