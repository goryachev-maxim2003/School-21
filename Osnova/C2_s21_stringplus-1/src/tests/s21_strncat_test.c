#include "../tests.h"

START_TEST(strncat_test_1) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  ck_assert_str_eq(s21_strncat(dest1, " world", 7),
                   strncat(dest2, " world", 7));
}
END_TEST

START_TEST(strncat_test_2) {
  char dest1[20] = "";
  char dest2[20] = "";
  ck_assert_str_eq(s21_strncat(dest1, "Hello", 4), strncat(dest2, "Hello", 4));
}
END_TEST

START_TEST(strncat_test_3) {
  char dest1[20] = "     ";
  char dest2[20] = "     ";
  ck_assert_str_eq(s21_strncat(dest1, " world", 3),
                   strncat(dest2, " world", 3));
}
END_TEST

START_TEST(strncat_test_4) {
  char dest1[20] = "\0";
  char dest2[20] = "\0";
  ck_assert_str_eq(s21_strncat(dest1, " world", 7),
                   strncat(dest2, " world", 7));
}
END_TEST

START_TEST(strncat_test_5) {
  char dest1[20] = "";
  char dest2[20] = "";
  ck_assert_str_eq(s21_strncat(dest1, "", 1), strncat(dest2, "", 1));
}
END_TEST

START_TEST(strncat_test_6) {
  char dest1[20] = "Hello\n";
  char dest2[20] = "Hello\n";
  ck_assert_str_eq(s21_strncat(dest1, " world", 7),
                   strncat(dest2, " world", 7));
}
END_TEST

START_TEST(strncat_test_7) {
  char dest1[20] = "\n";
  char dest2[20] = "\n";
  ck_assert_str_eq(s21_strncat(dest1, " world", 7),
                   strncat(dest2, " world", 7));
}
END_TEST

START_TEST(strncat_test_8) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  ck_assert_str_eq(s21_strncat(dest1, "", 3), strncat(dest2, "", 3));
}
END_TEST

TCase *s21_strncat_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strncat_test_1);
  tcase_add_test(tcase, strncat_test_2);
  tcase_add_test(tcase, strncat_test_3);
  tcase_add_test(tcase, strncat_test_4);
  tcase_add_test(tcase, strncat_test_5);
  tcase_add_test(tcase, strncat_test_6);
  tcase_add_test(tcase, strncat_test_7);
  tcase_add_test(tcase, strncat_test_8);

  return tcase;
}