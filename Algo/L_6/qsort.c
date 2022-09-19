#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct el{
    char* s;
    int l;
};
typedef struct el El;


int compare(const void* a, const void* b){
    El s_1=*(El*)a;
    El s_2=*(El*)b;
    if(s_1.l == s_2.l){
        return strcmp(s_1.s, s_2.s);
    }
    else return s_1.l - s_2.l;

}

int main(){
    int n, i;
    scanf("%d", &n);
    El *a=malloc(sizeof(El)*n);
    for(i=0;i<n;i++){
        a[i].s=malloc(sizeof(char)*101);
        scanf("%s", a[i].s);
        a[i].l = strlen(a[i].s);
    }
    qsort(a, n, sizeof(El), compare);

    for(i=0;i<n;i++){
        printf("%s\n", a[i].s);
    }

    return 0;
}
