#include <math.h>
#include <stdio.h>

int ost(int a, int b);
int is_simple(int a);
int div(int a, int b);
int maxd(int x);

int main() {
  char tmp;
  int x, da;
  da = scanf("%d%c", &x, &tmp);
  if (da == 2 && tmp == '\n') {
    if (x < 0) {
      x = -x;
    }
    printf("%d\n", maxd(x));
  } else {
    printf("n/a");
  }

  return 0;
}

int ost(int a, int b) {
  if (b == 0) {
    return -1;
  }
  while (a >= b) {
    a -= b;
  }
  return a;
}

int div(int a, int b) { //Деление нацело
  if (b == 0) {
    return -1;
  }
  int k = 0;
  while (a >= b) {
    a -= b;
    k++;
  }
  return k;
}

int is_simple(int a) { //Число простое?
  for (int i = 2; i <= (int)pow(a, 0.5); i++) {
    if (ost(a, i) == 0) {
      return 0;
    }
  }
  return 1;
}

int maxd(int x) { //Максимальный делитель
  int max = 1;
  for (int i = 1; i <= (int)pow(x, 0.5); i++) {
    if (ost(x, i) == 0) { //Если i - делитель
      if (is_simple(i)) {
        max = i;
      }
      if (is_simple(div(x, i))) {
        max = div(x, i);
        return max;
      }
    }
  }
  return max;
}
