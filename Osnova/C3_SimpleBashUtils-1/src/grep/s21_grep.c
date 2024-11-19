#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define flagsCount 10
#define flagErr "grep: illegal option"
#define fileErr "grep: %s: No such file or directory\n"

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags_struct;

int check_flags_and_filenames_len(int *filenames_len, int argc, char **argv,
                                  int *last_flag_ind, char ***f_filenames,
                                  int *template_must_be, int *f_filenames_len,
                                  int *templates_len, char ***templates,
                                  char **f_strings, int *f_strings_len);
void apply_flags(FILE *file, flags_struct *flags, char **templates,
                 int templates_len, char *filename);
int parcer(int argc, char **argv, flags_struct *flags, char ***filenames,
           int *filenames_len, char ***templates, char ***f_filenames,
           int *template_must_be, int *f_filenames_len, int *templates_len,
           char **f_strings, int *f_strings_len);
void add_el(char ***mas_pointer, char *el, int *size);
int template_check(char *s, char *template, flags_struct *flags);
void flag_o(char *s, char **templates, int templates_len, flags_struct *flags,
            char *filename, int string_number);
void flag_f(char *f_filename, char ***templates, int *templates_len,
            char **f_strings, int *f_strings_len);

int main(int argc, char **argv) {
  flags_struct flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char **filenames = NULL;
  int templates_len = 0;
  char **templates = calloc(0, sizeof(char *));
  int filenames_len = 0;
  int f_filenames_len;
  char **f_filenames = calloc(0, sizeof(char *));
  int template_must_be = 1;
  char *f_strings = calloc(0, sizeof(char));  //Строка1\0Строка2\0...
  int f_strings_len = 0;
  if (parcer(argc, argv, &flags, &filenames, &filenames_len, &templates,
             &f_filenames, &template_must_be, &f_filenames_len, &templates_len,
             &f_strings, &f_strings_len)) {
    printf(flagErr);
  } else {
    // printf("", flags.e, flags.i, flags.v, flags.c, flags.l, flags.n, flags.h,
    // flags.s, flags.f, flags.o);
    // printf("%d %d %d %d %d %d %d %d %d %d\n",
    //  flags.e, flags.i, flags.v, flags.c, flags.l, flags.n, flags.h, flags.s,
    // flags.f, flags.o);
    //Основа, так сказать, база
    for (int i = 0; i < filenames_len; i++) {
      FILE *file = fopen(filenames[i], "r");
      if (file == NULL) {
        if (!flags.s) printf(fileErr, filenames[i]);
      } else {
        // printf("filename: %s\n", filenames[i]);
        // printf("Вывод программы ________________________\n");
        apply_flags(file, &flags, templates, templates_len,
                    (filenames_len > 1)
                        ? filenames[i]
                        : NULL);  // если одно имя файла то filenames=NULL, в
                                  // таком случае grep не выводит имя файла
        // printf(" ________________________________________\n");
      }
      if (file != NULL) fclose(file);
    }
    //ПРОВЕРКА------------------------------------------------------
    // printf("f_filenames_len: %d\n", f_filenames_len);
    // for (int i = 0; i<f_filenames_len; i++){
    //     printf("f_filemane: %s\n", f_filenames[i]);
    // }
    // printf("templates_len %d\n", templates_len);
    // for (int i = 0; i<templates_len; i++){
    //     printf("template: %s\n", templates[i]);
    // }
  }
  if (filenames != NULL) free(filenames);
  if (templates != NULL) free(templates);
  if (f_filenames != NULL) free(f_filenames);
  if (f_strings != NULL) free(f_strings);
  return 0;
}

int flag_exists(char flag) {
  int res = 0;
  char flags[flagsCount] = {'e', 'i', 'v', 'c', 'l', 'n', 'h', 's', 'f', 'o'};
  for (int i = 0; i < flagsCount; i++) {
    if (flag == flags[i]) {
      res = 1;
      break;
    }
  }
  return res;
}

