#include "../tests.h"

START_TEST(mult_m_1_test) {
  matrix_t A, B, C, res;

  double All[2 * 2 * 3 + 3 * 2 + 2 * 3 + 3 * 3] = {1.,  2.,  3.,  4.,

                                                   4.,  3.,  -2., -1.,

                                                   0.,  1.,  4.,  5.,

                                                   1.,  4.,  2.,  5.,  3.,  6.,

                                                   1.,  -1., 1.,  2.,  3.,  4.,

                                                   9.,  11., 17., 12., 13., 22.,
                                                   15., 15., 27.};
  //             1 4    1 -1  1    9 11 17
  // C = A × B = 2 5  × 2  3  4 = 12 13 22
  //             3 6              15 15 27
  // test1
  int k = 0;
  create_matrix_from_array(&A, All, &k, 2, 2);
  create_matrix_from_array(&B, All, &k, 2, 2);
  create_matrix_from_array(&C, All, &k, 2, 2);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);

  // test2
  create_matrix_from_array(&A, All, &k, 3, 2);

  create_matrix_from_array(&B, All, &k, 2, 3);
  create_matrix_from_array(&C, All, &k, 3, 3);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);
  // print_matrix(&res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_m_culc_test) {
  matrix_t A, B, res;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(4, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), CALCULATION_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_m_NULL_test) {
  matrix_t A, B, res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1.;
  B.matrix[0][0] = 1.;

  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), INVALID_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

TCase *tests_s21_mult_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, mult_m_1_test);
  tcase_add_test(tcase, mult_m_culc_test);
  tcase_add_test(tcase, mult_m_NULL_test);

  return tcase;
}