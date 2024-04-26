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

START_TEST(test) {
double a[6][6] = {
      {12., 47., 58., 47., 42., 14.},   {47., 59., 63., 54., 89., 12.},
      {15., 56., -65., -97., 32., 16.}, {58., 75., -24., 45., -16., 8.},
      {78., 93., 17., 13., -11., 7.},   {84., 65., 19., -35., 54., 18.}};
  double b[6][6] = {{-0.01, -0.001, -0.009, 0.006, -0.005, 0.016},
                    {0.0, 0.008, 0.01, -0.007, 0.018, -0.018},
                    {0.009, -0.005, -0.004, -0.014, 0.011, 0.002},
                    {0.001, 0.003, -0.004, 0.012, -0.009, -0.001},
                    {-0.011, 0.017, 0.005, -0.001, -0.004, -0.005},
                    {0.075, -0.067, -0.012, 0.04, -0.061, 0.058}};

  matrix_t A, B;
  int ret;

  ret = s21_create_matrix(6, 6, &A);
  if (ret == 0) {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) {
        A.matrix[i][j] = a[i][j];
      }
    }
    ret = s21_inverse_matrix(&A, &B);
    ck_assert_int_eq(ret, 0);
    ck_assert_int_eq(B.rows, 6);
    ck_assert_int_eq(B.columns, 6);
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) {
        ck_assert_double_eq_tol(B.matrix[i][j], b[i][j], 1.0e-3);
      }
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}
START_TEST(test_02) {
  double a[6][6] = {{1.1, 1.2, 1.3, 1.4, 1.5, 1.6},
                    {2.8, -2.9, -2.3, -2.4, 2.5, 2.7},
                    {3.33, 3.2, -3.87, 3.99, 3.47, -3.02},
                    {4.85, 4.23, 4.32, -4.18, 4.89, 4.23},
                    {5.12, 5.32, 5.28, 5.67, -5.73, 5.91},
                    {6.15, -6.53, 6.44, 6.32, 6.78, 6.98}};
  matrix_t A;
  double dt = -77591.0 - (269266237810933.0 / 3733527061589101.0);
  double result = -1;
  int ret;

  ret = s21_create_matrix(6, 6, &A);
  if (ret == 0) {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) {
        A.matrix[i][j] = a[i][j];
      }
    }
    ret = s21_determinant(&A, &result);
    ck_assert_int_eq(ret, 0);
    ck_assert_double_eq_tol(dt, result, 1.0e-7);
    s21_remove_matrix(&A);
  }
}
END_TEST

TCase *tests_s21_inverse_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, inverse_NULL_test);
  tcase_add_test(tcase, inverse_1_test);
  tcase_add_test(tcase, inverse_2_test);
  tcase_add_test(tcase, inverse_calc_test);
  tcase_add_test(tcase, test);
  tcase_add_test(tcase, test_02);


  return tcase;
}