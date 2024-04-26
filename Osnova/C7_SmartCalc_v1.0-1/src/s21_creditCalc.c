#include "s21_creditCalc.h"

/**
 * \file
 * \brief Файл содержит реализацию кредитного калькулятора
 */

/**
 * @brief Расчитывает минимальный и максимальный ежемесячный платёж, переплату
 * по кредиту, общую выплату по введённым параметрам
 * @param credit_sum сумма кредита
 * @param period срок (в месяцах)
 * @param interest_rate процентная ставка (%)
 * @param type аннуитетный (ANNUITY 0) дифференцированный (DIFFERENTIATED 1)
 * @param monthly_payment_min указатель для записи минимального ежемесячного
 * платежа
 * @param monthly_payment_max указатель для записи максимального ежемесячного
 * платежа
 * @param overpayment указатель для записи переплаты по кредиту
 * @param total_payout указатель для записи общей переплаты
 */
void creditCalc(double credit_sum, int period, double interest_rate, int type,
                double *monthly_payment_min, double *monthly_payment_max,
                double *overpayment, double *total_payout) {
  if (type == DIFFERENTIATED) {
    *monthly_payment_max = 2;
    *overpayment = 0;
    *total_payout = credit_sum;
    double delta = credit_sum / period;
    *monthly_payment_max = delta + credit_sum * interest_rate / 1200;
    *monthly_payment_min = delta + delta * interest_rate / 1200;
    for (; credit_sum > 0; credit_sum -= delta)
      *overpayment += credit_sum * interest_rate / 1200;
    *total_payout += *overpayment;
  } else {  // ANNUITY
    // Sе = S*P /12*(1+P/12)^N/((1+P/12)^N -1)
    double k = 1 + interest_rate / 1200;
    *monthly_payment_min = credit_sum * interest_rate / 1200 * pow(k, period) /
                           (pow(k, period) - 1);
    *monthly_payment_max = *monthly_payment_min;
    *total_payout = *monthly_payment_min * period;
    *overpayment = *total_payout - credit_sum;
  }
}