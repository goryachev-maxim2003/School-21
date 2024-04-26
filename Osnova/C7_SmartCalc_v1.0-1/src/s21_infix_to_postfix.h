#ifndef S21_INFIX_TO_POSTFIX
#define S21_INFIX_TO_POSTFIX

#include <stdlib.h>
#include <string.h>

#include "s21_operations.h"

/**
 * \file
 * \brief Заголовочный файл для s21_infix_to_postfix.c
 */

#define NUMBER_OF_OPERATIONS 17  //+ - и унарные + - - одно и то же

/** @struct operation_struct
 *  @brief Структура для хранения операции
 *  @param value определение операции
 *  @param priority приоритет операции
 */
typedef struct operation_struct {
  char value;
  int priority;
} operation;

/** @struct stack_struct
 *  @brief Стек операций
 *  @param op элемент структуры operation
 *  @param next указатель на следующий элеент стека
 */
typedef struct stack_struct {
  operation op;
  struct stack_struct* next;
} operations_stack;

operation op(char value, int priority);

operations_stack* init(operation op);

void push(operations_stack** stack, operation op);

operation pop(operations_stack** stack);

void destroy(operations_stack* top);

//если оператор - Возвращает char соответствующий оператору, и сдвигает
//указатель на послений символ оператора, иначе '\0'
operation operation_to_struct(const char** p, int unary_conditions);

//Добавлет символ в буффер, двигает i
void buf_append(char* buf, char item, int* i);

//делает либо init либо push опрератора в стек или выталкивает из стека
//операторы если приоритет больше, учет скобок
void push_operator(operation op, operations_stack** stack, char* buf,
                   int* stack_is_init, int* buf_i);

void infix_to_postfix(const char* str, char* buf);

#endif