#include "tests.h"

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  suite_add_tcase(suite, tests_validation());
  suite_add_tcase(suite, tests_GUI_functions());
  suite_add_tcase(suite, tests_infix_to_postfix());
  suite_add_tcase(suite, tests_postfix_to_double());
  suite_add_tcase(suite, tests_calculate());
  suite_add_tcase(suite, tests_creditCalc());
  suite_add_tcase(suite, tests_depositCalc());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? 0 : 1;
}
