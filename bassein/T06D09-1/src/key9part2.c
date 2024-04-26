#include <stdio.h>

#define LEN 100

int input(int *buffer, int *n);
void output(int *buffer, int length);
void summ(int *buff1, int *buff2, int len, int *result, int *result_length);
void sub(int *buff1, int *buff2, int len, int *result);
void insignificant_zeros(int *a, int *n1, int *b, int *n2);
int sum_symbols(int *pointer, int a, int b, const int *mas);
void sub_symbols(int *pointer, int a, int b, const int *mas);
void shift_and_one(int *mas, int *length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int n1, n2, num1[LEN], num2[LEN], sum_len;
    if (input(num1, &n1) && input(num2, &n2)) {
        int first_more_then_second = 1;
        insignificant_zeros(num1, &n1, num2, &n2);  //Теперь n1==n2
        for (int i = 0; i < n1; i++) {
            if (num1[i] < num2[i]) {
                first_more_then_second = 0;
            } else {
                break;
            }
            printf("%d %d\n", num1[i], num2[i]);
        }

        if (first_more_then_second) {
            int sum[LEN], dif[LEN];
            summ(num1, num2, n1, sum, &sum_len);
            output(sum, sum_len);
            printf("\n");
            sub(num1, num2, n1, dif);
            output(dif, n1);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }

    return 0;
}

//Ввод массива
int input(int *buffer, int *n) {
    char next;
    int first_symbol = 1;
    int k = 0;
    int *p = buffer;
    while (1) {
        if (scanf("%d%c", p, &next) != 2 || *p > 9 || *p < 0) {
            return 0;
        }
        if (*p == 0 && first_symbol) continue;
        first_symbol = 0;
        k++;
        if (next == '\n') {  //Ввести количество массивов
            *n = k;
            break;
        }
        p++;
    }
    return 1;
}

//Вывод
void output(int *buffer, int length) {
    int first_simbol = 1;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p == 0 && first_simbol && (p - buffer) != length - 1) continue;
        first_simbol ? printf("%d", *p) : printf(" %d", *p);
        first_simbol = 0;
    }
}

//Для суммы ---------------------------------------------------------------
//сложить
void summ(int *buff1, int *buff2, int len, int *result, int *result_length) {
    *result_length = len;
    for (int i = 0, k = 0; i < *result_length; i++) {
        if (sum_symbols(result + i, buff1[k], buff2[k], result)) {
            shift_and_one(result, result_length);
            i++;
        }
        k++;
    }
}

//сложить символы
int sum_symbols(int *pointer, int a, int b, const int *mas) {
    *pointer = (a + b) % 10;  //Записываем сумму без десяток
    if (a + b > 9) {
        if ((pointer - 1) < mas) {
            return 1;  //Есть перенос единицы
        } else {
            pointer[-1]++;
        }
    }                                          //Переносим еденицу
    for (int i = 1; pointer[-i] == 10; i++) {  //Переносим еденицы (когда девятки)
        pointer[-i] = 0;
        if ((pointer - i - 1) < mas) {
            return 1;  //Есть перенос единицы
        }
        pointer[-i - 1]++;
    }
    return 0;
}

//Для разности ---------------------------------------------------------------
//Вычесть
void sub(int *buff1, int *buff2, int len, int *result) {
    for (int i = 0; i < len; i++) {
        sub_symbols(result + i, buff1[i], buff2[i], result);
    }
}

//вычесть символы
void sub_symbols(int *pointer, int a, int b, const int *mas) {
    if (a < b) {
        *pointer = 10 + a - b;
        pointer[-1]--;  //забираем единичку
    } else {
        *pointer = a - b;
    }

    //Переносим еденицу
    for (int i = 1; pointer[-i] == -1; i++) {  //Переносим еденицы (когда нули)
        pointer[-i] = 9;
        if ((pointer - i - 1) < mas) {
        }
        pointer[-i - 1]--;
    }
}

//Здвиг вправо + добавить еденицу
void shift_and_one(int *mas, int *length) {
    for (int i = (*length); i >= 0; i--) mas[i + 1] = mas[i];
    (*length)++;
    mas[0] = 1;
}

//Добавить незначущие нули
void insignificant_zeros(int *a, int *n1, int *b, int *n2) {
    int *p, dif_len, min_len;
    if (*n2 > *n1) {
        min_len = *n1;
        dif_len = *n2 - *n1;
        p = a;
        *n1 = *n2;
    } else {
        min_len = *n2;
        dif_len = *n1 - *n2;
        *n2 = *n1;
        p = b;
    }
    for (int i = min_len; i >= 0; i--)  //Здвигаем
        p[i + dif_len] = p[i];

    for (int i = 0; i < dif_len; i++)  //Заполняем нулями
        p[i] = 0;
}
