#include "data_stat.h"
double max(const double *data, int n) {
    double max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
double min(const double *data, int n) {
    double min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
double mean(const double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    return sum / n;
}
double variance(double *data, int n) {
    double sum_of_squares = 0;
    double m = mean(data, n);
    for (int i = 0; i < n; i++) sum_of_squares += (data[i] - m) * (data[i] - m);
    return sum_of_squares / n;
}