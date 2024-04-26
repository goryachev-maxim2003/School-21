/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, sum, data[NMAX];
    if (input(data, &n) && (sum = sum_numbers(data, n)) != -1) {
        int numbers[NMAX];
        output(numbers, find_numbers(data, n, sum, numbers), sum);
    } else {
        printf("n/a");
    }

    return 0;
}

//Ввод
int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length > NMAX || *length < 1) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    return 1;
}

//Вывод
void output(int *buffer, int length, int sum) {
    printf("%d\n", sum);
    for (int *p = buffer; p - buffer < length; p++) (p - buffer) == 0 ? printf("%d", *p) : printf(" %d", *p);
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0, no_even = 1;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            no_even = 0;
        }
    }

    return no_even ? -1 : sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int n = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[n] = buffer[i];
            n++;
        }
    }
    return n;
}
