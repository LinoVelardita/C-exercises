#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int compare(const void *a, const void *b){
    char *x=*(char**)a;
    char *y=*(char**)b;
    return strcmp(x,y);
}


char **print(char **a, int n, int k){
    int j, max=1, tmp=1, index=0;
    char* val=malloc(sizeof(char)*MAX);
    char **c=malloc(sizeof(char*)*k);
    while(k>0){
        for(j=0;j<n-1;j++){
            if(a[j]!="$$$" && strcmp(a[j],a[j+1])==0 ){
                tmp++;
            }

            else tmp=1;

            if(tmp>max){
                max=tmp;
                index=j;
            }
        }
        while(strcmp(a[index], "$$$")==0){
            index++;
        }
        max=1;
        c[k-1]=malloc(sizeof(char)*MAX);
        c[k-1]=a[index];
        val = a[index];
        for(j=0;j<n;j++){
            if(strcmp(a[j],val)==0){
                a[j]="$$$";
            }
        }
        k--;
    }


    return c;
}



int main(){
    int n, k, i;
    scanf("%d", &n);
    scanf("%d", &k);
    char **a=malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        a[i]=malloc(sizeof(char)*MAX);
        scanf("%s", a[i]);
    }
    //qui va bene
    qsort(a, n, sizeof(char*), compare);
    //qui va bene

    //char** c=malloc(sizeof(char*)*k);
    //for(i=0;i<k;i++){
    //    c[i]=malloc(sizeof(char)*MAX);
    //}

    char** c=print(a, n, k);


    qsort(c, k, sizeof(char*), compare);

    for(i=0;i<k;i++){
        printf("%s\n", c[i]);
    }


    return 0;
}
