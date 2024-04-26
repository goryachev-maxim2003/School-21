#include "../tests.h"

START_TEST(inverse_NULL_test) {
  matrix_t A, B, res;

  A.columns = 1;
  A.rows = 1;
  A.matrix = NULL;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(&B, NULL), INVALID_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &res), INVALID_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_1_test) {
  matrix_t A, B, res;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = -2.;
  B.matrix[0][0] = -0.5;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_2_test) {
  matrix_t A, B, res;
  double All[3 * 3 * 2] = {2., 5.,  7., 6.,   3.,  4.,   5.,  -2,   -3.,

                           1., -1., 1., -38., 41., -34., 27., -29., 24.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 3);
  create_matrix_from_array(&B, All, &k, 3, 3);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);
  ck_assert_int_eq(res.rows, 3);
  ck_assert_int_eq(res.columns, 3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_calc_test) {
  matrix_t A, res;
  s21_create_matrix(5, 6, &A);  //Не квадратная матрица
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CALCULATION_ERR);
  s21_remove_matrix(&A);
}
END_TEST

TCase *tests_s21_inverse_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, inverse_NULL_test);
  tcase_add_test(tcase, inverse_1_test);
  tcase_add_test(tcase, inverse_2_test);
  tcase_add_test(tcase, inverse_calc_test);

  return tcase;
}