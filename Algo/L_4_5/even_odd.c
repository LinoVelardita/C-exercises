#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


int distribuzione(int a[], int sx, int px, int dx) {
    swap(&a[dx], &a[px]);
    int x=a[dx];
    int i, j;
    i=sx-1;
    for(j=sx;j<dx;j++){
        if(a[j]<=x){
            i=i+1;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[dx], &a[i+1]);
    return i+1;
}

int even_odd(int a[], int sx, int dx){
    int i, j;
    i=sx-1;
    for(j=0;j<dx;j++){
        if(a[j]%2==0){
            i=i+1;
            swap(&a[i], &a[j]);
        }
    }
    return i+1;      // ---> il primo elemento dispari
                    // OSSERVAZIONE: i pari a destra rimangono ordinati, i dipsari no
}


void quicksort( int a[], int sx, int dx){

    int perno, pivot;

    if( sx < dx ) {

      pivot = sx + rand()%(dx - sx + 1);
      perno = distribuzione(a, sx, pivot, dx);

      quicksort(a, sx, perno-1);
      quicksort(a, perno+1, dx);

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
    int pivot = even_odd(a, 0, n);
    quicksort(a, pivot, n-1);
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }

}
