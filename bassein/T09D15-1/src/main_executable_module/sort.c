#include "sort.h"

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data + j, data + j + 1);
            }
        }
    }
}

void swap(double *a, double *b) {
    double save_a = *a;
    *a = *b;
    *b = save_a;
}
