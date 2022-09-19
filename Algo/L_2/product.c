#include <stdio.h>
#include <stdlib.h>

int len(char* s){
    int i=0;
    while(*(s+i)!=0){
        i++;
    }
    return i;
}

char* product(char* str, int k){
    int i=0;
    int l=len(str);
    int j=len(str);
    while(k>1){
        i=0;
        while(i<l){
            *(str+i+j)=*(str+i);
            i++;
        }
        k--;
        j=j+l;
    }
    *(str+j)='\0';
    return str;
}


int main(){
    char *s=malloc(sizeof(char)*1000);
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    printf("%s", product(s, k));
    return 0;
}
