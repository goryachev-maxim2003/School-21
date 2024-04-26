#include "../tests.h"

START_TEST(strcspn_test_1) {
  char str1[] = "Hello world";
  char str2[] = "lxc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_2) {
  char str1[] = "Hello!";
  char str2[] = "h!x";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_3) {
  char str1[] = "";
  char str2[] = "Hello!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_4) {
  char str1[] = "Hello!";
  char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_5) {
  char str1[] = "Hello\0 world";
  char str2[] = "\0 d";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_6) {
  char str1[] = "Hello\n world";
  char str2[] = "\n d";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_7) {
  char str1[] = "Hello!";
  char str2[] = "Hello!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test_8) {
  char str1[] = "o";
  char str2[] = "Hello!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

TCase *s21_strcspn_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strcspn_test_1);
  tcase_add_test(tcase, strcspn_test_2);
  tcase_add_test(tcase, strcspn_test_3);
  tcase_add_test(tcase, strcspn_test_4);
  tcase_add_test(tcase, strcspn_test_5);
  tcase_add_test(tcase, strcspn_test_6);
  tcase_add_test(tcase, strcspn_test_7);
  tcase_add_test(tcase, strcspn_test_8);

  return tcase;
}