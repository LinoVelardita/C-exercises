#include <stdio.h>
#define MAX 1000

int len(char *s){
    int i=0;
    while(*(s+i)!=0 && i<MAX){
        i++;
    }
    return i;
}

int my_strcmp(char *s1, char*s2){
    if(len(s1)==len(s2)){
        int n=0;
        int stop=0;
        while(n<=len(s1) && !stop){
            if(*(s1+n)>*(s2+n)){
                stop=1;
                return 1;
            }
            else{
                if(*(s1+n)<*(s2+n)){
                    stop=1;
                    return (-1);
                }
            }
            n++;
        }
        if(!stop){
            return 0;
        }

    }
    else{
        if(len(s1)>len(s2)){
            return 1;
        }
        else return -1;
    }
}

int main(){
    char a[MAX], b[MAX];
    char *s1=a;
    char *s2=b;
    scanf("%s", a);
    scanf("%s", b);
    if(my_strcmp(s1, s2)>0){
        printf("+1");
    }
    else{
        if(my_strcmp(s1, s2)<0){
            printf("-1");
        }
        else printf("0");
    }
}
