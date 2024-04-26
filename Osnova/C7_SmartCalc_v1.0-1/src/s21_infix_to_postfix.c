#include "s21_infix_to_postfix.h"

/**
 * \file
 * \brief Файл содержит реализацию функций для перевода выражения в инфиксной
 * натации в выражение в постфиксной нотации при помощи алгоритма Дейкстры: \n
 * Проходим исходную строку; \n При нахождении числа, заносим его в выходную
 * строку; \n При нахождении оператора, заносим его в стек; \n Выталкиваем в
 * выходную строку из стека все операторы, имеющие приоритет выше
 * рассматриваемого; \n При нахождении открывающейся скобки, заносим её в стек;
 * \n При нахождении закрывающей скобки, выталкиваем из стека все операторы до
 * открывающейся скобки, а открывающуюся скобку удаляем из стека.
 */

/**
 * @brief создаёт структуру operation на основе параметров
 * @param value определение операции
 * @param priority приоритет операции
 * @return элемент структуры operation
 */
operation op(char value, int priority) {
  operation o = {value, priority};
  return o;
}

/**
 * @brief Инициализация стека операций
 * @param op операция (operation)
 * @return стек операций (operations_stack*)
 */
operations_stack* init(operation op) {
  operations_stack* top = malloc(sizeof(operations_stack));
  top->op = op;
  top->next = NULL;
  return top;
}

/**
 * @brief Добавление операции в стек
 * @param stack указатель на стек операций (operations_stack**)
 * @param opоперация (operation)
 */
void push(operations_stack** stack, operation op) {
  operations_stack* new = malloc(sizeof(operations_stack));
  new->op = op;
  new->next = *stack;
  *stack = new;
}

/**
 * @brief Удаленят и возвращает перхний элемент стека операций
 * @param stack указатель на стек операций (operations_stack**)
 * @return операция (operation)
 */
operation pop(operations_stack** stack) {
  operations_stack* new_top = (*stack)->next;
  operation op = (*stack)->op;
  free(*stack);
  *stack = new_top;
  return op;
}

/**
 * @brief Отчищает стек операций
 * @param top стек операций (operations_stack*)
 */
void destroy(operations_stack* top) {
  while (top != NULL) {
    operations_stack* p = top;
    top = top->next;
    free(p);
  }
}

/**
 * @brief Если c начальной позиции был найден оператор - Возвращает операцию
 * (operation), и сдвигает указатель на послений символ оператора
 * @param p указатель на строку
 * @param unary_conditions переменная, определяющая выполнены ли условия, при
 * которых операции + и - будут унарными
 * @return если был найден оператор - Возвращает операцию (operation), иначе
 * возвращает пустой оператор (op('\0', 0))
 */
operation operation_to_struct(const char** p, int unary_conditions) {
  //- и + отдельно
  char* operations[NUMBER_OF_OPERATIONS] = {
      "atan", "asin", "acos", "sqrt", "tan", "sin", "cos", "mod", "ln",
      "log",  "^",    "(",    ")",    "/",   "*",   "+",   "-"};
  char symbols[NUMBER_OF_OPERATIONS + 2] = {
      ATAN, ASIN, ACOS, SQRT, TAN, SIN, COS, MOD,   LN,    LOG,
      '^',  '(',  ')',  '/',  '*', '+', '-', UPLUS, UMINUS};
  int priotiry[NUMBER_OF_OPERATIONS + 2] = {3, 3, 3, 3, 3, 3, 3, 2, 3, 3,
                                            4, 5, 5, 2, 2, 1, 1, 3, 3};
  operation ret = op('\0', 0);
  for (int i = 0; i < NUMBER_OF_OPERATIONS; i++) {
    if (strstr(*p, operations[i]) == *p) {
      ret = ((**p == '+' || **p == '-') && unary_conditions)
                ? op(symbols[i + 2], priotiry[i + 2])
                : op(symbols[i], priotiry[i]);
      (*p) +=
          strlen(operations[i]) - 1;  //смещение указателя на последний символ
      break;
    }
  }
  return ret;
}

/**
 * @brief Добавление символа в буфер, увеличение индекса
 * @param buf буфер символов
 * @param item символ
 * @param i указатель на переменную - индекс позиции в буффере
 */
void buf_append(char* buf, char item, int* i) {
  buf[*i] = item;
  (*i)++;
}

/**
 * @brief Добавление операции из стека в буфер символов или в стек по алгоритму
 * Дейкстры
 * @param op операция (operation)
 * @param stack указатель на стек операций (operations_stack**)
 * @param buf буфер символов
 * @param stack_is_init указатель на переменную определяющую, был ли стек уже
 * проинициализирован
 * @param buf_i указатель на переменную - индекс позиции в буффере
 */
void push_operator(operation op, operations_stack** stack, char* buf,
                   int* stack_is_init, int* buf_i) {
  if (op.value == ')') {
    //Если ')', выталкиваем все до '(', и удаляем '('
    while ((*stack)->op.value != '(') buf_append(buf, pop(stack).value, buf_i);
    pop(stack);  //удаляем '('
  } else {
    //Пока в стеке что-то есть и приоитет больше - выталкиваем, на '('
    //останавливаемся
    while (*stack != NULL && (*stack)->op.priority > op.priority &&
           (*stack)->op.value != '(')
      buf_append(buf, pop(stack).value, buf_i);

    //добавляем оператор в стек
    if (*stack_is_init)
      push(stack, op);
    else {
      *stack = init(op);
      *stack_is_init = 1;
    }
  }
}

/**
 * @brief запись постфикстной натации в буффер на основе инфиксной нотации
 * @param str строка (инфиксная запись)
 * @param buf буфер (постфиксная запись)
 */
void infix_to_postfix(const char* str, char* buf) {
  int buf_i = 0;
  operation op = {'\0', 0};
  operations_stack* stack = NULL;
  int stack_is_init = 0;
  int unary_conditions = 1;  //в начале строки и после '(': '+' и '-' - унарные
  int was_number = 0;  //для постановки пробела после числа
  for (const char* p = str; *p != '\0'; p++) {
    if (*p == ' ') continue;
    //число или точку сразу в буффер
    if ((*p >= '0' && *p <= '9') || *p == '.' || *p == 'x') {
      buf_append(buf, *p, &buf_i);
      was_number = 1;
    }
    //Оператор в стек
    else if ((op = operation_to_struct(&p, unary_conditions))
                 .priority) {  //приоритет 0 значит, что оператора не существует
      if (was_number) buf_append(buf, ' ', &buf_i);
      was_number = 0;
      push_operator(op, &stack, buf, &stack_is_init, &buf_i);
    }
    unary_conditions = (*p == '(') ? 1 : 0;  //Если была скобка то + и - унарные
  }
  //выталкиваем остатки из стека
  if (was_number) buf_append(buf, ' ', &buf_i);
  while (stack != NULL) buf_append(buf, pop(&stack).value, &buf_i);
  destroy(stack);
  buf_append(buf, '\0', &buf_i);
}