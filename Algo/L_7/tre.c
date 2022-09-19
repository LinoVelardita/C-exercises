#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

typedef struct El{
    char* string;
    char *anagramma;
}el;

int mbare(const void* a, const void* b){
    char x=*(char*)a;
    char y=*(char*)b;
    return (x - y);
}

int fratuzzo(const void* a, const void* b){
    el x, y;
    x=*(el*)a;
    y=*(el*)b;

    if(strcmp(x.anagramma, y.anagramma)==0){
        return strcmp(x.string, y.string);
    }
    else return strcmp(x.anagramma, y.anagramma);
}

void function(el* s, int n){
    qsort(s, n, sizeof(el), fratuzzo);
    int i=0;
    printf("%s ", s[i].string);
    for(i=1;i<n;i++){
        if(strcmp(s[i-1].anagramma, s[i].anagramma)!=0) printf("\n");
        printf("%s ", s[i].string);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    el* s=(el*)malloc(sizeof(el)*n);
    for(i=0;i<n;i++){
        s[i].string=(char*)malloc(sizeof(char)*MAX);
        s[i].anagramma=(char*)malloc(sizeof(char)*MAX);
        scanf("%s", s[i].string);
    }
    for(i=0;i<n;i++){
        strcpy(s[i].anagramma, s[i].string);
        qsort(s[i].anagramma, strlen(s[i].anagramma), sizeof(char), mbare);
    }
    function(s, n);
    return 0;
}
