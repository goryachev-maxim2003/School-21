#ifndef STACK_H
#define STACK_H

typedef struct stack1{
    int info;
    struct stack1* next;
} stack;

stack* init(int number);

stack* push(stack* top, int number);

stack* pop(stack* top);

void destroy(stack* top);

#endif