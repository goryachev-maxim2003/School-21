#include "../tests.h"

// conventional test
START_TEST(insert_test1) {
  char str[] = "Murka";
  char src[] = "I love my cat . She is very nice!";
  s21_size_t index = 14;
  char expected[] = "I love my cat Murka. She is very nice!";
  char *got = s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

// trying to insert empty str
START_TEST(insert_empty) {
  char *str = s21_NULL;
  char src[] = "ah shit, here we go again...";
  s21_size_t index = 1;
  char expected[] = "ah shit, here we go again...";
  char *got = s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

// trying to insert str in empty str
START_TEST(insert_in_empty) {
  char str[] = "You";
  char *src = s21_NULL;
  s21_size_t index = 1;
  char *got = s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

// insert str outside limits of source str
START_TEST(insert_test_out) {
  char str[] = "Mom";
  char src[] = "No way,";
  s21_size_t index = 8;
  char *got = s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

// insert in the end of str
START_TEST(insert_test_critical_end) {
  char str[] = " Mom";
  char src[] = "No way,";
  s21_size_t index = 7;
  char expected[] = "No way, Mom";
  char *got = s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

// insert in the begining of str
START_TEST(insert_test_critical_start) {
  char str[] = "Mom, ";
  char src[] = "No way!";
  s21_size_t index = 0;
  char expected[] = "Mom, No way!";
  char *got = s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Insert Test");
  TCase *tc1_1 = tcase_create("Insert Test");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, insert_test1);
  tcase_add_test(tc1_1, insert_empty);
  tcase_add_test(tc1_1, insert_in_empty);
  tcase_add_test(tc1_1, insert_test_out);
  tcase_add_test(tc1_1, insert_test_critical_end);
  tcase_add_test(tc1_1, insert_test_critical_start);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
TCase *s21_insert_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, insert_test1);
  tcase_add_test(tcase, insert_empty);
  tcase_add_test(tcase, insert_in_empty);
  tcase_add_test(tcase, insert_test_out);
  tcase_add_test(tcase, insert_test_critical_end);
  tcase_add_test(tcase, insert_test_critical_start);

  return tcase;
}