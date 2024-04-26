#include "../s21_string.h"

void specifier_c(int *str_i, char *str, va_list *vl) {
  str[*str_i] = (char)va_arg(*vl, int);
  (*str_i)++;
}

void specifier_s(int *str_i, char *str, opt_struct *options, va_list *vl) {
  char *tmp = va_arg(*vl, char *);
  s21_size_t len = s21_strlen(tmp);
  if (options->precision != -1) {
    if (options->precision < (int)len) {
      len = options->precision;
    }
  }
  s21_strncat(str, tmp, len);
  (*str_i) += len;
}

void specifier_percent(int *str_i, char *str) {
  str[*str_i] = '%';
  (*str_i)++;
}

void specifier_p(int *str_i, char *str, opt_struct *options, va_list *vl) {
  options->hash = 1;
  specifier_x(str_i, str, options, vl, 0);
}

void specifier_d(int *str_i, char *str, opt_struct *options, va_list *vl) {
  long int d;
  init_arg_with_length(&d, options, vl);
  // Обработка минуса
  if (d < 0) {
    d *= -1;
    str[(*str_i)] = '-';
    (*str_i)++;
  } else
    flag_plus_and_space(str_i, str, options);

  int numer_len = 1;  // число размером меньше одного ввести невозможно
  for (long long int step = 10; d >= step; step *= 10) numer_len++;
  precision_for_int(str_i, str, options, &numer_len, d);
  for (int i = numer_len - 1; i >= 0; i--) {
    str[i + (*str_i)] = d % 10 + '0';
    d /= 10;
  }
  (*str_i) += numer_len;
}

void specifier_u(int *str_i, char *str, opt_struct *options, va_list *vl) {
  unsigned long int d;
  init_arg_with_length(&d, options, vl);
  int numer_len = 1;  // число размером меньше одного ввести невозможно
  for (unsigned long long int step = 10; d >= step; step *= 10) numer_len++;
  precision_for_int(str_i, str, options, &numer_len, d);
  for (int i = numer_len - 1; i >= 0; i--) {
    str[i + (*str_i)] = d % 10 + '0';
    d /= 10;
  }
  (*str_i) += numer_len;
}

void specifier_o(int *str_i, char *str, opt_struct *options, va_list *vl) {
  long int d;
  init_arg_with_length(&d, options, vl);
  if (d != 0)
    flag_hash_for_oxX(str_i, str, options);  // hash для нуля не работает
  if (d < 0) d = 4294967295 + 1 + d;  // Обработка отрицательных чисел
  int numer_len = 1;  // число размером меньше одного ввести невозможно
  for (long long int step = 8; d >= step; step *= 8) numer_len++;
  precision_for_int(str_i, str, options, &numer_len, d);
  for (int i = numer_len - 1; i >= 0; i--) {
    str[i + (*str_i)] = d % 8 + '0';
    d /= 8;
  }
  (*str_i) += numer_len;
}

void specifier_x(int *str_i, char *str, opt_struct *options, va_list *vl,
                 int big) {
  long int d;
  init_arg_with_length(&d, options, vl);
  int was_p = options->specifier == 'p';
  if (options->specifier == 'p')
    options->specifier =
        'x';  // Для hash. init сначало, чтобы для p выделилось больше памяти
  if (d != 0 || was_p)
    flag_hash_for_oxX(str_i, str,
                      options);  // hash для нуля не работает если не p
  if (d < 0) d = 4294967295 + 1 + d;  // Обработка отрицательных чисел
  int numer_len = 1;  // число размером меньше одного ввести невозможно
  for (long long int step = 16; d >= step; step *= 16) numer_len++;
  precision_for_int(str_i, str, options, &numer_len, d);
  for (int i = numer_len - 1; i >= 0; i--) {
    str[i + (*str_i)] =
        (d % 16 > 9 ? d % 16 + 'a' - big * 32 - 10 : d % 16 + '0');
    d /= 16;
  }
  (*str_i) += numer_len;
}

