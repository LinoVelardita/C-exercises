#include <stdio.h>
#include <stdlib.h>

void tagliocorda(int *p, int* r, int* s, int n){
    int i, j;
    int q;
    for(i=1;i<=n;i++){
        q=p[i];
        for(j=2;j<i;j++){
            if(q<p[j]+r[i-j]){
                q=p[j]+r[i-j];
                s[i]=j;
            }
        }
        r[i]=q;
    }
}

void printbest(int* s, int n){
    if(n==0){
        printf("0\n");
    }
    else{
        int t=n;
        while(t>0){
            printf("%d ", s[t]);
            t-=s[t];
        }
        printf("\n");
    }
}

int main(){
    int n;
    int* p;
    int* s;
    int* r;
    int i;
    scanf("%d", &n);
    p=malloc(sizeof(int)*(n+1));
    s=malloc(sizeof(int)*(n+1));
    r=malloc(sizeof(int)*(n+1));
    p[0]=0;
    r[0]=0;
    s[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d", &p[i]);
        r[i]=p[i];
        s[i]=i;
    }

    tagliocorda(p, r, s, n);
    printf("%d\n", r[n]);
    printbest(s, n);

    return 0;
}
