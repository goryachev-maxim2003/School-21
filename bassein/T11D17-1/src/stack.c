#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack* init(int number) {
    stack* top = malloc(sizeof(stack));
    top->info = number;
    top->next = NULL;
    return top;
}

stack* push(stack* top, int number) {
    stack* new = malloc(sizeof(stack));
    new->info = number;
    new->next = top;
    return new;
}

stack* pop(stack* top) {
    stack* p = top;
    free(p);
    return top->next;
}

void destroy(stack* top) {
    while (top != NULL) {
        stack* p = top;
        top = top->next;
        free(p);
    }
}