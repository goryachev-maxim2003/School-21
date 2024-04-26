#include <stdio.h>
#include <stdlib.h>

int input(int *a, int length);
void output(int *a, int length);
void sort(int *a, int length);

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
    } else {
        int *data = malloc((n) * sizeof(int));
        if (input(data, n)) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
        free(data);
    }
    return 0;
}

int input(int *a, int length) {
    for (int *p = a; p - a < length; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    return 1;
}

void output(int *a, int length) {
    for (int *p = a; p - a < length; p++) {
        (p - a == 0) ? printf("%d", *p) : printf(" %d", *p);
    }
}

void swap(int *a, int *b) {
    int save_a = *a;
    *a = *b;
    *b = save_a;
}

void sort(int *a, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
            }
        }
    }
}
