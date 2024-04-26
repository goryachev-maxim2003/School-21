#include <stdio.h>

int main() {
    char tmp;
    int da;
    float x, y;
    da = scanf("%f%f%c", &x, &y, &tmp);
    if (da == 3 && tmp == '\n') {
        if (x * x + y * y < 25) {
            printf("GOTCHA");
        } else {
            printf("MISS");
        }
    } else {
        printf("n/a");
    }

    return 0;
}