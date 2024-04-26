#include "s21_validation.h"

/**
 * \file
 * \brief Файл с реализацией функции для проверки валидности строки. Правила
 * проверки: \n 1. Начало - не бинарная операция, не точка, не ')' \n 2. После
 * бинарного оператора или + - может быть (не бинарная операция, не + -, и не
 * точка) //точка учитана в 3 условии \n 3. После точки может быть цифра, перед
 * точкой может быть цифра, точка 1 раз в числе \n 4. После '(' может быть (не
 * бинарная операция, не ')', не точка) //точка учитана в 3 условии \n 5.
 * Количество открыввающихся и закрывающихся скобок одинаковое, ')' не может
 * быть если не было '(' \n 6. после ')' бинарная операция , +-, ')' \n 7. После
 * x: бинарная операция , +-, ')' \n 8. Последним символом может быть только:
 * число, x, ')' \n 9. Послее цифры: цифра '.', ,бинарная операция, +-, ')' \n
 * После унарного оператора обязан быть '(' - выполняется всегда из-за GUI
 */

/**
 * @brief Вычисляет статус оператора, с начальной позиции строки. Если найден
 * опреатор, то указатель смещается на последний симол оператора
 * @param p указатель на строку
 * @return статус оператора (NOT_OPERATER 0 - если в начале оператора нет, UNARY
 * 1 - если найден унарный оператор, BINARY 2 - если найден бинарный оператор,
 * UNARY_AND_BINARY - если найден оператор (+ или -) )
 */
int is_operator(const char** p) {
  char* operations[10] = {"atan", "asin", "acos", "sqrt", "tan",
                          "sin",  "cos",  "mod",  "ln",   "log"};
  int res = NOT_OPERATER;
  for (int i = 0; i < 10; i++) {
    if (strstr(*p, operations[i]) == *p) {
      res = (operations[i][0] == 'm' ? BINARY : UNARY);  // mod - бинарный
      (*p) +=
          strlen(operations[i]) - 1;  //смещение указателя на последний символ
      break;
    }
  }
  if (strchr("+-", **p))
    res = UNARY_AND_BINARY;
  else if (strchr("*/^", **p))
    res = BINARY;
  return res;
}

/**
 * @brief Является ли символ цифрой
 * @param p символ
 * @return 1 - да, 0 - нет
 */
int is_digit(char p) { return p >= '0' && p <= '9'; }

/**
 * @brief Проверяет инфиксную запись на правильность написания
 * @param str строка - выражение в инфиксной нотации
 * @return OK 0 - если в вырожении нет ошибок, иначе ERROR 1
 */
int validation(const char* str) {
  int operator= 0;
  int pre_operator = 0;
  int digit = 0;
  int pre_digit = 0;
  int start_of_string = 1;
  char pre_symbol = '\0';
  int point = 0;  //Когда не цифра и не точка, счетчик обнуляется
  int bracket_balance = 0;
  for (const char* p = str; *p != '\0'; p++) {
    if (*p == ' ') continue;
    operator= is_operator(&p);
    digit = is_digit(*p);
    // 3
    if (*p == '.')
      point++;
    else if (!digit)
      point = 0;
    // 5
    if (*p == '(')
      bracket_balance++;
    else if (*p == ')')
      bracket_balance--;
    // 1
    if (start_of_string) {
      if (operator== BINARY || * p == '.' || * p == ')') return ERROR;
      start_of_string = 0;
    }
    // 2
    else if ((pre_operator == BINARY || pre_operator == UNARY_AND_BINARY) &&
             (operator== BINARY || operator== UNARY_AND_BINARY))
      return ERROR;
    // 3
    else if ((pre_symbol == '.' && !digit) || (*p == '.' && !pre_digit) ||
             point == 2)
      return ERROR;
    // 4
    else if ((pre_symbol == '(' && (operator== BINARY || * p == ')')) ||
             bracket_balance < 0)
      return ERROR;
    // 6 7 9
    else if ((pre_digit || pre_symbol == 'x' || pre_symbol == ')') &&
             operator!= BINARY && operator!= UNARY_AND_BINARY && * p != ')')
      if (!(pre_digit && (*p == '.' || digit))) return ERROR;
    pre_operator = operator;
    pre_digit = digit;
    pre_symbol = *p;
  }
  // 5
  if (bracket_balance != 0) return ERROR;
  // 8
  if (!digit && pre_symbol != 'x' && pre_symbol != ')') return ERROR;
  return OK;
}