#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct el{
    int left;
    int right;
};
typedef struct el index;

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

index distribuzione(int a[], int sx, int px, int dx) {
    //swap(&a[sx], &a[px]);
    index k;
    int x=a[sx];
    k.left=sx;
    k.right=sx+1;
    int j;
    for(j=k.right;j<=dx;j++){
        if(a[j]==x){
            swap(&a[j], &a[k.left]);
            k.right++;
        }
        else{
            if(a[j]<x){
                swap(&a[j], &a[k.left]);
                swap(&a[j], &a[k.right]);
                k.left++;
                k.right++;
            }
        }
    }


    return k;
}

void quicksort( int a[], int sx, int dx){

    int pivot, perno1, perno2;

    if( sx < dx ) {

      //pivot = sx + rand()%(dx - sx + 1);
      perno1 = distribuzione(a, sx, pivot, dx).left;
      perno2 = distribuzione(a, sx, pivot, dx).right;


      quicksort(a, sx, perno1-1);
      //quicksort(a, perno1, perno2-1);   //-->segmentation fault
      quicksort(a, perno2, dx);

  }
}



int main(){
    srand(time(NULL));
    int n, i;
    scanf("%d", &n);
    int* a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n-1);
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }

}
