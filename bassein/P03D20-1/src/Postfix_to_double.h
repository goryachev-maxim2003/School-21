#ifndef POSTFIX_TO_DOUBLE_H
#define POSTFIX_TO_DOUBLE_H

#define SIN '#'
#define COS '!'
#define TAN '@'
#define CTG '&'
#define LN '?'
#define SQRT '%'

double execute(char op, double first, double second);

int is_binary_operator(char * str);

int is_unary_operator(char * str);

double calc(char *str, double x);

#endif