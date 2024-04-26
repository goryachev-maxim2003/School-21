#include "../tests.h"

START_TEST(strerror_test_1) {
#ifdef __APPLE__
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }

#elif __linux__
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
#endif
}
END_TEST

START_TEST(strerror_test_2) {
  ck_assert_str_eq(s21_strerror(-100), strerror(-100));
}
END_TEST

START_TEST(strerror_test_3) {
  ck_assert_str_eq(s21_strerror(200), strerror(200));
}
END_TEST


TCase *s21_strerror_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, strerror_test_1);
  tcase_add_test(tcase, strerror_test_2);
  tcase_add_test(tcase, strerror_test_3);

  return tcase;
}