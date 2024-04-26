#include "s21_matrix.h"

int sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int minus) {
  int status = OK;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL)
    status = INVALID_MATRIX;
  else if (A->rows != B->rows ||
           A->columns != B->columns)  //Несоответствие размеров матрицы
    status = CALCULATION_ERR;
  else if (s21_create_matrix(A->rows, A->columns, result) !=
           OK)  //Проверяем, только убедившись, что A и B не NULL
    status = INVALID_MATRIX;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] =
            A->matrix[i][j] + (1 - 2 * minus) * B->matrix[i][j];
  return status;
}

double sum_proizv(int len, double *vec1, double *vec2) {
  double sum = 0;
  for (int i = 0; i < len; i++) sum += vec1[i] * vec2[i];
  return sum;
}

void remove_row_and_culumn(int row, int column, matrix_t *A, matrix_t *result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++)
      result->matrix[i][j] =
          A->matrix[i >= row ? i + 1 : i][j >= column ? j + 1 : j];
}

double algebraic_complement(int row, int column, matrix_t *A) {
  matrix_t smaller_matrix;
  remove_row_and_culumn(row, column, A, &smaller_matrix);
  double det_smaller_matrix;
  s21_determinant(&smaller_matrix, &det_smaller_matrix);
  s21_remove_matrix(&smaller_matrix);
  return (1 - 2 * ((row + column) % 2)) *
         det_smaller_matrix;  //(1 - 2 * ((row + column) % 2)) - это 1 или -1 в
                              //зависимости от четности
}