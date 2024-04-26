#include "../tests.h"

START_TEST(strtok_test_1) {
  char dest1[] = "Hello world hello";
  char dest2[] = "Hello world hello";
  ck_assert_str_eq(s21_strtok(dest1, " ;"), strtok(dest2, " ;"));
}
END_TEST

START_TEST(strtok_test_2) {
  char dest1[] = "Hello world hello";
  char dest2[] = "Hello world hello";
  ck_assert_str_eq(s21_strtok(dest1, ",."), strtok(dest2, ",."));
}
END_TEST

START_TEST(strtok_test_3) {
  char dest1[] = "Hello world hello";
  char dest2[] = "Hello world hello";
  ck_assert_str_eq(s21_strtok(dest1, " , "), strtok(dest2, " , "));
}
END_TEST

START_TEST(strtok_test_4) {
  char dest1[] = "";
  ck_assert_ptr_null(s21_strtok(dest1, ",. "));
}
END_TEST

START_TEST(strtok_test_5) {
  char dest1[] = "Hello..,, world,  .hello  hell., hello;again.people";
  char dest2[] = "Hello..,, world,  .hello  hell., hello;again.people";
  char *token1 = s21_strtok(dest1, " ,.");
  char *token2 = strtok(dest2, " ,.");
  while (token1 != NULL && token2 != NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, " ,.");
    token2 = strtok(NULL, " ,.");
  }
}
END_TEST

START_TEST(strtok_test_6) {
  char dest1[] = " ";
  ck_assert_ptr_null(s21_strtok(dest1, ",. "));
}
END_TEST

START_TEST(strtok_test_7) {
  char dest1[] = "Hello world ";
  char dest2[] = "Hello world ";
  ck_assert_str_eq(s21_strtok(dest1, " "), strtok(dest2, " "));
}
END_TEST

START_TEST(strtok_test_8) {
  char dest1[] = "//////x//////";
  char dest2[] = "//////x//////";
  ck_assert_str_eq(s21_strtok(dest1, "/"), strtok(dest2, "/"));
}
END_TEST

TCase *s21_strtok_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strtok_test_1);
  tcase_add_test(tcase, strtok_test_2);
  tcase_add_test(tcase, strtok_test_3);
  tcase_add_test(tcase, strtok_test_4);
  tcase_add_test(tcase, strtok_test_5);
  tcase_add_test(tcase, strtok_test_6);
  tcase_add_test(tcase, strtok_test_7);
  tcase_add_test(tcase, strtok_test_8);

  return tcase;
}