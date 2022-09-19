#include <stdio.h>
#include <stdlib.h>

char *my_strcat2(char *s1, char *s2, int len1, int len2){
    int i=0;
    char *s3=malloc((len1+len2+1)*sizeof(char));    //Allocazione dinamica della memoria per una stringa
    while(i<len1){
        *(s3+i)=*(s1+i);
        i++;
    }

    i=0;
    while(i<len2){
        *(s3+len1+i)=*(s2+i);
        i++;
    }

    return s3;
}

int main(){
    int len_a, len_b;

    scanf("%d", &len_a);
    char a[len_a+1];            //+1 per il carattere terminatore "\0"
    scanf("%s", a);
    char *s1=a;

    scanf("%d", &len_b);
    char b[len_b+1];            //up
    scanf("%s", b);
    char *s2=b;

    printf("%s\n", my_strcat2(s1, s2, len_a, len_b));

    return 0;
}
