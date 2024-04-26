
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Postfix_to_double.h"
#include "stack.h"

double execute(char op, double first, double second){
    double result;
    switch (op)
    {
        case '+':
            result = first+second;
            break;
        case '-':
            result = first-second;  
            break;
        case '*':
            result = first*second;
            break;
        case '/':
            result = first/second;
            break;
        case '~':
            result = -first;
            break;
        case SIN:
            result = sin(first);
            break;
        case COS:
            result = cos(first);
            break;
        case TAN:
            result = tan(first);
            break;
        case CTG:
            result = 1/tan(first);
            break;
        case LN:
            result = log(first);
            break;
        case SQRT:
            result = sqrt(first);
            break;
    }
    return result;
} 

int is_binary_operator(char * str){
    int b = 1;
    char operands[5] = "+-*/";
    if (strlen(str)!=1 || strchr(operands, str[0])==NULL)
        b = 0;
    return b;
}

int is_unary_operator(char * str){
    int b = 1;
    char operands[8] = {'~', SIN, COS, TAN, CTG, LN, SQRT, '\0'};
    if (strlen(str)!=1 || strchr(operands, str[0])==NULL)
        b = 0;
    return b;
}

int is_number(char * str){
    char numbers[10] = "0123456789";
    int b = 1;
    int point_col = 0;
    int len = strlen(str);
    if (len==0 || strchr(numbers, str[0])==NULL){
        b = 0;
    }
    else if(len>1){
        for (int i = 1; i<len; i++){
            if (str[i]=='.')
                point_col++;
            if ((strchr(numbers, str[i])==NULL && str[i]!='.') || point_col>1){
                b = 0;
                break;
            }
            
        }
    }
    return b;
}

double calc(char *str, double x){
    const char sep[2] = " ";
    char * token = strtok(str, sep);
    stack* numbers= NULL;
    int first_number = 1;
    while (token!=NULL){
        if (is_binary_operator(token)){ //Бинарный оператор.
            if (numbers!=NULL && numbers->next!=NULL){ //Если есть 2 числа в стеке
                //Удаляем 2 числа в стеке, добавляем результат операции
                double product = execute(token[0], numbers->next->info, numbers->info);
                numbers = pop(numbers);
                numbers = pop(numbers);
                numbers = push(numbers, product);
            }
        }
        else if(is_unary_operator(token)){ //Унарный оператор
            if (numbers!=NULL){ //Если есть число в стеке
                //Удаляем число в стеке, добавляем результат операции
                double product = execute(token[0], numbers->info,  0);
                numbers = pop(numbers);
                numbers = push(numbers, product);
            }
        }
        else if(is_number(token)){ //Число
            //Добавляем с стек
            numbers = (first_number) ? init(atof(token)) : push(numbers, atof(token)); 
            first_number = 0;
        }
        else if(token[0]=='x' && strlen(token)==1){ //x
            numbers = (first_number) ? init(x) : push(numbers, x); 
            first_number = 0;
        }
        token = strtok(NULL, sep);
    }
    
    
    if (numbers!=NULL) destroy(numbers); //Отчистка
    return numbers->info;
}