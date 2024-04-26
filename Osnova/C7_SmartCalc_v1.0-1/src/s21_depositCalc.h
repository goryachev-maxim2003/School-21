#ifndef S21_DEPOSIT_CALC
#define S21_DEPOSIT_CALC

#include <math.h>
#include <stdio.h>
#include <time.h>

#define WITHOUT_CAPITALIZATION 0
#define WITH_CAPITALIZATION 1

typedef enum enumPeriodType {
  MONTHLY,
  ONCE_IN_2_MONTH,
  ONCE_IN_QUARTER,
  ONCE_IN_4_MONTH,
  HALF_YEARLY,
  YEARLY
} PeriodType;

/**
 * \file
 * \brief Заголовочный файл для s21_depositCalc.c
 */

/** @struct addSumStruct
 *  @brief Структура, содержащая информацию для добавленной владельцем вклада
 * суммы
 *  @param month номер месяца с начала кредита в котором было пополнение/снятие
 * (первый месяц = 1)
 *  @param sum сумма пополнения (если > 0) или снятия (если < 0)
 *  @param day_number Номер дня в месяце, в котором было пополнение
 */
typedef struct addSumStruct {
  int month;
  double sum;
  int day_number;  //Номер дня в месяце, в котором было пополнение
} addSum;

void depositCalc(double deposit_sum, int period, double interest_rate,
                 double tax_rate, PeriodType periodicity, int capitalization,
                 double* interest_charges, double* tax_sum, double* end_sum,
                 addSum* arr, int arr_len);

//Возвращает длинну итерации в месяцах
int get_interation_len(PeriodType periodicity);

//Находит соклько дней в периоде и переносить время на этот период, возвращает 0
//когда периуд не в входит в срок депозита, увеличивает счетчик месяцеd
int next_period(time_t* timer, int* days_in_period, double* days_in_year,
                int intaration_len, int period, int* month_counter);

//высчитывает добавленную сумму с учетом процентов за месяц
double get_added_sum(addSum* arr, int arr_len, int month, double interest_rate,
                     int days_in_period, double days_in_year,
                     int intaration_len);

#endif