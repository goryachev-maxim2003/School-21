#include "s21_postfix_to_double.h"

/**
 * \file
 * \brief Файл с реализацией функций для перевода постфиксной нотации в
 * вещественное число при помощи алгоритма вычисления постфиксной записи: \n
 * Проходим постфиксную запись; \n При нахождении числа, парсим его и заносим в
 * стек; \n При нахождении бинарного оператора, берём два последних значения из
 * стека в обратном порядке; \n При нахождении унарного оператора, в данном
 * случае - унарного минуса, берём последнее значение из стека и вычитаем его из
 * нуля, так как унарный минус является правосторонним оператором; \n Последнее
 * значение, после отработки алгоритма, является решением выражения.
 */

/**
 * @brief Инициализация стека чисел (numbers_stack)
 * @param n число
 * @return стек чисел (numbers_stack)
 */
numbers_stack* n_init(double n) {
  numbers_stack* top = malloc(sizeof(numbers_stack));
  top->value = n;
  top->next = NULL;
  return top;
}

/**
 * @brief Добавление числа в стек
 * @param stack указатель на стек чисел (numbers_stack**)
 * @param n число
 */
void n_push(numbers_stack** stack, double n) {
  numbers_stack* new = malloc(sizeof(numbers_stack));
  new->value = n;
  new->next = *stack;
  *stack = new;
}

/**
 * @brief Удаляет верхнее число из стек и возвращает его значнеие
 * @param stack указатель на стек чисел (numbers_stack**)
 * @return число
 */
double n_pop(numbers_stack** stack) {
  numbers_stack* new_top = (*stack)->next;
  double n = (*stack)->value;
  free(*stack);
  *stack = new_top;
  return n;
}

/**
 * @brief Отчищает стек операций
 * @param top стек чисел (numbers_stack*)
 */
void n_destroy(numbers_stack* top) {
  while (top != NULL) {
    numbers_stack* p = top;
    top = top->next;
    free(p);
  }
}

/**
 * @brief определяет является ли операция бинарной
 * @param op операция
 * @return статус операции (BINARY_OP или UNARY_OP)
 */
int operation_status(char op) {
  return (op == MOD || strchr("^/*+-", op)) ? BINARY_OP : UNARY_OP;
}

/**
 * @brief Добавление операции в стек (numbers_stack)
 * @param n число
 * @param stack указатель на стек чисел (numbers_stack**)
 * @param stack_is_init указатель на переменную определяющую, был ли стек уже
 * проинициализирован
 * @param buf_i указатель на переменную - индекс позиции в буффере
 */
void push_number(double n, numbers_stack** stack, int* stack_is_init) {
  if (*stack_is_init)
    n_push(stack, n);
  else {
    *stack = n_init(n);
    *stack_is_init = 1;
  }
}

/**
 * @brief вычисляет результат бинарной опрациями над двумя числами
 * @param op бинарная операция
 * @param n1 1 число
 * @param n2 2 число
 * @return результат операции
 */
double execute_binary(char op, double n1, double n2) {
  // mod ^ / * + -
  double ret = 0;
  switch (op) {
    case MOD:
      ret = fmod(n1, n2);
      break;
    case '^':
      ret = pow(n1, n2);
      break;
    case '/':
      ret = n1 / n2;
      break;
    case '*':
      ret = n1 * n2;
      break;
    case '+':
      ret = n1 + n2;
      break;
    case '-':
      ret = n1 - n2;
      break;
  }
  return ret;
}
/**
 * @brief вычисляет результат унарной опрациями над числом
 * @param op унарная операция
 * @param n число
 * @return результат операции
 */
double execute_unary(char op, double n) {
  // ATAN, ASIN, ACOS, SQRT, TAN, SIN, COS, LN, LOG, UPLUS, UMINUS
  double ret = n;  // UPLUS
  switch (op) {
    case ATAN:
      ret = atan(n);
      break;
    case ASIN:
      ret = asin(n);
      break;
    case ACOS:
      ret = acos(n);
      break;
    case SQRT:
      ret = sqrt(n);
      break;
    case TAN:
      ret = tan(n);
      break;
    case SIN:
      ret = sin(n);
      break;
    case COS:
      ret = cos(n);
      break;
    case LN:
      ret = log(n);
      break;
    case LOG:
      ret = log10(n);
      break;
    case UMINUS:
      ret = -ret;
      break;
  }
  return ret;
}

/**
 * @brief Расчитывает результат выражения в постфиксной записи
 * @param str строка (посфиксная запись)
 * @param x значение параметра x, участвующего в выражении
 * @return результат выражения
 */
double postfix_to_double(const char* str, double x) {
  int stack_is_init = 0;
  double n = 0;  //для чтения числа
  numbers_stack* stack = NULL;
  for (const char* p = str; *p != '\0'; p++) {
    //ПРОВЕРКА
    // printf("символ: %c\nстек:\n", *p);
    // numbers_stack* stack2 = stack;
    // for (; stack2!=NULL; stack2 = stack2->next)
    //     printf("%lf\n", stack2->value);
    // printf("------------\n\n");
    //------------------
    if (*p >= '0' && *p <= '9') {
      sscanf(p, "%lf", &n);
      push_number(n, &stack, &stack_is_init);
      while (*p != ' ') p++;  //смещается до пробела
    } else if (*p == 'x')
      push_number(x, &stack, &stack_is_init);
    else if (operation_status(*p) == UNARY_OP)  //унарный оператор
      n_push(&stack, execute_unary(*p, n_pop(&stack)));
    else  //бинарный оператор
      n_push(&stack,
             execute_binary(*p, n_pop(&stack),
                            n_pop(&stack)));  //Сначало выполняется правый pop,
                                              //а потом левый. Почему?
  }
  double ret = n_pop(&stack);
  n_destroy(stack);
  return ret;
}
