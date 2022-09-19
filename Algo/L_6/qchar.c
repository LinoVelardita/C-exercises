#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int compare(const void* a, const void* b){
    char* x = *(char**)a;
    char* y = *(char**)b;
    return -strcmp(x, y);

}

int main(){
    int n, i;
    scanf("%d", &n);
    char** a=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        a[i]=(char*)malloc(sizeof(char)*101);
        scanf("%s", a[i]);
    }

    qsort(a, n, sizeof(char*), compare);

    for(i=0;i<n;i++){
        printf("%s\n", a[i]);
    }


    return 0;
}
