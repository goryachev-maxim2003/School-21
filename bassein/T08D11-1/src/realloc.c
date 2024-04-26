#include <stdio.h>
#include <stdlib.h>

int input(int *a, int index);
void output(int* a, int len);

int main(){
    int ind = 0;
    int * arr = NULL;
    while (input(arr, ind)){
        ind++;
    }
    output(arr, ind);
    free(arr);
    return 0;
}

int input(int *a, int index){
    int el;
    if (scanf("%d",&el)!=1){
        printf("n/a");
        return 0;
    }
    if (el == -1) return 0;
    a = realloc(a, (index+1)*sizeof(int));
    a[index] = el;
    return 1;
}
void output(int* a, int len){
    for (int i = 0; i<len; i++)
        (i==len-1) ? printf("%d",a[i]) : printf("%d ",a[i]);
}
