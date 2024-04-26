#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = (char *)s21_NULL;
  s21_size_t src_length = (src == NULL) ? 0 : s21_strlen(src);
  s21_size_t str_length = (str == NULL) ? 0 : s21_strlen(str);
  s21_size_t res_length = src_length + str_length;

  if (src != s21_NULL &&
      start_index <= src_length) {  // если строка непустая и ее длина больше
                                    // стартового индекса
    result = calloc(res_length + 1, sizeof(char));  // пробуем выделить память
    if (result != s21_NULL) {
      if (str == s21_NULL)
        s21_strncpy(result, src, src_length);
      else {
        s21_strncpy(result, src, start_index);
        result = result + start_index;
        src = src + start_index;
        s21_strncpy(result, str, str_length);
        result = result + str_length;
        s21_strncpy(result, src, src_length - start_index);
        result = result - str_length - start_index;
      }
    }
  }
  return result;
}