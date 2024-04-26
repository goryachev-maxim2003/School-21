#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t n = (str == NULL) ? 0 : s21_strlen(str);
  char *str_cpy = (char *)s21_NULL;
  if (str) {
    str_cpy = calloc(n + 1, sizeof(char));
    for (s21_size_t i = 0; i < n; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        str_cpy[i] = str[i] - 32;
      } else {
        str_cpy[i] = str[i];
      }
    }
    str_cpy[n] = '\0';
  }
  return (void *)str_cpy;
}