#include "../tests.h"

START_TEST(strchr_test_1) {
  char dest1[] = "lHeLLo L";
  ck_assert_str_eq(s21_strchr(dest1, 'L'), strchr(dest1, 'L'));
}
END_TEST

START_TEST(strchr_test_2) {
  char dest1[] = "";
  ck_assert_ptr_null(s21_strchr(dest1, 'e'));
}
END_TEST

START_TEST(strchr_test_3) {
  char dest1[] = "123453";
  ck_assert_str_eq(s21_strchr(dest1, '3'), strchr(dest1, '3'));
}
END_TEST

START_TEST(strchr_test_4) {
  char dest1[] = "\0";
  ck_assert_str_eq(s21_strchr(dest1, '\0'), strchr(dest1, '\0'));
}
END_TEST

START_TEST(strchr_test_5) {
  char dest1[] = "Hello";
  ck_assert_ptr_null(s21_strchr(dest1, 'q'));
}
END_TEST

START_TEST(strchr_test_6) {
  char dest1[] = "Hello\n";
  ck_assert_str_eq(s21_strchr(dest1, '\n'), strchr(dest1, '\n'));
}
END_TEST

START_TEST(strchr_test_7) {
  char dest1[] = "     ";
  ck_assert_str_eq(s21_strchr(dest1, ' '), strchr(dest1, ' '));
}
END_TEST

TCase *s21_strchr_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strchr_test_1);
  tcase_add_test(tcase, strchr_test_2);
  tcase_add_test(tcase, strchr_test_3);
  tcase_add_test(tcase, strchr_test_4);
  tcase_add_test(tcase, strchr_test_5);
  tcase_add_test(tcase, strchr_test_6);
  tcase_add_test(tcase, strchr_test_7);

  return tcase;
}