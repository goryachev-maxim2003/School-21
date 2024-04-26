#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack* init(double number) {
    stack* top = malloc(sizeof(stack));
    top->info = number;
    top->next = NULL;
    return top;
}

stack* push(stack* top, double number) {
    stack* new = malloc(sizeof(stack));
    new->info = number;
    new->next = top;
    return new;
}

stack* pop(stack* top) {
    stack* new_top = top->next;
    free(top);
    return new_top;
}

void destroy(stack* top) {
    while (top != NULL) {
        stack* p = top;
        top = top->next;
        free(p);
    }
}

void output(stack* top){
    while (top != NULL) {
        printf("%lf ", top->info);
        top = top->next;
    }
    printf("\n");
}