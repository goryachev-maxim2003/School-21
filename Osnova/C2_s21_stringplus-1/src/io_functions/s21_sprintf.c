#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list vl;
  va_start(vl, format);

  int str_i = 0;
  for (int i = 0; i < (int)s21_strlen(format); i++) {
    opt_struct options = {0, 0, 0, 0, 0, 0, -1, 0, 0};  // Точность в начале =
                                                        // -1
    if (format[i] == '%') {
      parcer(&i, &options, format, &vl);
      push_specifier(&str_i, str, &options, &vl);
    } else {
      str[str_i] = format[i];  // Запись в буфер
      str_i++;
    }
    str[str_i] = '\0';
  }
  va_end(vl);
  return str_i;
}

void parcer(int *i, opt_struct *options, const char *format, va_list *vl) {
  get_flags(i, options, format);
  get_width_or_precision(i, options, format, vl, FOR_WIDTH);
  get_precision(i, options, format, vl);
  get_length(i, options, format);
  get_specifier(i, options, format);
  (*i)--;  // чтобы не потерять первый символ после всех опций
}

void get_flags(
    int *i, opt_struct *options,
    const char *format) {  // читает и записывает флаги увеличивая i в парсере
  while (1) {
    (*i)++;  // Изначально позиция стоит на знаке '%'
    if (format[*i] == '-')
      options->minus = 1;
    else if (format[*i] == '+')
      options->plus = 1;
    else if (format[*i] == ' ')
      options->space = 1;
    else if (format[*i] == '#')
      options->hash = 1;
    else if (format[*i] == '0')
      options->zero = 1;
    else
      break;
  }
  // Заканчиваем на первом символе после флагов
}

int get_int_from_format(int *i, const char *format) {
  int number = 0;
  int number_len = 0;
  for (; '0' <= format[(*i) + number_len] && format[(*i) + number_len] <= '9';
       number_len++)
    ;
  (*i) += number_len - 1;
  int step = 1;
  for (int step_i = 0; step_i < number_len; step_i += 1) {  // пока цифра
    number += (format[*i] - '0') * step;
    (*i)--;
    step *= 10;
  }
  (*i) += number_len + 1;  // Переходим на первый символ после числа
  return number;
}

void get_width_or_precision(int *i, opt_struct *options, const char *format,
                            va_list *vl, int for_width) {
  if ('0' <= format[*i] && format[*i] <= '9')
    *(for_width ? &(options->width) : &(options->precision)) =
        get_int_from_format(i, format);
  else if (format[*i] == '*') {
    *(for_width ? &(options->width) : &(options->precision)) = va_arg(*vl, int);
    (*i)++;
  }
}

void get_precision(int *i, opt_struct *options, const char *format,
                   va_list *vl) {
  if (format[*i] == '.') {
    options->precision = 0;
    (*i)++;
    get_width_or_precision(i, options, format, vl, FOR_PRECISION);
  }
}

void get_length(int *i, opt_struct *options, const char *format) {
  while (1) {
    if (format[*i] == 'h')
      options->length = 'h';
    else if (format[*i] == 'l')
      options->length = 'l';
    else if (format[*i] == 'L')
      options->length = 'L';
    else
      break;
    (*i)++;
  }
}

void get_specifier(int *i, opt_struct *options, const char *format) {
  if (s21_strchr("cdieEfFgGosuxXpn%", format[*i])) {
    options->specifier = format[*i];
    (*i)++;
  }
}

void push_specifier(int *str_i, char *str, opt_struct *options, va_list *vl) {
  int persent_index = *str_i;
  if (options->specifier == 'c')
    specifier_c(str_i, str, vl);
  else if (options->specifier == 'd' || options->specifier == 'i')
    specifier_d(str_i, str, options, vl);
  else if (options->specifier == 'e' || options->specifier == 'E' ||
           options->specifier == 'f' || options->specifier == 'g' ||
           options->specifier == 'G') {
    long double d;
    init_arg_with_length(&d, options, vl);
    if (options->specifier == 'e' || options->specifier == 'g')
      specifier_e(str_i, str, options, 0, d);
    else if (options->specifier == 'E' || options->specifier == 'G')
      specifier_e(str_i, str, options, 1, d);
    else if (options->specifier == 'f')
      specifier_f(str_i, str, options, d);
  } else if (options->specifier == 'o')
    specifier_o(str_i, str, options, vl);
  else if (options->specifier == 's')
    specifier_s(str_i, str, options, vl);
  else if (options->specifier == 'u')
    specifier_u(str_i, str, options, vl);
  else if (options->specifier == 'x')
    specifier_x(str_i, str, options, vl, 0);
  else if (options->specifier == 'X')
    specifier_x(str_i, str, options, vl, 1);
  else if (options->specifier == 'p')
    specifier_p(str_i, str, options, vl);
  else if (options->specifier == 'n')
    specifier_n(str_i, vl);
  else if (options->specifier == '%')
    specifier_percent(str_i, str);
  ;

  width(str_i, str, options, persent_index);
}

