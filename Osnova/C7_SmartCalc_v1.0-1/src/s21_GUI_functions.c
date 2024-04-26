#include "s21_GUI_functions.h"

/**
 * \file
 * \brief Файл содержит функции, которые предназначенны для действий с
 * пользовательским интерфейсом
 */

/**
 * @brief вспомогательная функция для get_last_item_len
 * @param str строка
 * @param substr подстрока
 * @return 1 если в конце нет подстроки, длинну подстроки, если она есть в конце
 */
int strstr_len_in_end(const char *str, const char *substr) {
  int l = strlen(str);
  int sub_l = strlen(substr);
  if (sub_l > l) return 1;  // 1 - значение по умолчанию
  for (int i = 0; i < sub_l; i++)
    if (str[l - i - 1] != substr[sub_l - i - 1]) {
      sub_l = 1;
      break;
    }
  return sub_l;
}

/**
 * @brief Находит длинну последнего элемента в выражении (например, sin( - 4 )
 * (функция используется в интерфейсе для быстрого удаления элементов выражения)
 * @param str строка вырожения
 * @return длинна последнего элемента
 */
int get_last_item_len(const char *str) {
  int ret = 1;
  char *big_operations[19] = {
      "atan(", "asin(", "acos(",        "tan(",   "sin(", "cos(", "sqrt(",
      "ln(",   "log(",  " mod ",        " ^ ",    " / ",  " * ",  " - ",
      " + ",   "nan",   GRAPH_ERR_TEXT, ERR_TEXT, "inf"};
  for (int i = 0; i < 19; i++) {
    if ((ret = strstr_len_in_end(str, big_operations[i])) > 1) break;
  }
  return ret;
}

/**
 * @brief Определяет, считается ли текст сообщением об ошибке
 * (используется в интерфейсе для моментального удаления сообщения при вводе
 * новых символов в строку выражения)
 * @param str строка вырожения
 * @return 1, если является ошибкой, 0, если нет
 */
int is_error(const char *str) {
  return !strcmp(str, ERR_TEXT) || !strcmp(str, "nan") ||
         !strcmp(str, "-inf") || !strcmp(str, "inf") ||
         !strcmp(str, GRAPH_ERR_TEXT);
}

/**
 * @brief преобразует строку в вещественное число
 * @param str строка - вещественное число
 * @param x указатель для записи вещественного числа
 * @return 0, если строка не является числом, 1, если является
 */
int get_x(const char *str, double *x) {
  char c = '\0';
  return sscanf(str, "%lf%c", x, &c) == 1;
}

/**
 * @brief преобразует строку в целое число
 * @param str строка - целое число
 * @param x указатель для записи вещественного числа
 * @return 0, если строка не является числом, 1, если является
 */
int get_int(const char *str, int *n) {
  char c = '\0';
  return sscanf(str, "%d%c", n, &c) == 1;
}