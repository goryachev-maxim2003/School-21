#include "tests.h"

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

    suite_add_tcase(suite,  s21_insert_test());
    suite_add_tcase(suite,  s21_memchr_test());
    suite_add_tcase(suite,  s21_memcmp_test());
    suite_add_tcase(suite,  s21_memcpy_test());
    suite_add_tcase(suite,  s21_memset_test());
    suite_add_tcase(suite,  s21_sprintf_test());
    suite_add_tcase(suite,  s21_strchr_test());
    suite_add_tcase(suite,  s21_strcspn_test());
    suite_add_tcase(suite,  s21_strerror_test());
    suite_add_tcase(suite,  s21_strlen_test());
    suite_add_tcase(suite,  s21_strncat_test());
    suite_add_tcase(suite,  s21_strncmp_test());
    suite_add_tcase(suite,  s21_strncpy_test());
    suite_add_tcase(suite,  s21_strpbrk_test());
    suite_add_tcase(suite,  s21_strrchr_test());
    suite_add_tcase(suite,  s21_strstr_test());
    suite_add_tcase(suite,  s21_strtok_test());
    suite_add_tcase(suite,  s21_to_lower_test());
    suite_add_tcase(suite,  s21_to_upper_test());
    suite_add_tcase(suite,  s21_trim_test());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}