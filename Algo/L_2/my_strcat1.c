#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 1000

int len(char *s){
    int i=0;
    while(*(s+i)!=0 && i<DIM_MAX){
        i++;
    }
    return i;
}

char *my_strcat1(char *s1, char *s2){
    int i=0;
    char *s3=malloc(sizeof(char)*1000);

    while(i<=len(s1)){
        *(s3+i)=*(s1+i);
        i++;
    }
    i=0;
    while(i<=len(s2)+1){
        *(s3+len(s1)+i)=*(s2+i);
        i++;
    }

    return s3;
}

int main(){
    char a[DIM_MAX], b[DIM_MAX];
    scanf("%s", a);
    scanf("%s", b);
    char *s1=a;
    char *s2=b;
    printf("%s\n", my_strcat1(s1, s2));

    return 0;
}