int check_flags_and_filenames_len(int *filenames_len, int argc, char **argv,
                                  int *last_flag_ind, char ***f_filenames,
                                  int *template_must_be, int *f_filenames_len,
                                  int *templates_len, char ***templates,
                                  char **f_strings, int *f_strings_len) {
  int err = 0;
  int last_flag = 0;
  int skip_next_i = 0;
  *f_filenames_len = 0;
  for (int i = 1; i < argc; i++) {  //Проверка флагов
    if (skip_next_i) {
      skip_next_i = 0;
      continue;
    }
    if ((*template_must_be) && argv[i][0] == '-' &&
        argv[i][1] == '\0') {  //Если или - , то значит это шаблон !замечание
                               //--[символы] -не работает в grep
      break;
    } else if (argv[i][0] == '-') {
      for (int j = 1; argv[i][j] != '\0';
           j++) {  //Проверяем каждый символ флага
        if (!flag_exists(argv[i][j])) {
          err = 1;  //не существующий флаг
          break;
        } else if (argv[i][j] == 'f') {  //Если флаг f
          *template_must_be = 0;
          if (argc != (i + 1) &&
              argv[i][j + 1] == '\0') {  //аргумент не поcледний и флаг
                                         //последний (случай -[флаги]f text.txt)
            add_el(f_filenames, argv[i + 1], f_filenames_len);
            flag_f(argv[i + 1], templates, templates_len, f_strings,
                   f_strings_len);
            skip_next_i = 1;
            last_flag++;
          } else if (argv[i][j + 1] !=
                     '\0') {  //флаг не последний(случай -ftext.txt))
            add_el(f_filenames, argv[i] + j + 1,
                   f_filenames_len);  //Указатель на следующий символ после f
            flag_f(argv[i] + j + 1, templates, templates_len, f_strings,
                   f_strings_len);
            break;
          } else {
            err = 1;
            break;
          }
        } else if (argv[i][j] == 'e') {  //Если флаг e
          *template_must_be = 0;
          if (argc != (i + 1) &&
              argv[i][j + 1] == '\0') {  //аргумент не поcледний и флаг
                                         //последний (случай -[флаги]e шаблон)
            add_el(templates, argv[i + 1], templates_len);
            skip_next_i = 1;
            last_flag++;
          } else if (argv[i][j + 1] !=
                     '\0') {  //флаг не последний(случай -eшаблон))
            add_el(templates, argv[i] + j + 1,
                   templates_len);  //Указатель на следующий символ после e
            break;
          } else {
            err = 1;
            break;
          }
        }
      }
    } else {
      break;
    }
    if (err) break;
    last_flag++;
  }
  *last_flag_ind = last_flag;
  int len = 0;
  if (!err) {
    for (int i = last_flag + 1 + (*template_must_be); i < argc;
         i++) {  //Количетво файлов (Начинаем с last_flag+2), если есть шабон, и
                 //с last_flag+1 если нет
      if (argv[i][0] == '-') {
        err = 1;  //неожиданный флаг между именами файлов
        break;
      } else {
        len++;
      }
    }
  }
  if (!err) *filenames_len = len;
  return err;
}

void flags_changer(flags_struct *flags, char flag) {
  switch (flag) {
    case 'e':
      flags->e = 1;
      break;
    case 'i':
      flags->i = 1;
      break;
    case 'v':
      flags->v = 1;
      break;
    case 'c':
      flags->c = 1;
      break;
    case 'l':
      flags->l = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 'h':
      flags->h = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 'f':
      flags->f = 1;
      break;
    case 'o':
      flags->o = 1;
      break;
  }
}

int parcer(int argc, char **argv, flags_struct *flags, char ***filenames,
           int *filenames_len, char ***templates, char ***f_filenames,
           int *template_must_be, int *f_filenames_len, int *templates_len,
           char **f_strings, int *f_strings_len) {
  int err = 0;
  int last_flag_ind;
  if (!check_flags_and_filenames_len(
          filenames_len, argc, argv, &last_flag_ind, f_filenames,
          template_must_be, f_filenames_len, templates_len, templates,
          f_strings, f_strings_len)) {  //Добавляем флаги и имена файлов
    int skip_next_i = 0;
    //Добавляем шаблон
    if ((*template_must_be))
      add_el(templates, argv[last_flag_ind + 1], templates_len);
    //добавляем флаги
    for (int i = 1; i <= last_flag_ind; i++) {
      if (skip_next_i) {
        skip_next_i = 0;
        continue;
      }
      for (int j = 1; argv[i][j] != '\0'; j++) {
        flags_changer(flags, argv[i][j]);
        if ((argv[i][j] == 'e' || argv[i][j] == 'f') && argv[i][j + 1] != '\0')
          break;  // случай -etemplate или -ffile
        else if ((argv[i][j] == 'e' || argv[i][j] == 'f') &&
                 argv[i][j + 1] == '\0')
          skip_next_i =
              1;  // случай -e template или -f file. Следующий аргумент точно
                  // будет так как это проверялось в другой функции
      }
    }
    //Добавляем имена файлов
    *filenames = (char **)malloc(sizeof(char *) * (*filenames_len));
    for (int i = last_flag_ind + 1 + (*template_must_be); i < argc; i++) {
      (*filenames)[i - last_flag_ind - 1 - (*template_must_be)] = argv[i];
    }
  } else {
    err = 1;
  }
  return err;
}

void add_el(char ***mas_pointer, char *el, int *size) {
  (*size)++;
  (*mas_pointer) = realloc((*mas_pointer), (*size) * sizeof(char *));
  (*mas_pointer)[(*size) - 1] = el;
}

