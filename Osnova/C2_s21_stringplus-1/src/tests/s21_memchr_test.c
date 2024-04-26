#include "../tests.h"

START_TEST(memchr_test_1) {
  char dest1[] = "lHeLLo L";
  char sumb = 'L';
  s21_size_t n = s21_strlen(dest1);
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_2) {
  char dest1[] = "lHeLLo L";
  char sumb = 'q';
  s21_size_t n = s21_strlen(dest1);
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_3) {
  char dest1[] = "lHeLLo L";
  char sumb = '\0';
  s21_size_t n = s21_strlen(dest1);
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_4) {
  char dest1[] = "lHeLLo L";
  char sumb = 'L';
  s21_size_t n = 0;
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_5) {
  char dest1[] = "";
  char sumb = '\0';
  s21_size_t n = s21_strlen(dest1);
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_6) {
  char dest1[] = "3123123";
  char sumb = '3';
  s21_size_t n = s21_strlen(dest1);
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, n), memchr(dest1, sumb, n));
}
END_TEST

START_TEST(memchr_test_7) {
  char dest1[] = "hello";
  char sumb = 'o';
  ck_assert_ptr_eq(s21_memchr(dest1, sumb, 3), memchr(dest1, sumb, 3));
}
END_TEST

TCase *s21_memchr_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, memchr_test_1);
  tcase_add_test(tcase, memchr_test_2);
  tcase_add_test(tcase, memchr_test_3);
  tcase_add_test(tcase, memchr_test_4);
  tcase_add_test(tcase, memchr_test_5);
  tcase_add_test(tcase, memchr_test_6);
  tcase_add_test(tcase, memchr_test_7);

  return tcase;
}