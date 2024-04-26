#include "../tests.h"

START_TEST(create_1_test) {
  matrix_t matr;
  ck_assert_int_eq(s21_create_matrix(0, 0, &matr), INVALID_MATRIX);
}
END_TEST

START_TEST(create_2_test) {
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(create_3_test) {
  matrix_t matr;
  ck_assert_int_eq(s21_create_matrix(5, 6, &matr), OK);
  ck_assert_int_eq(matr.rows, 5);
  ck_assert_int_eq(matr.columns, 6);
  s21_remove_matrix(&matr);
}
END_TEST

START_TEST(create_4_test) {
  ck_assert_int_eq(s21_create_matrix(5, 6, NULL), INVALID_MATRIX);
}
END_TEST

TCase *tests_s21_create_matrix(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, create_1_test);
  tcase_add_test(tcase, create_2_test);
  tcase_add_test(tcase, create_3_test);
  tcase_add_test(tcase, create_4_test);
  return tcase;
}
