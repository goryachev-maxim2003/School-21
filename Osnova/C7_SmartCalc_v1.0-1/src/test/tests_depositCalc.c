#include "../tests.h"

START_TEST(test_depositCalc) {
  double interest_charges;
  double tax_sum;
  double end_sum;
  depositCalc(500000, 9, 50, 13, MONTHLY, WITH_CAPITALIZATION,
              &interest_charges, &tax_sum, &end_sum, NULL, 0);
  ck_assert_int_eq(fabs(interest_charges - 221510.3) < 1, 1);
  ck_assert_int_eq(fabs(tax_sum - 7996.34) < 1, 1);
  ck_assert_int_eq(fabs(end_sum - 721510.3) < 1, 1);
  addSum a = {1, 3000, 2};
  addSum b = {2, 9000, 3};
  addSum c = {1, 4000, 2};

  int k = 3;
  addSum *arr = calloc(k, sizeof(addSum));
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;

  depositCalc(500000, 9, 50, 13, MONTHLY, WITH_CAPITALIZATION,
              &interest_charges, &tax_sum, &end_sum, arr, k);
  ck_assert_int_eq(fabs(interest_charges - 228057.69) < 1, 1);
  ck_assert_int_eq(fabs(end_sum - 744057.69) < 1, 1);

  depositCalc(500000, 9, 50, 13, ONCE_IN_QUARTER, WITH_CAPITALIZATION,
              &interest_charges, &tax_sum, &end_sum, arr, k);
  ck_assert_int_eq(fabs(interest_charges - 218204.6) < 1, 1);
  ck_assert_int_eq(fabs(end_sum - 734204.6) < 1, 1);

  depositCalc(500000, 9, 50, 13, ONCE_IN_QUARTER, WITHOUT_CAPITALIZATION,
              &interest_charges, &tax_sum, &end_sum, arr, k);
  ck_assert_int_eq(fabs(interest_charges - 193113.39) < 1, 1);
  ck_assert_int_eq(fabs(end_sum - 709113.39) < 1, 1);

  free(arr);
}
END_TEST

START_TEST(test_get_interation_len) {
  ck_assert_int_eq(get_interation_len(ONCE_IN_2_MONTH), 2);
  ck_assert_int_eq(get_interation_len(HALF_YEARLY), 6);
  ck_assert_int_eq(get_interation_len(YEARLY), 12);
  ck_assert_int_eq(get_interation_len(ONCE_IN_4_MONTH), 4);
}
END_TEST

TCase *tests_depositCalc(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_depositCalc);
  tcase_add_test(tcase, test_get_interation_len);

  return tcase;
}