#include <stdio.h>
#include <stdlib.h>
#define STATIC_SIZE 100

int input(int *way, int *m, int *n);
void static_output(int m, int n, int matr[m][n]);
int static_input_mas(int m, int n, int matr[m][n]);
void dynamic_output(int m, int n, int **matr);
int dynamic_input_mas(int m, int n, int **matr);
int max(const int *stroka, int n);     //число столбцов(n) - размер строки
int min(int **mas, int m, int stolb);  //число строк(m) - размер столбца
void print_max(int m, int n, int **mas);
void print_min(int m, int n, int **mas);
void static_print_max(int m, int n, int mas[m][n]);
int static_min(int m, int n, int stolb, int mas[m][n]);
void static_print_min(int m, int n, int mas[m][n]);

int main() {
    int way, m, n;

    if (input(&way, &m, &n)) {
        if (way == 1) {
            int matr[m][n];
            if (static_input_mas(m, n, matr)) {
                static_output(m, n, matr);
                static_print_max(m, n, matr);
                static_print_min(m, n, matr);
            } else {
                printf("n/a");
            }
            //Для статич
        } else if (way == 2) {
            int **matr = malloc((m * n * sizeof(int) + m * sizeof(int *)));
            int *ptr = (int *)(matr + m);
            for (int i = 0; i < m; i++) matr[i] = ptr + n * i;
            if (dynamic_input_mas(m, n, matr)) {
                dynamic_output(m, n, matr);
                print_max(m, n, matr);
                print_min(m, n, matr);
            } else {
                printf("n/a");
            };
            free(matr);
        } else if (way == 3) {
            int **matr = malloc(m * sizeof(int *));
            for (int i = 0; i < m; i++) matr[i] = malloc(n * sizeof(int));
            if (dynamic_input_mas(m, n, matr)) {
                dynamic_output(m, n, matr);
                print_max(m, n, matr);
                print_min(m, n, matr);
            } else {
                printf("n/a");
            };
            //Отчистка
            for (int i = 0; i < m; i++) free(matr[i]);
            free(matr);

        } else if (way == 4) {
            int **matr = malloc(m * sizeof(int *));
            int *values = malloc(m * n * sizeof(int));
            for (int i = 0; i < m; i++) matr[i] = values + n * i;
            if (dynamic_input_mas(m, n, matr)) {
                dynamic_output(m, n, matr);
                print_max(m, n, matr);
                print_min(m, n, matr);
            } else {
                printf("n/a");
            };
            //Отчистка
            free(values);
            free(matr);
        }

    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *way, int *m, int *n) {
    if (scanf("%d", way) != 1 || *way < 1 || *way > 4) return 0;
    if (scanf("%d%d", m, n) != 2 || *m < 1 || *n < 1 || (*way == 1 && (*n > 100 || *m > 100))) return 0;
    return 1;
}
void static_output(int m, int n, int matr[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) j == 0 ? printf("%d", matr[i][j]) : printf(" %d", matr[i][j]);
        printf("\n");
    }
}
int static_input_mas(int m, int n, int matr[m][n]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matr[i][j]) != 1) {
                return 0;
            };
        }
    return 1;
}

void dynamic_output(int m, int n, int **matr) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) j == 0 ? printf("%d", matr[i][j]) : printf(" %d", matr[i][j]);
        printf("\n");
    }
}
int dynamic_input_mas(int m, int n, int **matr) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matr[i][j]) != 1) {
                return 0;
            };
        }
    return 1;
}
int max(const int *stroka, int n) {
    int max = stroka[0];
    for (int i = 0; i < n; i++)
        if (stroka[i] > max) {
            max = stroka[i];
        }
    return max;
}
int min(int **mas, int m, int stolb) {
    int minn = mas[0][stolb];

    for (int i = 0; i < m; i++) {
        if (mas[i][stolb] < minn) {
            minn = mas[i][stolb];
        }
    }
    return minn;
}

void print_max(int m, int n, int **mas) {
    for (int i = 0; i < m; i++) i == 0 ? printf("%d", max(mas[i], n)) : printf(" %d", max(mas[i], n));
    printf("\n");
}

void print_min(int m, int n, int **mas) {
    for (int i = 0; i < n; i++) i == 0 ? printf("%d", min(mas, m, i)) : printf(" %d", min(mas, m, i));
}

//Для статики
void static_print_max(int m, int n, int mas[m][n]) {
    for (int i = 0; i < m; i++) i == 0 ? printf("%d", max(mas[i], n)) : printf(" %d", max(mas[i], n));
    printf("\n");
}

int static_min(int m, int n, int stolb, int mas[m][n]) {
    int minn = mas[0][stolb];

    for (int i = 0; i < m; i++) {
        if (mas[i][stolb] < minn) {
            minn = mas[i][stolb];
        }
    }
    return minn;
}

void static_print_min(int m, int n, int mas[m][n]) {
    for (int i = 0; i < n; i++)
        i == 0 ? printf("%d", static_min(m, n, i, mas)) : printf(" %d", static_min(m, n, i, mas));
}
