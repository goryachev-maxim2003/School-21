#include "s21_depositCalc.h"

/**
 * \file
 * \brief Файл содержит реализацию депозитного калькулятора
 */

/**
 * @brief Расчитывает начисленные проценты, сумму налога и сумму на вкладе к
 * концу срока на депозите по введённым параметрам
 * @param deposit_sum сумма депозита
 * @param period срок депозита (в месяцах)
 * @param interest_rate процентная ставка (%)
 * @param tax_rate налоговая ставка (%)
 * @param periodicity периодичность выплат по депозиту (MONTHLY,
 * ONCE_IN_2_MONTH, ONCE_IN_QUARTER,ONCE_IN_4_MONTH, HALF_YEARLY, YEARLY)
 * @param capitalization Наличие капитализации (WITHOUT_CAPITALIZATION 0,
 * WITH_CAPITALIZATION 1)
 * @param interest_charges указатель для записи начисленных процентов
 * @param tax_sum указатель для записи суммы налога
 * @param end_sum указатель для записи суммы на вкладе к концу срока
 * @param arr массив структур(addSum) с информацией о пополнениях и снятиях с
 * вклада
 * @param arr_len длинна массива структур
 */
void depositCalc(double deposit_sum, int period, double interest_rate,
                 double tax_rate, PeriodType periodicity, int capitalization,
                 double* interest_charges, double* tax_sum, double* end_sum,
                 addSum* arr, int arr_len) {
  time_t timer = time(NULL);
  int start_sum = deposit_sum;
  double days_in_year = 365;
  int days_in_period = 30;
  int intaration_len = (capitalization == WITH_CAPITALIZATION)
                           ? get_interation_len(periodicity)
                           : period;
  int month_counter = 0;
  interest_rate /= 100;  //Перевод % в число
  while (next_period(&timer, &days_in_period, &days_in_year, intaration_len,
                     period, &month_counter)) {
    //Пополнение депозита
    deposit_sum += deposit_sum * interest_rate * days_in_period / days_in_year;
    deposit_sum += get_added_sum(arr, arr_len, month_counter, interest_rate,
                                 days_in_period, days_in_year, intaration_len);
    //Огругление до сотых
    deposit_sum = round(deposit_sum * 100) / 100;
    // printf("days_in_period %d days_in_year %lf month_counter %d sum %lf\n",
    // days_in_period, days_in_year, month_counter, deposit_sum);
  }
  // printf("%lf", sum_add_sum);
  *interest_charges = deposit_sum - start_sum;
  *tax_sum = (*interest_charges > 160000)
                 ? round((*interest_charges - 160000) * tax_rate / 100)
                 : 0;
  *end_sum = deposit_sum;

  //Удаляем из даходов положенные нами деньги
  for (int i = 0; i < arr_len; i++) (*interest_charges) -= arr[i].sum;
}

/**
 * @brief Вычисляет длинну одного периода в месяцах по периодичности
 * @param periodicity периодичность выплат по депозиту (MONTHLY,
 * ONCE_IN_2_MONTH, ONCE_IN_QUARTER,ONCE_IN_4_MONTH, HALF_YEARLY, YEARLY)
 * @return длинна одного периода
 */
int get_interation_len(PeriodType periodicity) {
  int ret = -1;
  if (periodicity == MONTHLY)
    ret = 1;
  else if (periodicity == ONCE_IN_2_MONTH)
    ret = 2;
  else if (periodicity == ONCE_IN_QUARTER)
    ret = 3;
  else if (periodicity == ONCE_IN_4_MONTH)
    ret = 4;
  else if (periodicity == HALF_YEARLY)
    ret = 6;
  else if (periodicity == YEARLY)
    ret = 12;
  return ret;
}
/**
 * @brief Находит  сколько дней в году, соклько дней в периоде и переносит время
 * на этот период, увеличивает счетчик месяцев
 * @param timer указатель на переменную времени. Переменная увеличивается на
 * период по завершению функции
 * @param days_in_period указатель для записи дней в текущем периоде
 * @param days_in_year указатель для записи количества дней в году
 * @param intaration_len длинна периода (в месяцах)
 * @param period срок депозита (в месяцах)
 * @param month_counter указатель на счётчик месяцев. В процессе выполнения
 * функции счетчик увеличивается на период
 * @return возвращает 0, если период вышел за срок депозита, иначе 1
 */
int next_period(time_t* timer, int* days_in_period, double* days_in_year,
                int intaration_len, int period, int* month_counter) {
  struct tm* t_tm = localtime(timer);
  *days_in_year =
      t_tm->tm_year % 4 == 0
          ? 366
          : 365;  //Может наступить новый год, поэтому каждый раз пересчитываем
  // if (t_tm->tm_year % 4 == 0 && t_tm->tm_mon == 11) *days_in_year =
  // 365.386071; //!!!!!!!!!!!!!!!!!!!!!Граница високосного и невисокосного
  // года? Почему так???
  int days_counter =
      t_tm->tm_mday;  //при расчете депозита учитывается количество дней месяца
                      //с которого начался депозит
  int pre_month_number = t_tm->tm_mon;
  int start_month_counter = *month_counter;
  //Движемся по месяцам пока их количество < длинны итерации и пока время не
  //зайдёт за границу конца срока
  while (*month_counter - start_month_counter < intaration_len &&
         *month_counter <= period) {
    //изменяем на день пока не наступит новый месяц
    while (pre_month_number == t_tm->tm_mon) {
      *timer += 60 * 60 * 24;  //Смещение ремени на день
      t_tm = localtime(timer);
      days_counter++;
    }
    (*month_counter)++;
    pre_month_number = t_tm->tm_mon;
  }
  days_counter--;  //При несовпадающем месяце прибавился лишний день
  *days_in_period = days_counter;
  return (*month_counter <= period);
}

/**
 * @brief высчитывает добавленную владельцем вклада сумму с учетом процентов за
 * месяц
 * @param arr массив структур(addSum) с информацией о пополнениях и снятиях с
 * вклада
 * @param arr_len длинна массива структур
 * @param month номер месяца с начала кредита (первый месяц = 1)
 * @return добавленная владельцем вклада сумма с учетом процентов за месяц
 */
double get_added_sum(addSum* arr, int arr_len, int month, double interest_rate,
                     int days_in_period, double days_in_year,
                     int intaration_len) {
  double added_sum = 0;
  for (int i = 0; i < arr_len; i++) {
    // printf("added sum %lf %d %d\n", added_sum, (arr[i].month - 1) /
    // intaration_len, (month-1) / intaration_len);
    //Если в одном периоде
    if ((arr[i].month - 1) / intaration_len == (month - 1) / intaration_len)
      added_sum +=
          (arr[i].sum > 0)
              ? arr[i].sum + arr[i].sum * interest_rate *
                                 (days_in_period - arr[i].day_number + 1) /
                                 days_in_year
              : arr[i].sum;
  }
  return added_sum;
}