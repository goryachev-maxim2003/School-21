#include <math.h>
#include <stdio.h>
int f(int n);

int main() {
  char tmp;
  int da, n;
  da = scanf("%d%c", &n, &tmp);
  if (da != 2 || tmp != '\n' || n < 0) {
    printf("n/a");
    return 0;
  }

  printf("%d", f(n));
  return 0;
}

int f(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return f(n - 1) + f(n - 2);
  }
}