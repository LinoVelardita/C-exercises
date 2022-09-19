#include <stdio.h>          //VIOLATING MEMORY LIMITS
#include <stdlib.h>
#include <string.h>


int search(char **a, char *s, int sx, int dx){
    if(sx>dx) return -1;
    else{
        int cx;
        if((sx+dx)%2==0) cx=(sx+dx)/2;
        else cx=(sx+dx+1)/2;

        if(strcmp(a[cx], s)==0) return cx;
        if(strcmp(a[cx], s)<0) return search(a, s, cx+1, dx);
        else return search(a, s, sx, cx-1);
    }
}

int main(){
    int dim;
    scanf("%d", &dim);
    char **a=malloc(dim*sizeof(char*));
    int i, k=0;
    for(i=0;i<dim;i++){
        a[i]=malloc(101*sizeof(char));
        scanf("%s", a[i]);
    }


    int *b=malloc(205*sizeof(int));             //ALLOCO LA MEMORIA PER CONTENERE GLI OUPUT
    char *s=malloc(101*sizeof(char));
    scanf("%d", &i);
    while(i==1){
        scanf("%s", s);
        b[k]=search(a, s, 0, dim-1);
        k++;
        scanf("%d", &i);
    }
    b[k]=-2;
    k=0;
    while(b[k]!=-2){
        printf("%d\n", b[k]);
        k++;
    }
    free(s);
    for(i=0;i<dim;i++){
        free(a[i]);
    }
    free(a);
    free(b);

    return 0;
}
