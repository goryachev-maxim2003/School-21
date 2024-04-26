/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int first_occurrence(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("%d", first_occurrence(data, n));
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

int first_occurrence(int *a, int n) {
    double m = mean(a, n);
    double sigma = sqrt(variance(a, n));
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= m && *p <= m + 3 * sigma && *p != 0) return *p;
    }
    return 0;
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
