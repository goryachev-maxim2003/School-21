#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (result == NULL || rows < 1 ||
      columns < 1) {  //Неверны размер матрицы или указатель
    status = INVALID_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    if ((result->matrix = malloc(rows * sizeof(double *) +
                                 rows * columns * sizeof(double))) ==
        NULL)  //Нехватка памяти
      status = INVALID_MATRIX;
    else {  //Заполнение матрицы
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;
    }
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) free(A->matrix);
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL)
    res = FAILURE;
  else if (A->columns != B->columns || A->rows != B->rows)
    res = FAILURE;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >=
            1e-7) {  //Сравнение до 7ого знака
          res = FAILURE;
          break;
        }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return sum_or_sub_matrix(A, B, result, 0);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return sum_or_sub_matrix(A, B, result, 1);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (A == NULL || A->matrix == NULL)
    status = INVALID_MATRIX;
  else if (s21_create_matrix(A->rows, A->columns, result) !=
           OK)  //Проверяем, только убедившись, что A не NULL
    status = INVALID_MATRIX;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL)
    status = INVALID_MATRIX;
  else if (A->columns !=
           B->rows)  //Матрицы нельзя умножить  правильно: AxB * B*C = AxC
    status = CALCULATION_ERR;
  else if (s21_create_matrix(A->rows, B->columns, result) !=
           OK)  //Проверяем, только убедившись, что A и B не NULL
    status = INVALID_MATRIX;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++) {
        double B_column[A->columns];  // j-й столбец матрицы B
        for (int k = 0; k < A->columns; k++) B_column[k] = B->matrix[k][j];
        result->matrix[i][j] = sum_proizv(A->columns, A->matrix[i], B_column);
      }
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (A == NULL || A->matrix == NULL)
    status = INVALID_MATRIX;
  else if (s21_create_matrix(A->columns, A->rows, result) !=
           OK)  //Проверяем, только убедившись, что A и B не NULL
    status = INVALID_MATRIX;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  return status;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (A == NULL || A->matrix == NULL || result == NULL)
    status = INVALID_MATRIX;
  else if (A->rows != A->columns)  //Матрица не квадратная
    status = CALCULATION_ERR;
  else if (A->rows == 1)
    *result = A->matrix[0][0];
  else {
    double sum = 0;
    for (int i = 0; i < A->columns;
         i++)  //Сумма произведений значений строки (берём первую) на
               //алгеброические дополнения
      sum += algebraic_complement(0, i, A) * A->matrix[0][i];
    *result = sum;
  }
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (A == NULL || A->matrix == NULL)
    status = INVALID_MATRIX;
  else if (A->rows != A->columns ||
           A->rows <= 1)  //Матрица не квадратная или из одного элемента
    status = CALCULATION_ERR;
  else if (s21_create_matrix(A->columns, A->rows, result) !=
           OK)  //Проверяем, только убедившись, что A и B не NULL
    status = INVALID_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = algebraic_complement(i, j, A);
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  double det;
  if ((status = s21_determinant(A, &det)) == OK &&
      det != 0.) {  //Проверка на NULL A, и квадратную матрицу внутри
                    // s21_determinant.
    if (s21_create_matrix(A->columns, A->rows, result) !=
        OK)  //Проверяем, только убедившись, что A не NULL
      status = INVALID_MATRIX;
    else if (A->rows == 1)  //Отделяeм этот случай, так как нельзя посчитать
                            //матрицу алгебраических дополнений
      result->matrix[0][0] = 1. / A->matrix[0][0];
    else {
      s21_remove_matrix(result);  //Матрица создается в s21_mult_number
      matrix_t m_algebraic_complement;
      matrix_t m_algebraic_complement_T;

      s21_calc_complements(A, &m_algebraic_complement);
      s21_transpose(&m_algebraic_complement, &m_algebraic_complement_T);
      s21_mult_number(&m_algebraic_complement_T, 1. / det, result);

      s21_remove_matrix(&m_algebraic_complement);
      s21_remove_matrix(&m_algebraic_complement_T);
    }
  }
  return status;
}