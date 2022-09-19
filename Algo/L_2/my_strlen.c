#include <stdio.h>
#define DIM_MAX 1000

int my_strlen(char *s){
    int i=0;
    while(*(s+i)!=0 && i<DIM_MAX){
        i++;
    }
    return i;
}

int main(){
    char string[DIM_MAX];
    scanf("%s", string);
    char *s=string;
    int len=my_strlen(s);
    printf("%d\n", len);
    return 0;
}
