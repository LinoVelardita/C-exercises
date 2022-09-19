#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 30

//Function to be implemented:
void readbinary(char arr[], int *len, int *reps);
int sum1rec(char arr[], int len);
int existSubseq(char arr[], int len, int reps);

int main(){
    char arr[ARR_LEN];
    int len, reps, i;

    //Read and print the array://
    readbinary(arr, &len, &reps);
    printf("Array:\n");
    for(i=0;i<len;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Computes how many 1's are occuring (RECURSIVE)//
    printf("Totale occorrenze di 1: %d\n", sum1rec(arr, len));

    //Computes if a subsequence of exactly nreps 1's exists in the Array//
    if(existSubseq(arr, len, reps))
        printf("Condizione per %d uno contigui: VERA\n", reps);
    else
        printf("Condizione per %d uno contigui: FALSA\n", reps);
    return 0;
}

void readbinary(char arr[], int *len, int *reps){
    int a;
    int count;
    scanf("%d", &a);
    for(count=0;count<ARR_LEN && ( a==0 || a==1 );count++){
        arr[count]=a;
        scanf("%d", &a);
    }
    *reps=a;
    *len=count;
}

int sum1rec(char arr[], int len){
    if(len>0){
        if(arr[len-1]==1){
            return 1 + sum1rec(arr, len-1);
        }
        else{
            return 0 + sum1rec(arr, len-1);
        }
    }
    else{
        return 0;
    }
}

int existSubseq(char arr[], int len, int reps){
    int ctrl=0;
    int i;
    int count=0;
    for(i=0;i<len;i++){
        if(arr[i]==1){
            count++;
        }
        else{
            count=0;
        }
        if(count==reps){
            if(arr[i+1]!=1){
                ctrl=1;
            }
        }
    }
    return ctrl;
}
