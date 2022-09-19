#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n=rand()%11 + 0;  //genera un numero casuale tra 10 e 0
    printf("%d", n);
    return 0;
}
