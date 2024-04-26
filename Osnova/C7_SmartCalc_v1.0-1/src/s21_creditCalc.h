#ifndef S21_CREDIT_CALC
#define S21_CREDIT_CALC

#include <math.h>
#define ANNUITY 0
#define DIFFERENTIATED 1

/**
 * \file
 * \brief Заголовочный файл для s21_creditCalc.c
 */
void creditCalc(double credit_sum, int period, double interest_rate, int type,
                double *monthly_payment_min, double *monthly_payment_max,
                double *overpayment, double *total_payout);

#endif