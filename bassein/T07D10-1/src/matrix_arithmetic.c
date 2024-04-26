#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);

int inputLen(int *n, int *m);

int main() {
    int way, n1, m1, n2, m2;

    if (scanf("%d", &way) == 1 && way >= 1 && way <= 3) {
        int **matr1;
        int flag1 = inputLen(&n1, &m1);
        if (flag1) {
            matr1 = malloc((n1 * m1 * sizeof(int) + n1 * sizeof(int *)));
            int *ptr1 = (int *)(matr1 + n1);
            for (int i = 0; i < n1; i++) matr1[i] = ptr1 + m1 * i;
        } else {
            printf("n/a");
            return 0;
        }
        int **matr2;
        int flag2 = inputLen(&n2, &m2);
        if (flag2) {
            int **matr2 = malloc((n2 * m2 * sizeof(int) + n2 * sizeof(int *)));
            int *ptr2 = (int *)(matr2 + n2);
            for (int i = 0; i < n2; i++) matr2[i] = ptr2 + m2 * i;
        }

        if (flag1) free(matr1);
        if (flag2) free(matr2);
    } else {
        printf("n/a");
    }
    return 0;
}

int inputLen(int *n, int *m) {
    if (scanf("%d%d", n, m) != 2 || *m < 1 || *n < 1) return 0;
    return 1;
}

int input(int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matr[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}