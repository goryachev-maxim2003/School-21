#include "../tests.h"

START_TEST(strpbrk_test_1) {
  char str1[] = "Hello world people";
  char str2[] = "olh ";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_2) {
  char str1[] = "Hello world people";
  char str2[] = "h wdo";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_3) {
  char str1[] = "";
  char str2[] = "Hello world people";
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_4) {
  char str1[] = "Hello world people";
  char str2[] = "";
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_5) {
  char str1[] = "11111111111";
  char str2[] = "11";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_6) {
  char str1[] = "Hello world people 2";
  char str2[] = "zx 2";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_7) {
  char str1[] = "Hello world people";
  char str2[] = "Hello world people";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_8) {
  char str1[] = "e";
  char str2[] = "Hello world people";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

TCase *s21_strpbrk_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strpbrk_test_1);
  tcase_add_test(tcase, strpbrk_test_2);
  tcase_add_test(tcase, strpbrk_test_3);
  tcase_add_test(tcase, strpbrk_test_4);
  tcase_add_test(tcase, strpbrk_test_5);
  tcase_add_test(tcase, strpbrk_test_6);
  tcase_add_test(tcase, strpbrk_test_7);
  tcase_add_test(tcase, strpbrk_test_8);

  return tcase;
}