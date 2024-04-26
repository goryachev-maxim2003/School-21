#include "../tests.h"

START_TEST(calculate_1) {
  double true_result = 4 + 4 / 2;
  ck_assert_int_eq(calculate("4 + 4 / 2", 0) - true_result < EPS, 1);
  true_result = sin(2.3232) * (-34.34343) * (1.34 - (+3433 * (fmod(4, 5)))) +
                log10(-(sin(7 + pow(5.5353, 12))));
  ck_assert_int_eq(calculate("sin(2.3232) * ( - 34.34343) * (1.34 - ( + 3433 * "
                             "(4 mod 5))) + log(-(sin(x + 5.5353 ^ 12)))",
                             7) -
                           true_result <
                       EPS,
                   1);
}
END_TEST

TCase *tests_calculate(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, calculate_1);

  return tcase;
}
