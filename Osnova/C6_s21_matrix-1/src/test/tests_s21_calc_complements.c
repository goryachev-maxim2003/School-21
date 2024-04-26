#include "../tests.h"

START_TEST(calc_complements_NULL_test) {
  matrix_t res;
  ck_assert_int_eq(s21_calc_complements(NULL, &res), INVALID_MATRIX);
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 1.;
  A.matrix[1][0] = 1.;
  A.matrix[1][1] = 1.;
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INVALID_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_calc_test) {
  matrix_t A, res;
  //Не квадратная
  s21_create_matrix(5, 6, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &res), CALCULATION_ERR);
  s21_remove_matrix(&A);
  // 1х1
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &res), CALCULATION_ERR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_1_test) {
  matrix_t A, B, res;
  double All[3 * 3 * 2] = {1., 2.,  3.,   0., 4.,   2., 5.,  2.,  1.,

                           0., 10., -20., 4., -14., 8., -8., -2., 4.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 3);
  create_matrix_from_array(&B, All, &k, 3, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);
  ck_assert_int_eq(res.rows, 3);
  ck_assert_int_eq(res.columns, 3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

TCase *tests_s21_calc_complements(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, calc_complements_NULL_test);
  tcase_add_test(tcase, calc_complements_calc_test);
  tcase_add_test(tcase, calc_complements_1_test);

  return tcase;
}
