#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include <check.h>

#include "s21_GUI_functions.h"
#include "s21_calculate.h"
#include "s21_creditCalc.h"
#include "s21_depositCalc.h"
#include "s21_infix_to_postfix.h"
#include "s21_postfix_to_double.h"
#include "s21_validation.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

#define EPS 0.000001

TCase *tests_validation(void);
TCase *tests_GUI_functions(void);
TCase *tests_infix_to_postfix(void);
TCase *tests_postfix_to_double(void);
TCase *tests_calculate(void);
TCase *tests_creditCalc(void);
TCase *tests_depositCalc(void);

#endif
