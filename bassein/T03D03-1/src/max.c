#include <stdio.h>
int max(int x, int y);

int main() {
    char tmp;
    int x, y, da;
    da = scanf("%d%d%c", &x, &y, &tmp);
    if (da == 3 && tmp == '\n') {
        printf("%d", max(x, y));
    } else {
        printf("n/a");
    }
    return 0;
}

int max(int x, int y) {
    int m = x;
    if (y > x) {
        m = y;
    }
    return m;
}
