// нормальные значения,
// аномальные значения,
// граничные значения и т. д. Д
// ля каждого теста ввод, вывод и результат теста (SUCCESS/FAIL) должны быть выведены
// на стандартный вывод.

#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef Quest_1
    s21_strlen_test();
#endif
#ifdef Quest_2
    s21_strcmp_test();
#endif
#ifdef Quest_3
    s21_strcpy_test();
#endif
#ifdef Quest_4
    s21_strcat_test();
#endif
#ifdef Quest_5
    s21_strchr_test();
#endif
#ifdef Quest_6
    s21_strstr_test();
#endif
    return 0;
}

void s21_strlen_test() {
    (s21_strlen("123456") == 6) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strlen("abs") == 3) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strlen("") == 0) ? printf("SUCCESS") : printf("FAIL");
}

void s21_strcmp_test() {
    (s21_strcmp("123", "12") == 51) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strcmp("123", "125") == -2) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strcmp("12", "125") == -53) ? printf("SUCCESS") : printf("FAIL");
}

void s21_strcpy_test() {
    char str1[10] = "copy me";
    char str2[10];
    char str3[10] = "new text";
    s21_strcpy(str2, str1);
    (s21_strcmp(str1, str2) == 0) ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcpy(str1, str3);
    (str2[7] == 0) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strcmp(str1, str3) == 0) ? printf("SUCCESS") : printf("FAIL");
}

void s21_strcat_test() {
    char str[] = "hello";
    char str2[] = " world";
    char emptystr[] = "";
    s21_strcat(str, str2);
    (s21_strcmp(str, "hello world") == 0) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strcmp(s21_strcat(emptystr, "world"), "world") == 0) ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strcmp(s21_strcat(str, "2"), "hello world2") == 0) ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strchr_test() {
    char str[5] = "ABCDE";
    (*s21_strchr(str, 'C') == 'C') ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strchr(str, 'F') == NULL) ? printf("SUCCESS\n") : printf("FAIL\n");
    (*s21_strchr(str, 'E') == 'E') ? printf("SUCCESS") : printf("FAIL");
}

void s21_strstr_test() {
    char str[5] = "ABCDE";
    (*s21_strstr(str, "CD") == 'C') ? printf("SUCCESS\n") : printf("FAIL\n");
    (s21_strstr(str, "ABE") == NULL) ? printf("SUCCESS\n") : printf("FAIL\n");
    (*s21_strstr(str, "CDE") == 'C') ? printf("SUCCESS") : printf("FAIL");
}