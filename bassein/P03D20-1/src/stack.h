#ifndef STACK_H
#define STACK_H

typedef struct stack1{
    double info;
    struct stack1* next;
} stack;

stack* init(double number);

stack* push(stack* top, double number);

stack* pop(stack* top);

void destroy(stack* top);

void output(stack* top);

#endif