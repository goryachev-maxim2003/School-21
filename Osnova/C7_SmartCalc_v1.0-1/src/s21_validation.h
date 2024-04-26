#ifndef S21_VALIDATION
#define S21_VALIDATION

#include <stdio.h>
#include <string.h>

/**
 * \file
 * \brief Заголовочный файл для s21_validation.c
 */

#define NOT_OPERATER 0
#define UNARY 1
#define BINARY 2
#define UNARY_AND_BINARY 3
//начинается ли строка с оператора, смещает указатель на последний символ
//оператора, если он есть. возвращает статус оператора
int is_operator(const char** p);

#define OK 0
#define ERROR 1
int validation(const char* str);

#define ERR_TEXT "ERROR"
#define GRAPH_ERR_TEXT "GRAPH_ERROR"

#endif