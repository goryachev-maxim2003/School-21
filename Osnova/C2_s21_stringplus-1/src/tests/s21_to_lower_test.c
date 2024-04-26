#include "../tests.h"

START_TEST(s21_to_lower_normal) {
  char *test_str0 = "HELLO WORLD";
  char *test_str1 = "H1E2L3L4O5";

  char *func_result0 = s21_to_lower(test_str0);
  char *func_result1 = s21_to_lower(test_str1);

  ck_assert_str_eq(func_result0, "hello world");
  ck_assert_str_eq(func_result1, "h1e2l3l4o5");
  if (func_result0) free(func_result0);
  if (func_result1) free(func_result1);
}
END_TEST

START_TEST(s21_to_lower_whith_sign) {
  char *test_str = "K!E1l/l&O.";

  char *func_result = s21_to_lower(test_str);
  ck_assert_str_eq(func_result, "k!e1l/l&o.");
  if (func_result) free(func_result);
}
END_TEST

START_TEST(s21_to_lower_whith_upper) {
  char *test_str = "e_boy";

  char *func_result = s21_to_lower(test_str);
  ck_assert_str_eq(func_result, test_str);
  if (func_result) free(func_result);
}
END_TEST

START_TEST(s21_to_lower_whith_null) {
  char *test_str = s21_NULL;
  char *func_result = s21_to_lower(test_str);
  ck_assert_ptr_null(func_result);
  if (func_result) free(func_result);
}
END_TEST

TCase *s21_to_lower_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, s21_to_lower_normal);
  tcase_add_test(tcase, s21_to_lower_whith_sign);
  tcase_add_test(tcase, s21_to_lower_whith_upper);
  tcase_add_test(tcase, s21_to_lower_whith_null);

  return tcase;
}