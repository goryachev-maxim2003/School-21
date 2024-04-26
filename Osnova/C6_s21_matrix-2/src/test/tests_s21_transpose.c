#include "../tests.h"

START_TEST(transpose_1_test) {
  matrix_t A, B, res;
  double All[2 * 3 * 2] = {1., 4., 2., 5., 3., 6,

                           1., 2., 3., 4., 5., 6.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 2);
  create_matrix_from_array(&B, All, &k, 2, 3);
  ck_assert_int_eq(s21_transpose(&A, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_NULL_test) {
  matrix_t A, B, res;

  A.columns = 1;
  A.rows = 1;
  A.matrix = NULL;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.;
  ck_assert_int_eq(s21_transpose(&A, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_transpose(&B, NULL), INVALID_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

TCase *tests_s21_transpose(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, transpose_1_test);
  tcase_add_test(tcase, transpose_NULL_test);

  return tcase;
}