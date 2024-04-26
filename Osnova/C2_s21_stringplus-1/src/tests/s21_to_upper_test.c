#include "../tests.h"

START_TEST(s21_to_upper_normal) {
  char *test_str0 = "hello world";
  char *test_str1 = "h1e2l3l4o5";

  char *func_result0 = s21_to_upper(test_str0);
  char *func_result1 = s21_to_upper(test_str1);

  ck_assert_str_eq(func_result0, "HELLO WORLD");
  ck_assert_str_eq(func_result1, "H1E2L3L4O5");
  if (func_result0) free(func_result0);
  if (func_result1) free(func_result1);
}
END_TEST

START_TEST(s21_to_upper_whith_sign) {
  char *test_str = "h!e1l/l&o.";

  char *func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, "H!E1L/L&O.");
  if (func_result) free(func_result);
}
END_TEST

START_TEST(s21_to_upper_whith_upper) {
  char *test_str = "HELLO";

  char *func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, test_str);
  if (func_result) free(func_result);
}
END_TEST

START_TEST(s21_to_upper_whith_null) {
  char *test_str = s21_NULL;
  char *func_result = s21_to_upper(test_str);
  ck_assert_ptr_null(func_result);
  if (func_result) free(func_result);
}
END_TEST

TCase *s21_to_upper_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, s21_to_upper_normal);
  tcase_add_test(tcase, s21_to_upper_whith_sign);
  tcase_add_test(tcase, s21_to_upper_whith_upper);
  tcase_add_test(tcase, s21_to_upper_whith_null);

  return tcase;
}