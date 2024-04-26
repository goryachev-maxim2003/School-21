#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *c);
void output(int *buffer, int length);
void shift(const int *buffer, int *sorted, int length, int c);

int main() {
    int n, data[NMAX], c;
    if (input(data, &n, &c)) {
        int sorted[NMAX];
        shift(data, sorted, n, c);
        output(sorted, n);
    } else {
        printf("n/a");
    }

    return 0;
}

//Ввод
int input(int *buffer, int *length, int *c) {
    if (scanf("%d", length) != 1 || *length > NMAX || *length < 1) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    if (scanf("%d", c) != 1) {
        return 0;
    }
    return 1;
}

//Вывод
void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) (p - buffer) == 0 ? printf("%d", *p) : printf(" %d", *p);
}

//Повернуть элементы массива
void shift(const int *buffer, int *sorted, int length, int c) {
    int k = (c < 0 ? length : 0) + c % length;  //Здвиг вправо на k то же что здвиг влево на length-k
    for (int i = 0; i < length; i++) sorted[(i - k < 0) ? i - k + length : i - k] = buffer[i];
}