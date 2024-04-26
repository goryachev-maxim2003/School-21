#ifndef S21_POSTFIX_TO_DOUBLE
#define S21_POSTFIX_TO_DOUBLE

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_operations.h"

/**
 * \file
 * \brief Заголовочный файл для s21_postfix_to_double.c
 */

/** @struct numbers_struct
 *  @brief Стек чисел
 *  @param value число
 *  @param numbers_struct указатель на следующий элеент стека
 */
typedef struct numbers_struct {
  double value;
  struct numbers_struct* next;
} numbers_stack;

numbers_stack* n_init(double n);

void n_push(numbers_stack** stack, double n);

double n_pop(numbers_stack** stack);

void n_destroy(numbers_stack* top);

#define UNARY_OP 0
#define BINARY_OP 1
int operation_status(char op);

void push_number(double n, numbers_stack** stack, int* stack_is_init);

double execute_binary(char op, double n1, double n2);
double execute_unary(char op, double n);

double postfix_to_double(const char* str, double x);

#endif