void specifier_e(int *str_i, char *str, opt_struct *options, int big,
                 long double d) {
  long double old_d = d;  // сохраняем старое значение если будет необходимо
                          // вызвать флаг f для спецификатора g
  // Точность по умолчанию
  if (options->precision == -1) options->precision = 6;
  if (options->specifier == 'g' || options->specifier == 'G')
    options->precision = 5;  // для спецификатора g

  // Обрабоотка минуса
  if (1 / d < 0) {  // 1/d - чтобы отличить негативный ноль от обычного
    d *= -1;
    str[(*str_i)] = '-';
    (*str_i)++;
  } else
    flag_plus_and_space(str_i, str, options);

  // Нормализация
  int exp = 0;
  while (d >= 10) {
    d /= 10;
    exp++;
  }
  while (d < 1 && d != 0.) {
    d *= 10;
    exp--;
  }
  // СПЕЦИФИКАТОР G
  if ((options->specifier == 'g' || options->specifier == 'G') && exp >= -4 &&
      exp <= 5) {
    specifier_f(
        str_i, str, options,
        old_d);  // Используем f для g если экспонента в определенном диапазоне
  } else {
    // Записываем целую часть числа
    long long int ceil_part_d = (int)d;
    double fraction = d - (long long int)d;  // дробная часть
    // Округление до целого
    if (options->precision == 0 && floor(fraction * 10 + 0.000000001) >= 5)
      ceil_part_d++;
    // Нормализация в случае например %.0e 999999.7
    while (ceil_part_d >= 10) {
      ceil_part_d /= 10;
      d /= 10;
      exp++;
    }
    str[(*str_i)] = (int)ceil_part_d % 10 + '0';
    (*str_i)++;
    if (options->precision || options->hash) {
      str[(*str_i)] = '.';
      (*str_i)++;
    }
    if (options->precision) {  // если не округлилось до целого
      // Записываем дробную часть числа
      for (int i = 0; i < 6; i++) {
        int num = (int)(fraction * 10 +
                        0.000000001);  // Костыль (0.1*10 = 0.99999999)
        str[i + (*str_i)] = (num) + '0';
        fraction = 10 * fraction - num;
        // Округление последнего знака
        if ((i == options->precision - 1) &&
            (floor(fraction * 10 + 0.000000001) >= 5))
          str[i + (*str_i)] += 1;
        if (i == options->precision - 1) break;
      }
      (*str_i) += (options->precision >= 6
                       ? 6
                       : options->precision);  // Если точность > 6 двигаем на 6

      // Дописываем нули если точность больше
      for (int i = 0; i < options->precision - 6; i++) {
        str[*str_i] = '0';
        (*str_i)++;
      }
      if (options->specifier == 'g' || options->specifier == 'G')
        delete_zeros(
            str_i,
            str);  // Для спецификаотра g (удаляем нули перед записи e+...)
    }
    str[*str_i] = 'e' - 32 * big;
    str[*str_i + 1] = exp >= 0 ? '+' : '-';  // знак
    if (exp < 0) exp *= -1;
    (*str_i) += 2;
    if (exp < 10) {
      str[*str_i] = '0';
      (*str_i)++;
    }
    // Записываем степень
    int exp_len = 1;
    for (long long int step = 10; exp >= step; step *= 10) exp_len++;
    for (int i = exp_len - 1; i >= 0; i--) {
      str[i + (*str_i)] = exp % 10 + '0';
      exp /= 10;
    }
    (*str_i) += exp_len;
  }
}

void specifier_f(int *str_i, char *str, opt_struct *options, long double d) {
  // Точность по умолчанию
  if (options->precision == -1) options->precision = 6;

  // Обрабоотка минуса
  if (1 / d < 0) {  // 1/d - чтобы отличить негативный ноль от обычного
    d *= -1;
    str[(*str_i)] = '-';
    (*str_i)++;
  } else
    flag_plus_and_space(str_i, str, options);
  // Записываем целую часть числа
  long long int ceil_part_d = (long long int)d;
  int len_before_point = 1;  // число размером меньше одного ввести невозможно
  for (long long int step = 10; ceil_part_d >= step; step *= 10)
    len_before_point++;
  if (options->specifier == 'g' || options->specifier == 'G')
    options->precision = 6 - len_before_point;  // для спецификатора g
  double fraction = d - (long long int)d;  // дробная часть
  // Округление до целого
  if (options->precision == 0 && floor(fraction * 10 + 0.000000001) >= 5)
    ceil_part_d++;
  for (int i = len_before_point - 1; i >= 0; i--) {
    str[i + (*str_i)] = (long long int)ceil_part_d % 10 + '0';
    ceil_part_d /= 10;
  }

  (*str_i) += len_before_point;
  int was_point = 0;  // запоминаем была ли точка, чтобы для спецификатора g
                      // случайно не удалить значимые нули
  if (options->precision || options->hash) {
    str[(*str_i)] = '.';
    (*str_i)++;
    was_point = 1;
  }
  if (options->precision) {  // если не округлилось до целого
    // Записываем дробную часть числа

    for (int i = 0; i < 6; i++) {
      int num =
          (int)(fraction * 10 + 0.000000001);  // Костыль (0.1*10 = 0.99999999)
      str[i + (*str_i)] = (num) + '0';
      fraction = 10 * fraction - num;
      // Округление последнего знака
      if ((i == options->precision - 1) &&
          (floor(fraction * 10 + 0.000000001) >= 5))
        str[i + (*str_i)] += 1;
      if (i == options->precision - 1) break;
    }
    (*str_i) += (options->precision >= 6
                     ? 6
                     : options->precision);  // Если точность > 6 двигаем на 6

    // Дописываем нули если точность больше
    for (int i = 0; i < options->precision - 6; i++) {
      str[*str_i] = '0';
      (*str_i)++;
    }
  }
  if (was_point && (options->specifier == 'g' || options->specifier == 'G'))
    delete_zeros(
        str_i,
        str);  // Для спецификаотра g (удаляем нули только если была точка)
}
void specifier_n(int *str_i, va_list *vl) {
  int *n = va_arg(*vl, int *);
  *n = *str_i;
}