void apply_flags(
    FILE *file, flags_struct *flags, char **templates, int templates_len,
    char *filename) {  //Проверка шаблона для обдного файла применяя флаги
  char s[10000];
  int flagc_counter = 0;
  int file_have_template = 0;
  int all_strings_have_template_in_file = 1;  //Для -v -l
  //Проверка файла на пустоту
  fseek(file, 0, SEEK_END);
  int empty_file = (ftell(file) > 0) ? 0 : 1;
  rewind(file);
  // printf("filename %s empty_file:%d\n", filename, empty_file);
  //перебираем строки
  int string_number = 0;
  while (fgets(s, 10000, file) != NULL) {
    for (int i = 0; s[i] != '\0'; i++) {  //Удаление \n
      if (s[i] == '\n') s[i] = '\0';
    }
    string_number++;
    int string_have_template = 0;
    //Флаг -o работает отдельно от всех
    if (flags->o && !empty_file && !flags->c &&
        !flags->l) {  //Флаги -c и -l отменяют флаг -o
      flag_o(s, templates, templates_len, flags, filename, string_number);
    } else {
      //Перебираем шаблоны
      for (int i = 0; i < templates_len; i++) {
        if (!template_check(s, templates[i], flags)) {
          if (flags->l) file_have_template = 1;
          string_have_template = 1;
          break;
        }
      }
      // printf("string_have_template:%d string:%s\n", string_have_template, s);
      all_strings_have_template_in_file *= string_have_template;
      if ((flags->v) ? !string_have_template : string_have_template) {
        if (flags->c &&
            !empty_file) {  //проверка на пустой файл нужна для случая -v с
                            //пустым файлом. у пустого файла должно быть 0
          flagc_counter++;
        } else if (!flags->l) {
          if (flags
                  ->n) {  //Стандартный вывод (флаг l отменяет построчный вывод)
            (filename == NULL || flags->h)
                ? printf("%d:%s\n", string_number, s)
                : (printf("%s:%d:%s\n", filename, string_number, s));
          } else {
            (filename == NULL || flags->h) ? printf("%s\n", s)
                                           : (printf("%s:%s\n", filename, s));
          }
        }
      }
    }
  }
  if (flags->c)
    (filename == NULL || flags->h)
        ? printf("%d\n", (flags->l) ? flagc_counter > 0 : flagc_counter)
        : printf("%s:%d\n", filename,
                 (flags->l) ? flagc_counter > 0 : flagc_counter);
  if (flags->l && !empty_file &&
      ((flags->v) ? !all_strings_have_template_in_file : file_have_template))
    printf("%s\n",
           filename);  //Пустые файлы флаг l не обрабатывает. -l вместе с -v
                       //выводит те файлы где есть хоть одно несовпадение
}

int template_check(char *s, char *template, flags_struct *flags) {
  int recomp_flag = 0;
  if (flags->i) recomp_flag = REG_ICASE;
  regex_t reegex;
  int value =
      regcomp(&reegex, template, recomp_flag);  // value = 0 => паттерн есть
  if (value) {
    printf("Ошибка с вводом шаблона");
  } else {
    value = regexec(&reegex, s, 0, NULL, 0);
  }
  // printf("template_check s: %s, template: %s, value: %d\n", s, template,
  // value);
  regfree(&reegex);
  return value;
}

void flag_o(char *s, char **templates, int templates_len, flags_struct *flags,
            char *filename,
            int string_number) {  //Для каждой строки выводит совпадения
  char *start_of_template;
  int need_to_print_filename = 1;
  //Перебираем шаблоны
  for (int i = 0; i < templates_len; i++) {
    if (flags->v) {  //С флагом v
      if (strstr(s, templates[i]) == NULL) {
        if (filename != NULL && !flags->h)
          (flags->n) ? printf("%s:%d:%s\n", filename, string_number, s)
                     : printf("%s:%s\n", filename, s);
      }
    } else {  //Без флага v
      int template_len = strlen(templates[i]);
      //Просматрваем все сопадения с шаблонами
      while ((start_of_template = strstr(s, templates[i])) != NULL) {
        //Вывод названия файла
        if (need_to_print_filename) {
          if (filename != NULL && !flags->h)
            (flags->n) ? printf("%s:%d:", filename, string_number)
                       : printf("%s:", filename);
          need_to_print_filename = 0;
        }
        //Вывод совпадения
        for (char *j = start_of_template; j < start_of_template + template_len;
             j++)
          printf("%c", *j);
        printf("\n");
        s = start_of_template + 1;  //Удаляем все, что было до шаблона
      }
    }
    //     //printf("Шаблон внутри флага -o %s\n", templates[i]); //Пока
  }
}

void flag_f(char *f_filename, char ***templates, int *templates_len,
            char **f_strings, int *f_strings_len) {
  char s[100000];
  FILE *file = fopen(f_filename, "r");
  if (file == NULL) {
    printf(fileErr, f_filename);
  } else {
    int k = 0;  //Позиция в f_strings
    while (fgets(s, 10000, file) != NULL) {
      for (int i = 0; s[i] != '\0'; i++) {  //Удаление \n
        if (s[i] == '\n') s[i] = '\0';
      }
      int string_len = strlen(s);
      (*f_strings_len) += string_len + 1;
      (*f_strings) = realloc((*f_strings), (*f_strings_len) * sizeof(char));
      for (int i = 0; s[i] != '\0'; i++) {
        (*f_strings)[i + k] = s[i];
      }
      //Добавляем элемент в template
      add_el(templates, (*f_strings) + k, templates_len);
      k += string_len + 1;
    }
  }
}
