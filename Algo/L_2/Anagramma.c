#include <stdio.h>
#define DMAX 256

int len(unsigned char *s){
    int i=0;
    while(*(s+i)!=0){
        i++;
    }
    return i;
}


int ctrl_occ(unsigned char a[], unsigned char b[], int dim, int el){
    int i;
    int count=0;
    for(i=0;i<dim;i++){
        if(a[i]==el){
            count++;
        }
    }
    for(i=0;i<dim;i++){
        if(b[i]==el){
            count--;
        }
    }
    if(count==0){
        return 1;
    }
    else return 0;
}

int ctrl_occ2(unsigned char a[], unsigned char b[], int dim){
    int i=0;
    int ok=1;
    while(i<dim && ok){
        if(ctrl_occ(a, b, dim, a[i])!=1){
            ok=0;
        }
        i++;
    }
    return ok;
}

int anagramma(unsigned char *s1, unsigned char *s2){
    if(len(s1)!=len(s2)){
        return 0;
    }
    else{
        unsigned char a1[len(s1)], a2[len(s1)];
        int i=0;
        while(i<len(s1)){
            a1[i]=*(s1+i);
            i++;
        }
        i=0;
        while(i<len(s1)){
            a2[i]=*(s2+i);
            i++;
        }
        return ctrl_occ2(a1, a2, len(s1));
    }
}

int main(){

    unsigned char string1[DMAX], string2[DMAX];
    scanf("%s", string1);
    scanf("%s", string2);
    unsigned char *s1=string1;
    unsigned char *s2=string2;
    printf("%d\n", anagramma(s1, s2));
    return 0;
}
