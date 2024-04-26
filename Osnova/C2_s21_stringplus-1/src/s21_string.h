#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
#define FOR_WIDTH 1
#define FOR_PRECISION 0

typedef long unsigned s21_size_t;

// base
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// special
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// sprintf
typedef struct {
  int minus;
  int plus;
  int space;
  int hash;
  int zero;
  int width;
  int precision;
  char length;  // Длина может быть только одна, не может быть h и l
                // одновременно
  char specifier;
} opt_struct;

int s21_sprintf(char *str, const char *format, ...);
void parcer(int *i, opt_struct *options, const char *format, va_list *vl);

// читает и записывает флаги увеличивая i в парсере
void get_flags(int *i, opt_struct *options, const char *format);

// Считывает число или * для width или precision
void get_width_or_precision(int *i, opt_struct *options, const char *format,
                            va_list *vl, int for_width);

// Читает и возвращает число начиная с позиции i, останавливается на последнем
// символе
int get_int_from_format(int *i, const char *format);

// читает и записывает precision
void get_precision(int *i, opt_struct *options, const char *format,
                   va_list *vl);

// читает и записывает параметры длины
void get_length(int *i, opt_struct *options, const char *format);

// Читает и записывает спецификатор
void get_specifier(int *i, opt_struct *options, const char *format);

// Заменяет спецификаторы значениями
void push_specifier(int *str_i, char *str, opt_struct *options, va_list *vl);

void specifier_c(int *str_i, char *str, va_list *vl);
void specifier_d(int *str_i, char *str, opt_struct *options, va_list *vl);
void specifier_e(int *str_i, char *str, opt_struct *options, int big,
                 long double d);  // Внутри втроен выбор для спецификатора g
void specifier_f(int *str_i, char *str, opt_struct *options, long double d);
void specifier_o(int *str_i, char *str, opt_struct *options, va_list *vl);
void specifier_s(int *str_i, char *str, opt_struct *options, va_list *vl);
void specifier_u(int *str_i, char *str, opt_struct *options, va_list *vl);
void specifier_x(int *str_i, char *str, opt_struct *options, va_list *vl,
                 int big);
void specifier_p(int *str_i, char *str, opt_struct *options, va_list *vl);
void specifier_n(int *str_i, va_list *vl);
void specifier_percent(int *str_i, char *str);

// флаги
void flag_plus_and_space(int *str_i, char *str, opt_struct *options);
void width(int *str_i, char *str, opt_struct *options,
           int persent_index);  // Потдерживает флаг 0
void precision_for_int(int *str_i, char *str, opt_struct *options,
                       int *number_len, int d);
void flag_hash_for_oxX(int *str_i, char *str, opt_struct *options);

void init_arg_with_length(void *var, opt_struct *options, va_list *vl);

void delete_zeros(int *str_i, char *str);  // для флага g

#endif