#ifndef S21_GUI_FUNCTIONS
#define S21_GUI_FUNCTIONS

#include <stdio.h>
#include <string.h>

#include "s21_validation.h"

/**
 * \file
 * \brief Заголовочный файл для s21_GUI_functions.c
 */

//Сравнивает строки с конца, возвращает длинну substr если совпадает, иначе 1
int strstr_len_in_end(const char *str, const char *substr);
int get_last_item_len(const char *srt);
int is_error(const char *str);
int get_x(const char *str,
          double *x);  // 1 если число, записывает в x, иначе  - 0
int is_number(const char *str);
int get_int(const char *str, int *n);

#endif