#include "s21_matrix.h"

void print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%lf ", A->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void create_matrix_from_array(matrix_t *A, double *arr, int *k, int rows,
                              int columns) {
  s21_create_matrix(rows, columns, A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A->matrix[i][j] = arr[*k];
      (*k)++;
    }
}