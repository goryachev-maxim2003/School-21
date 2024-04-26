#include "s21_calculate.h"

/** !
 * \mainpage
 * \author granulem
 * \version 1.0
 * \section intro_sec Calculator_v1.0 was done with
 * 1. C language \n
 * 2. Qt Creator, Qt
 * 3. Qcustomplot
 * 4. Qmake6
 * 5. Doxygen
 * \file
 * \brief Файл содержит реализацию калькулятора, который преобразует
 * инфиксную нотацию в обратную польскую нотацию и затем вычисляет выражение
 */

/**
 * @brief Расчитывает результат вырожения, записанного в инфиксной нотации
 * @param str строка вырожения в инфиксной нотации
 * @param x передаваемый в интерфейсе параметр, который может присутствовать в
 * вырожении
 * @return вещейственный результат вычисления
 */
double calculate(const char *str, double x) {
  char buf[strlen(str) * 2];
  infix_to_postfix(str, buf);
  return postfix_to_double(buf, x);
}