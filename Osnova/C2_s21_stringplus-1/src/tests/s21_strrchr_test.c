#include "../tests.h"

START_TEST(strrchr_test_1) {
  char dest1[] = "Hello world people";
  ck_assert_str_eq(s21_strrchr(dest1, 'l'), strrchr(dest1, 'l'));
}
END_TEST

START_TEST(strrchr_test_2) {
  char dest1[] = "";
  ck_assert_ptr_null(s21_strrchr(dest1, 'e'));
}
END_TEST

START_TEST(strrchr_test_3) {
  char dest1[] = "3123453123";
  ck_assert_str_eq(s21_strrchr(dest1, '3'), strrchr(dest1, '3'));
}
END_TEST

START_TEST(strrchr_test_4) {
  char dest1[] = "Hello world people\0";
  ck_assert_str_eq(s21_strrchr(dest1, '\0'), strrchr(dest1, '\0'));
}
END_TEST

START_TEST(strrchr_test_5) {
  char dest1[] = "Hello world people";
  ck_assert_ptr_null(s21_strrchr(dest1, 'q'));
}
END_TEST

START_TEST(strrchr_test_6) {
  char dest1[] = "Hello\n world \n";
  ck_assert_str_eq(s21_strrchr(dest1, '\n'), strrchr(dest1, '\n'));
}
END_TEST

START_TEST(strrchr_test_7) {
  char dest1[] = "     ";
  ck_assert_str_eq(s21_strrchr(dest1, ' '), strrchr(dest1, ' '));
}
END_TEST

START_TEST(strrchr_test_8) {
  char dest1[] = "";
  ck_assert_ptr_null(s21_strrchr(dest1, ' '));
}
END_TEST

TCase *s21_strrchr_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strrchr_test_1);
  tcase_add_test(tcase, strrchr_test_2);
  tcase_add_test(tcase, strrchr_test_3);
  tcase_add_test(tcase, strrchr_test_4);
  tcase_add_test(tcase, strrchr_test_5);
  tcase_add_test(tcase, strrchr_test_6);
  tcase_add_test(tcase, strrchr_test_7);
  tcase_add_test(tcase, strrchr_test_8);

  return tcase;
}