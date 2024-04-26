#include "stack.h"
#include "Postfix_to_double.h"
#include <stdio.h>

int main() {
    // stack* top = init(1);
    // top = push(top, 2);
    // top = push(top, 3);
    // top = pop(top);
    // top = pop(top);
    // printf("%d", top->info);
    // top = pop(top);
    //destroy(top);
    //printf("%f", execute('+', 1.23, 3.45));
    
    //char str1[] = "1.5 x * / # ! ~";
    //char str1[] = "1.5 x * 1 2 x + / ?";
    char str1[] = "111 ?";
    
    printf("%lf", calc(str1, 3));
    return 0;
}
