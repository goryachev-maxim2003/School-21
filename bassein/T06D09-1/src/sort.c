#include <stdio.h>
#define SIZE 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[SIZE];
    if (input(data)) {
        sort(data);
        output(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a) {
    for (int *p = a; p - a < SIZE; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    return 1;
}

void output(int *a) {
    for (int *p = a; p - a < SIZE; p++) {
        (p - a == 0) ? printf("%d", *p) : printf(" %d", *p);
    }
}

void swap(int *a, int *b) {
    int save_a = *a;
    *a = *b;
    *b = save_a;
}

void sort(int *a) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
            }
        }
    }
}
