#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(char *str1, char *str2) {
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}



int partition(char **a, int sx, int dx){
    char *s=malloc(101*sizeof(char));
    s=a[dx];
    int i, j;
    i=sx-1;
    for(j=sx;j<dx;j++){
        if(strcmp(a[j], s)<=0){
            i=i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[dx], a[i+1]);
    return i+1;
}


void quicksort(char **a, int sx, int dx){
    if(sx<dx){
        int pivot=partition(a, sx, dx);
        quicksort(a, sx, pivot-1);
        quicksort(a, pivot+1, dx);
    }
}


int main(){
    int dim, i;
    scanf("%d", &dim);
    char **a=malloc(dim*sizeof(char*));
    for(i=0;i<dim;i++){
        a[i]=malloc(101*sizeof(char));
        scanf("%s", a[i]);
    }

    quicksort(a, 0, dim-1);

    for(i=0;i<dim;i++){
        printf("%s\n", a[i]);
    }

    for(i=0;i<dim;i++){
        free(a[i]);
    }
    free(a);

    return 0;
}
