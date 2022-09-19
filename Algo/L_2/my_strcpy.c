#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

char *my_strcpy(char *dest, char *src){
    dest=src;
    return dest;
}

int main(){
    char a[MAX];
    char *s=a;
    scanf("%s", a);
    char *s1=malloc(sizeof(char)*MAX);
    printf("%s\n", my_strcpy(s1, s));

    return 0;
}
