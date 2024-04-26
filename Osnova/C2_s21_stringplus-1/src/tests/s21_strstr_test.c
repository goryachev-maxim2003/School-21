#include "../tests.h"

START_TEST(strstr_test_1) {
  char str1[] = "Hello world people";
  char str2[] = "world";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_2) {
  char str1[] = "Hello world";
  char str2[] = "hello";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_3) {
  char str1[] = "People";
  char str2[] = "Hello";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_4) {
  char str1[] = "Hello";
  char str2[] = "";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_5) {
  char str1[] = "";
  char str2[] = "Hello";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_6) {
  char str1[] = "hello world hello hell people";
  char str2[] = "hell";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_7) {
  char str1[] = "Hello!";
  char str2[] = "Hello!";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_8) {
  char str1[] = "hello Word hello";
  char str2[] = "World";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_9) {
  char str1[] = "hello Word hello World people";
  char str2[] = "World";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_10) {
  char str1[] = "hello  Word hello World people";
  char str2[] = " ";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

TCase *s21_strstr_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strstr_test_1);
  tcase_add_test(tcase, strstr_test_2);
  tcase_add_test(tcase, strstr_test_3);
  tcase_add_test(tcase, strstr_test_4);
  tcase_add_test(tcase, strstr_test_5);
  tcase_add_test(tcase, strstr_test_6);
  tcase_add_test(tcase, strstr_test_7);
  tcase_add_test(tcase, strstr_test_8);
  tcase_add_test(tcase, strstr_test_9);
  tcase_add_test(tcase, strstr_test_10);

  return tcase;
}