#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

TCase *tests_s21_create_matrix(void);
TCase *tests_s21_eq_matrix(void);
TCase *tests_s21_sum_matrix(void);
TCase *tests_s21_sub_matrix(void);
TCase *tests_s21_mult_number(void);
TCase *tests_s21_mult_matrix(void);
TCase *tests_s21_transpose(void);
TCase *tests_s21_calc_complements(void);
TCase *tests_s21_determinant(void);
TCase *tests_s21_inverse_matrix(void);

#endif  // SRC_S21_TEST_H_
