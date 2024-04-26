#include "../tests.h"

START_TEST(test_creditCalc) {
  double monthly_payment_min;
  double monthly_payment_max;
  double overpayment;
  double total_payout;
  creditCalc(10000, 5, 50, DIFFERENTIATED, &monthly_payment_min,
             &monthly_payment_max, &overpayment, &total_payout);
  ck_assert_int_eq(monthly_payment_min - 2083.33 < 0.01, 1);
  ck_assert_int_eq(monthly_payment_max - 2416.67 < 0.01, 1);
  ck_assert_int_eq(overpayment - 1250 < 0.01, 1);
  ck_assert_int_eq(total_payout - 11250 < 0.01, 1);
  creditCalc(1350354.34, 23, 44.5, DIFFERENTIATED, &monthly_payment_min,
             &monthly_payment_max, &overpayment, &total_payout);
  ck_assert_int_eq(monthly_payment_min - 60888.26 < 0.01, 1);
  ck_assert_int_eq(monthly_payment_max - 108786.70 < 0.01, 1);
  ck_assert_int_eq(overpayment - 600907.68 < 0.01, 1);
  ck_assert_int_eq(total_payout - 1951262.02 < 0.01, 1);
  creditCalc(10000, 5, 50, ANNUITY, &monthly_payment_min, &monthly_payment_max,
             &overpayment, &total_payout);
  ck_assert_int_eq(monthly_payment_min - 2256.8 < 0.01, 1);
  ck_assert_int_eq(monthly_payment_max - 2256.8 < 0.01, 1);
  ck_assert_int_eq(overpayment - 1284 < 0.01, 1);
  ck_assert_int_eq(total_payout - 11284 < 0.01, 1);
  creditCalc(1350354.34, 23, 44.5, ANNUITY, &monthly_payment_min,
             &monthly_payment_max, &overpayment, &total_payout);
  ck_assert_int_eq(monthly_payment_min - 88285.48 < 0.01, 1);
  ck_assert_int_eq(monthly_payment_max - 88285.48 < 0.01, 1);
  ck_assert_int_eq(overpayment - 680211.7 < 0.01, 1);
  ck_assert_int_eq(total_payout - 2030566.04 < 0.01, 1);
}
END_TEST

TCase *tests_creditCalc(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_creditCalc);

  return tcase;
}
