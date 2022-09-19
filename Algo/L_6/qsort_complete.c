
//ORDINA INTERI
int compare1(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

//ORDINA CARATTERI
int compare2(const void* a, const void* b){
    char x = *(char*)a;
    char y = *(char*)b;
    return x - y;
}

//ORDINA STRINGHE
int compare3(const void* a, const void* b){
    char* x = *(char**)a;
    char* y = *(char**)b;
    return strcmp(x, y);
}

//ORDINA STRUCT
int compare4(const void* a, const void* b){
    block x = *(block*)a;
    block y = *(block*)b;
    return x.el - y.el;
}

qsort(array, dim_array, sizeof(int), compare1);
qsort(array, dim_array, sizeof(char), compare2);
qsort(array, dim_array, sizeof(char*), compare3);
qsort(array, dim_array, sizeof(block), compare4);
