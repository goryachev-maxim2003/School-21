#include "../tests.h"

// conventional test
START_TEST(trim_space_test) {
  char str[] = " ";
  char src[] = "   ah shit, here we go again...   ";
  char expected[] = "ah shit, here we go again...";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_space_dot_test) {
  char str[] = " .";
  char src[] = "   ah shit, here we go again...   ";
  char expected[] = "ah shit, here we go again";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_big_test) {
  char str[] = " .ahshit,";
  char src[] = "   ah shit, now we go again...   ";
  char expected[] = "now we go again";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_all_test) {
  char str[] = " .r";
  char src[] = "       ";
  char expected[] = "";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_null_test1) {
  char *str = s21_NULL;
  char src[] = "    boobs   ";
  char expected[] = "    boobs   ";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_null_test2) {
  char *str = " ./";
  char *src = s21_NULL;
  char *got = s21_trim(src, str);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty_test_1) {
  char *str = "";
  char *src = "buba_gang";
  char expected[] = "buba_gang";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty_test_2) {
  char *str = "buagn";
  char *src = "";
  char expected[] = "";
  char *got = s21_trim(src, str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

TCase *s21_trim_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, trim_space_test);
  tcase_add_test(tcase, trim_space_dot_test);
  tcase_add_test(tcase, trim_big_test);
  tcase_add_test(tcase, trim_all_test);
  tcase_add_test(tcase, trim_null_test1);
  tcase_add_test(tcase, trim_null_test2);
  tcase_add_test(tcase, trim_empty_test_1);
  tcase_add_test(tcase, trim_empty_test_2);

  return tcase;
}