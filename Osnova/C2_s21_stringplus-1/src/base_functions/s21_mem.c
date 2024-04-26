#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *s = (const char *)str;
  int flag = 1;

  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == c) {
      s = (void *)&s[i];  // Оператор « & » определяет адрес переменной, а
                          // оператор « * » разыменования позволяет получить
                          // значение по адресу, указанным указателем.
      flag = 0;
      break;
    }
  }
  if (flag) s = s21_NULL;
  return (void *)s;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *cstr1 = (const unsigned char *)str1;
  const unsigned char *cstr2 = (const unsigned char *)str2;
  int result = 0;
  s21_size_t i = 0;
  while (i < n) {
    if (cstr1[i] < cstr2[i] || cstr1[i] > cstr2[i]) {
      result = cstr1[i] - cstr2[i];
    }
    if (result != 0) {
      break;
    }
    i++;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *source = (unsigned char *)src;
  unsigned char *destination = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    destination[i] = source[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *strr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    strr[i] = (unsigned int)c;
  }
  return str;
}