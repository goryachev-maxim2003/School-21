#include "../tests.h"

START_TEST(sum_1_test) {
  matrix_t A, B, C, res;

  double All[3 * 3 * 3] = {
      1.123,  2.323,  0.,     1.123, 2.323, 0., 1.123, 2.323, 0.,

      -0.123, -5.323, -1.323, 1.,    1.,    1., 0.,    0.,    0.,

      1.,     -3.,    -1.323, 2.123, 3.323, 1., 1.123, 2.323, 0.};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 3);
  create_matrix_from_array(&B, All, &k, 3, 3);
  create_matrix_from_array(&C, All, &k, 3, 3);
  s21_sum_matrix(&A, &B, &res);
  // print_matrix(&A);
  // print_matrix(&B);
  // print_matrix(&C);
  // print_matrix(&res);
  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);

  double All2[3 * 2 * 3] = {-3., -2., -1., 1., 2., 3.,

                            -3., -2., -1., 1., 2., 3.,

                            -6., -4., -2., 2., 4., 6.};
  k = 0;
  create_matrix_from_array(&A, All2, &k, 2, 3);
  create_matrix_from_array(&B, All2, &k, 2, 3);
  create_matrix_from_array(&C, All2, &k, 2, 3);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_culc_err_test) {
  matrix_t A, B, res;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(1, 1, &B);

  double All[2 * 2 + 1 * 1] = {1.123, 2.323, 1.123, 2.323,

                               1.};

  int k = 0;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = All[k];
      k++;
    }
  B.matrix[0][0] = All[k];
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), CALCULATION_ERR);
  // print_matrix(&A);
  // print_matrix(&B);
  // print_matrix(&C);
  // print_matrix(&res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_null_test) {
  matrix_t A, B, res;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  double All[2 * 2 + 2 * 2] = {
      1.123, 2.323, 1.123, 2.323,

      1.123, 2.323, 1.123, 2.323,
  };

  int k = 0;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = All[k];
      k++;
    }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = All[k];
      k++;
    }
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &res), INVALID_MATRIX);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INVALID_MATRIX);
  // print_matrix(&A);
  // print_matrix(&B);
  // print_matrix(&res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&res);
}
END_TEST

TCase *tests_s21_sum_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, sum_1_test);
  tcase_add_test(tcase, sum_culc_err_test);
  tcase_add_test(tcase, sum_null_test);

  return tcase;
}