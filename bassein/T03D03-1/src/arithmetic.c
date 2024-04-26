#include <stdio.h>

int main() {
    char tmp;
    int x, y, da;
    da = scanf("%d%d%c", &x, &y, &tmp);
    if (da == 3 && tmp == '\n') {
        printf("%d ", x + y);
        printf("%d ", x - y);
        printf("%d ", x * y);
        if (y != 0) {
            printf("%d", x / y);
        } else {
            printf("n/a");
        }
        return 0;
    } else {
        printf("n/a");
    }
}