#include "tests.h"

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  suite_add_tcase(suite, tests_s21_create_matrix());
  suite_add_tcase(suite, tests_s21_eq_matrix());
  suite_add_tcase(suite, tests_s21_sum_matrix());
  suite_add_tcase(suite, tests_s21_sub_matrix());
  suite_add_tcase(suite, tests_s21_mult_number());
  suite_add_tcase(suite, tests_s21_mult_matrix());
  suite_add_tcase(suite, tests_s21_transpose());
  suite_add_tcase(suite, tests_s21_determinant());
  suite_add_tcase(suite, tests_s21_calc_complements());
  suite_add_tcase(suite, tests_s21_inverse_matrix());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