void flag_plus_and_space(int *str_i, char *str, opt_struct *options) {
  if (options->plus || options->space) {
    str[*str_i] = (options->plus ? '+' : ' ');  // + приорететнее чем ' '
    (*str_i)++;
  }
}

void width(int *str_i, char *str, opt_struct *options,
           int persent_index) {  // Потдерживает флаг 0
  int count = options->width - ((*str_i) - persent_index);
  char width_ch = (options->zero ? '0' : ' ');
  if (count > 0) {
    if (options->minus) {  // Если по левому краю
      // Подстановка пробелов
      for (int i = 0; i < count; i++) str[(*str_i) + i] = width_ch;
      (*str_i) += count;
    } else {  // Если по правому краю
      // Сдвиг в буфере
      for (int i = 0; i < (*str_i) - persent_index; i++)
        str[(*str_i) - 1 - i + count] = str[(*str_i) - 1 - i];

      // Подстановка пробелов
      for (int i = 0; i < count; i++) str[persent_index + i] = width_ch;
      (*str_i) += count;

      // ' ', '+' и '-' стоят перед отступами когда отcтупы - '0',
      // Меняем 0 и {'-', '+', ' '} местами для чисел c флагами + ' ', и
      // отрицательных чисел
      if (width_ch == '0' && s21_strchr("fd", options->specifier) &&
          s21_strchr("-+ ", str[persent_index + count])) {
        str[persent_index] = str[persent_index + count];
        str[persent_index + count] = width_ch;
      }
    }
  }
}

void precision_for_int(int *str_i, char *str, opt_struct *options,
                       int *number_len, int d) {  // d,i,o,u,x,X
  if (d == 0 && options->precision == 0) (*number_len)--;
  int count = options->precision - *number_len;
  for (int i = 0; i < count; i++) str[(*str_i) + i] = '0';
  if (count > 0) (*str_i) += options->precision - *number_len;
}

void flag_hash_for_oxX(int *str_i, char *str, opt_struct *options) {
  if (options->hash) {
    str[(*str_i)] = '0';
    (*str_i)++;
    if (options->specifier == 'x')
      str[(*str_i)] = 'x';
    else if (options->specifier == 'X')
      str[(*str_i)] = 'X';
    else
      (*str_i)--;
    (*str_i)++;
  }
}

// Инициалищирует аргумент учитывая ширину
void init_arg_with_length(void *var, opt_struct *options, va_list *vl) {
  // Целые
  if (s21_strchr("idoxX", options->specifier)) {
    if (options->length == 'h') {
      *((long int *)var) = (short int)va_arg(*vl, int);
    } else if (options->length == 'l') {
      *((long int *)var) = va_arg(*vl, long int);
    } else {
      *((long int *)var) = va_arg(*vl, int);
    }
  } else if (options->specifier == 'p') {  // спецификатор p использует x
    *((long int *)var) = va_arg(*vl, long int);
  }
  // Беззнаковый
  else if (options->specifier == 'u') {
    if (options->length == 'h') {
      *((unsigned long int *)var) =
          (unsigned short int)va_arg(*vl, unsigned int);
    } else if (options->length == 'l') {
      *((unsigned long int *)var) = va_arg(*vl, unsigned long int);
    } else {
      *((unsigned long int *)var) = va_arg(*vl, unsigned int);
    }
  }
  // Дробные
  else if (s21_strchr("eEfgG", options->specifier)) {
    if (options->length == 'L') {
      *((long double *)var) = va_arg(*vl, long double);
    } else {
      *((long double *)var) = va_arg(*vl, double);
    }
  }
}

void delete_zeros(int *str_i, char *str) {
  int len = s21_strlen(str);
  for (int i = len - 1; i >= 0 && str[i] == '0';
       i--) {  // Удаление незначимых нулей
    str[i] = '\0';
    (*str_i)--;
  }
  if (str[(*str_i) - 1] == '.') {  // удаление точки если за ней нет символов
    str[(*str_i) - 1] = '\0';
    (*str_i)--;
  }
}