#include "../tests.h"

START_TEST(memset_test_1) {
  char src[] = "hello world";
  char src1[] = "hello world";
  ck_assert_str_eq(s21_memset(src, 'h', 5), memset(src1, 'h', 5));
}
END_TEST

START_TEST(memset_test_2) {
  char src[] = "hello world";
  char src1[] = "hello world";
  ck_assert_str_eq(s21_memset(src, 'h', s21_strlen(src)),
                   memset(src1, 'h', s21_strlen(src1)));
}
END_TEST

START_TEST(memset_test_3) {
  char src[] = "hello world";
  char src1[] = "hello world";
  ck_assert_str_eq(s21_memset(src, 'h', 1), memset(src1, 'h', 1));
}
END_TEST

START_TEST(memset_test_4) {
  char src[] = "";
  char src1[] = "";
  ck_assert_str_eq(s21_memset(src, 'h', (unsigned int)0),
                   memset(src1, 'h', (unsigned int)0));
}
END_TEST

START_TEST(memset_test_5) {
  char src[] = "hello world";
  char src1[] = "hello world";
  ck_assert_str_eq(s21_memset(src, 'h', (unsigned int)0),
                   memset(src1, 'h', (unsigned int)0));
}
END_TEST

START_TEST(memset_test_6) {
  char src[] = "12345";
  char src1[] = "12345";
  ck_assert_str_eq(s21_memset(src, -1, 5), memset(src1, -1, 5));
}
END_TEST

START_TEST(memset_test_7) {
  char src[] = "12345";
  char src1[] = "12345";
  ck_assert_str_eq(s21_memset(src, 1, 5), memset(src1, 1, 5));
}
END_TEST

START_TEST(memset_test_8) {
  char src[] = "hello\n\0 world";
  char src1[] = "hello\n\0 world";
  ck_assert_str_eq(s21_memset(src, 'h', 10), memset(src1, 'h', 10));
}
END_TEST

TCase *s21_memset_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, memset_test_1);
  tcase_add_test(tcase, memset_test_2);
  tcase_add_test(tcase, memset_test_3);
  tcase_add_test(tcase, memset_test_4);
  tcase_add_test(tcase, memset_test_5);
  tcase_add_test(tcase, memset_test_6);
  tcase_add_test(tcase, memset_test_7);
  tcase_add_test(tcase, memset_test_8);

  return tcase;
}