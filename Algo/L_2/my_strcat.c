#include <stdio.h>
#include <stdlib.h>

int len(char *s){
    int i=0;
    while(*(s+i)!=0){
        i++;
    }
    return i;
}

char *my_strcat(char *s1, char *s2){
    int i;
    int j=len(s1);
    for(i=0;i<len(s2);i++){
        *(s1+j+i)=*(s2+i);
    }
    return s1;
}

int main(){

    char *s1=malloc(1000*sizeof(char));
    char *s2=malloc(1000*sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);

    printf("%s\n", my_strcat(s1, s2));

    return 0;
}
