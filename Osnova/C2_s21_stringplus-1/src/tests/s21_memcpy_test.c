#include "../tests.h"

START_TEST(memcpy_test_1) {
  char dest1[6] = "Hello";
  char dest2[6] = "Hello";
  ck_assert_str_eq(s21_memcpy(dest1, "world", 5), memcpy(dest2, "world", 5));
}
END_TEST

START_TEST(memcpy_test_2) {
  char dest1[6] = "";
  char dest2[6] = "";
  ck_assert_str_eq(s21_memcpy(dest1, "world", 5), memcpy(dest2, "world", 5));
}
END_TEST

START_TEST(memcpy_test_3) {
  char dest1[] = "Hello";
  char dest2[] = "Hello";
  ck_assert_str_eq(s21_memcpy(dest1, "world", 0), memcpy(dest2, "world", 0));
}
END_TEST

START_TEST(memcpy_test_4) {
  char dest1[6] = "\0";
  char dest2[6] = "\0";
  ck_assert_str_eq(s21_memcpy(dest1, "world", 5), memcpy(dest2, "world", 5));
}
END_TEST

START_TEST(memcpy_test_5) {
  char dest1[6] = "Hello";
  char dest2[6] = "Hello";
  ck_assert_str_eq(s21_memcpy(dest1, "world", 3), memcpy(dest2, "world", 3));
}
END_TEST

START_TEST(memcpy_test_6) {
  char dest1[] = "";
  char dest2[] = "";
  ck_assert_str_eq(s21_memcpy(dest1, "", 1), memcpy(dest2, "", 1));
}
END_TEST

START_TEST(memcpy_test_7) {
  char dest1[4] = "\n";
  char dest2[4] = "\n";
  ck_assert_str_eq(s21_memcpy(dest1, " world", 3), memcpy(dest2, " world", 3));
}
END_TEST

START_TEST(memcpy_test_8) {
  char dest1[6] = "Hello";
  char dest2[6] = "Hello";
  ck_assert_str_eq(s21_memcpy(dest1, "", 1), memcpy(dest2, "", 1));
}
END_TEST

TCase *s21_memcpy_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, memcpy_test_1);
  tcase_add_test(tcase, memcpy_test_2);
  tcase_add_test(tcase, memcpy_test_3);
  tcase_add_test(tcase, memcpy_test_4);
  tcase_add_test(tcase, memcpy_test_5);
  tcase_add_test(tcase, memcpy_test_6);
  tcase_add_test(tcase, memcpy_test_7);
  tcase_add_test(tcase, memcpy_test_8);

  return tcase;
}