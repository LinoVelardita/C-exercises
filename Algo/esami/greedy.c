#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101

typedef struct _esame{
    char* titolo;
    int crediti;
    int durezza;
    int selected;
}esame;

int cmp(const void* a, const void* b){
    esame x=*(esame*)a;
    esame y=*(esame*)b;
    if(x.crediti==y.crediti){
        if(x.durezza==y.durezza){
            return strcmp(x.titolo, y.titolo);
        }
        return (x.durezza - y.durezza);
    }
    return (y.crediti - x.crediti);
}

int cmp2(const void* a, const void* b){
    esame x=*(esame*)a;
    esame y=*(esame*)b;
    if(x.selected && y.selected){
        return strcmp(x.titolo, y.titolo);
    }
    else if(x.selected==1 && y.selected==0) return -1;
    return 1;
}

void stampasel(esame* libretto, int n, int k){
    int i;
    for(i=0;i<n;i++){
        if(k==0) return;
        if(libretto[i].crediti<=k){
            libretto[i].selected=1;
            k-=libretto[i].crediti;
        }
    }
}


int main(){
    int k, n, i;
    esame* esami;
    scanf("%d", &k);
    scanf("%d", &n);
    esami=(esame*)malloc(n*sizeof(esame));
    for(i=0;i<n;i++){
        esami[i].titolo=(char*)malloc(sizeof(char)*LEN);
        scanf("%s", esami[i].titolo);
        scanf("%d", &esami[i].crediti);
        scanf("%d", &esami[i].durezza);
        esami[i].selected=0;

    }
    
    qsort(esami, n, sizeof(esame), cmp);

    stampasel(esami, n, k);
    qsort(esami, n, sizeof(esame), cmp2);

    i=0;
    while(i<n){
        if(esami[i].selected==1){
            printf("%s\n", esami[i].titolo);
        }
        i++;
    }
    return 0;
}
