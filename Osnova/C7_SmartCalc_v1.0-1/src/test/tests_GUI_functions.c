#include "../tests.h"

START_TEST(GUI_get_last_item_len) {
  ck_assert_int_eq(get_last_item_len("1 ^ "), 3);
  ck_assert_int_eq(get_last_item_len("log(7) *"), 1);
  ck_assert_int_eq(get_last_item_len("log(7)"), 1);
  ck_assert_int_eq(get_last_item_len("log(7"), 1);
  ck_assert_int_eq(get_last_item_len("log("), 4);
  ck_assert_int_eq(get_last_item_len("log("), 4);
  ck_assert_int_eq(get_last_item_len("sin(x)+asin("), 5);
  ck_assert_int_eq(get_last_item_len("sin(x) mod "), 5);
}
END_TEST

START_TEST(is_error_test) {
  ck_assert_int_eq(is_error(ERR_TEXT), 1);
  ck_assert_int_eq(is_error("ERROR"), 1);
  ck_assert_int_eq(is_error("ERRORR"), 0);
}
END_TEST

START_TEST(test_get_x) {
  double x = 0;
  ck_assert_int_eq(get_x("123.12456", &x), 1);
  ck_assert_double_eq(x, 123.12456);
  ck_assert_int_eq(get_x("12.3213asds", &x), 0);
  ck_assert_int_eq(get_x("asd12.3213", &x), 0);
  ck_assert_int_eq(get_x("1.", &x), 1);
  ck_assert_double_eq(x, 1);
  ck_assert_int_eq(get_x("1..", &x), 0);
}
END_TEST

START_TEST(test_get_int) {
  int x = 0;
  ck_assert_int_eq(get_int("123", &x), 1);
  ck_assert_int_eq(x, 123);
  ck_assert_int_eq(get_int("12.3213", &x), 0);
}
END_TEST

TCase *tests_GUI_functions(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, GUI_get_last_item_len);
  tcase_add_test(tcase, is_error_test);
  tcase_add_test(tcase, test_get_x);
  tcase_add_test(tcase, test_get_int);

  return tcase;
}
