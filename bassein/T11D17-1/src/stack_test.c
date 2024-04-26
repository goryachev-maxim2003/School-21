#include "stack.h"

#include <stdio.h>

int main() {
    stack* top = init(1);
    top = push(top, 2);
    (top->info == 2) ? printf("SUCCESS\n") : printf("FAIL\n");
    top = push(top, 4);
    top = pop(top);
    top = push(top, 3);
    // 1 2 3
    (top->next->info == 2) ? printf("SUCCESS\n") : printf("FAIL\n");
    (top->info == 3) ? printf("SUCCESS\n") : printf("FAIL\n");
    top = pop(top);
    (top->info == 2) ? printf("SUCCESS\n") : printf("FAIL\n");
    top = pop(top);
    (top->info == 1) ? printf("SUCCESS\n") : printf("FAIL\n");
    top = pop(top);
    (top == NULL) ? printf("SUCCESS\n") : printf("FAIL\n");

    destroy(top);
    return 0;
}
