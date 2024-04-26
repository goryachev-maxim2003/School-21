#include <math.h>
#include <stdio.h>

double a(double x);
double b(double x);
double c(double x);

int main() {
  double h;
  h = 3.14159265358979323846 * 2 / 41;
  for (double x = -3.14159265358979323846; x < 3.14159265358979323846; x += h) {
    if (isnan(b(x))) {
      printf("%.7lf | %.7lf | - | %.7lf\n", x, a(x), c(x));
    } else {
      printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, a(x), b(x), c(x));
    }
  }
  return 0;
}

double a(double x) { return 1 / (1 + x * x); }
double b(double x) { return pow(pow(1 + 4 * x * x, 0.5) - x * x - 1, 0.5); }
double c(double x) { return 1 / (x * x); }