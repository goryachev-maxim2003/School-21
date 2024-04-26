#include "../tests.h"

START_TEST(mult_number_1_test) {
  matrix_t A, B, C, res;

  double All[2 * 2 * 3] = {1.,   2.,  -1.,  -2.,

                           0.5,  1.,  -0.5, -1.,

                           -0.5, -1., 0.5,  1.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 2, 2);
  create_matrix_from_array(&B, All, &k, 2, 2);
  create_matrix_from_array(&C, All, &k, 2, 2);

  ck_assert_int_eq(s21_mult_number(&A, 0.5, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &B), SUCCESS);
  s21_remove_matrix(&res);
  ck_assert_int_eq(s21_mult_number(&A, -0.5, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);
  s21_remove_matrix(&res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  double All2[3 * 2 * 2] = {-3.,  -2., -1.,  1.,  2., 3.,

                            -1.5, -1., -0.5, 0.5, 1., 1.5};
  k = 0;
  create_matrix_from_array(&A, All2, &k, 2, 3);
  create_matrix_from_array(&B, All2, &k, 2, 3);
  ck_assert_int_eq(s21_mult_number(&A, 0.5, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_NULL_test) {
  matrix_t A, res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.;

  ck_assert_int_eq(s21_mult_number(NULL, 0.5, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_mult_number(&A, 0.5, NULL), INVALID_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

TCase *tests_s21_mult_number(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, mult_number_1_test);
  tcase_add_test(tcase, mult_number_NULL_test);

  return tcase;
}