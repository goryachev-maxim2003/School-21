#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INVALID_MATRIX 1
#define CALCULATION_ERR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int minus);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

double sum_proizv(int len, double *vec1, double *vec2);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

void remove_row_and_culumn(int row, int column, matrix_t *A, matrix_t *result);
double algebraic_complement(int row, int column, matrix_t *A);
int s21_determinant(matrix_t *A, double *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// functions for testing
void print_matrix(matrix_t *A);

void create_matrix_from_array(matrix_t *A, double *arr, int *k, int rows,
                              int columns);