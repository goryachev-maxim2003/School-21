#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > 10 || *n < 1) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        (p - a) == 0 ? printf("%d", *p) : printf(" %d", *p);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max;
    max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int min;
    min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) min = *p;
    }
    return min;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) sum += *p;
    return sum / n;
}

double variance(int *a, int n) {
    double sum_of_squares = 0;
    double m = mean(a, n);
    for (int *p = a; p - a < n; p++) sum_of_squares += (*p - m) * (*p - m);
    return sum_of_squares / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
