#include "../tests.h"

START_TEST(determinant_1_test) {
  matrix_t A;
  double res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = -2.345;
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, -2.345);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_NULL_test) {
  double res;
  ck_assert_int_eq(s21_determinant(NULL, &res), INVALID_MATRIX);
}
END_TEST

START_TEST(determinant_calc_test) {
  matrix_t A;
  s21_create_matrix(5, 6, &A);
  double res;
  ck_assert_int_eq(s21_determinant(&A, &res), CALCULATION_ERR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2_test) {
  matrix_t A;
  double res;
  double All[16] = {100., 2.,  3.,  4.,  5.,  6.,  7.,  8.,
                    9.,   10., 11., 12., 13., 14., 15., 17.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 4, 4);
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, -396.);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3_test) {
  matrix_t A;
  double res;
  double All[16] = {1., 2., 3., 4., 5., 6., 7., 8., 9.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, 0.);
  s21_remove_matrix(&A);
}
END_TEST
TCase *tests_s21_determinant(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, determinant_1_test);
  tcase_add_test(tcase, determinant_NULL_test);
  tcase_add_test(tcase, determinant_calc_test);
  tcase_add_test(tcase, determinant_2_test);
  tcase_add_test(tcase, determinant_3_test);

  return tcase;
}