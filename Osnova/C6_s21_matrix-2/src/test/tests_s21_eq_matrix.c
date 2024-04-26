#include "../tests.h"

START_TEST(eq_1_test) {
  matrix_t A, B, C, D, E;

  double All[3 * 3 + 2 * 2 * 2 + 2] = {
      1.123,     2.323,       0., 1.123, 2.323, 0., 1.123, 2.323, 0.,

      0.4,       0.12345678,  //На 7ом знаке совпадают
      -0.4,      -0.12345678,

      0.4,       0.12345677,  //На 7ом знаке совпадают
      -0.4,      -0.12345677,

      0.1234567,

      0.1234566};

  int k = 0;
  create_matrix_from_array(&A, All, &k, 3, 3);
  create_matrix_from_array(&B, All, &k, 2, 2);
  create_matrix_from_array(&C, All, &k, 2, 2);
  create_matrix_from_array(&D, All, &k, 1, 1);
  create_matrix_from_array(&E, All, &k, 1, 1);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);  // 3х3 2х2
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);  //одинаковае 2х2 2х2
  ck_assert_int_eq(s21_eq_matrix(&C, &D), FAILURE);  // 2х2 1х1
  ck_assert_int_eq(s21_eq_matrix(&D, &E), FAILURE);  //разные 1х1 1х1
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);  // NULL
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  s21_remove_matrix(&E);
}
END_TEST

TCase *tests_s21_eq_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, eq_1_test);

  return tcase;
}