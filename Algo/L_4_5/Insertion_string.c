#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** insertion_string(char **a, int dim){
    int i, j;
    char *key=malloc(101*sizeof(char));
    for(j=1;j<dim;j++){
        strcpy(key, a[j]);
        i=j-1;
        while(i>=0 && strcmp(a[i], key)>0){
            strcpy(a[i+1], a[i]);
            i=i-1;
        }
        strcpy(a[i+1], key);
    }
    free(key);
    return a;
}

int main(){
    int k, i;
    scanf("%d", &k);
    char **s;
    s=malloc(k*sizeof(char*));
    for(i=0;i<k;i++){
        s[i]=malloc(101*sizeof(char));
        scanf("%s", s[i]);
    }

    s=insertion_string(s, k);
    for(i=0;i<k;i++){
        printf("%s\n", s[i]);
    }

    for(i=0;i<k;i++){
        free(s[i]);
    }
    free(s);

    return 0;
}
