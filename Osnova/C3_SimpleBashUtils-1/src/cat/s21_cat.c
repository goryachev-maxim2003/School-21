#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileErr "cat: %s: No such file or directory\n"
#define flagErr "cat: illegal option"
#define flagsCount 8  //Для flag exist количество коротких флагов

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags_struct;
void printfile(char *file_name);
int parcer(int argc, char **argv, flags_struct *flags, char ***filenames,
           int *filenames_len);
int check_flags_and_filenames_len(int *filenames_len, int argc, char **argv,
                                  int *last_flag_ind);
int flag_exists(char flag);
void flags_changer(flags_struct *flags, char flag);
void apply_flags(FILE *file, flags_struct *flags);
int is_long_flag(char *flag);

int main(int argc, char **argv) {
  flags_struct flags = {0, 0, 0, 0, 0, 0};
  char **filenames;
  int filenames_len;
  if (parcer(argc, argv, &flags, &filenames, &filenames_len)) {
    printf(flagErr);
  } else {
    //ПРОВЕРКА
    // printf("flags: %d %d %d %d %d %d\n", flags.b, flags.e, flags.n, flags.s,
    // flags.t, flags.v);
    //---------------------------------------------------
    for (int i = 0; i < filenames_len; i++) {
      FILE *file = fopen(filenames[i], "r");
      if (file == NULL) {
        printf(fileErr, filenames[i]);
      } else {
        apply_flags(file, &flags);
        fclose(file);
      }
    }
    free(filenames);
  }
  return 0;
}

int flag_exists(char flag) {
  int res = 0;
  const char flags[flagsCount] = {'b', 'e', 'n', 's', 't', 'E', 'T', 'v'};
  for (int i = 0; i < flagsCount; i++) {
    if (flag == flags[i]) {
      res = 1;
      break;
    }
  }
  return res;
}

int is_long_flag(char *flag) {
  int ret = 0;
  char *longflags[3] = {"--number-nonblank", "--number", "--squeeze-blank"};
  for (int i = 0; i < 3; i++) {
    if (!strcmp(longflags[i], flag)) {
      ret = i + 1;
    }
  }
  return ret;
}
int check_flags_and_filenames_len(int *filenames_len, int argc, char **argv,
                                  int *last_flag_ind) {
  int err = 0;
  int last_flag = 0;
  for (int i = 1; i < argc; i++) {  //Проверка флагов
    if (argv[i][0] == '-') {
      if (is_long_flag(argv[i]) == 0) {
        for (int j = 1; argv[i][j] != '\0'; j++) {
          if (!flag_exists(argv[i][j])) {
            err = 1;  //не существующий флаг
            break;
          }
        }
      }
    } else {
      break;
    }
    if (err) break;
    last_flag = i;
  }
  *last_flag_ind = last_flag;
  int len = 0;

  if (!err) {
    for (int i = last_flag + 1; i < argc; i++) {  //Количетво файлов
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
    case 'b':
      flags->b = 1;
      break;
    case 'e':
      flags->e = 1;
      flags->v = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 't':
      flags->t = 1;
      flags->v = 1;
      break;
    case 'E':
      flags->e = 1;
      break;
    case 'T':
      flags->t = 1;
      break;
  }
}

int parcer(int argc, char **argv, flags_struct *flags, char ***filenames,
           int *filenames_len) {
  int err = 0;
  int last_flag_ind;
  if (!check_flags_and_filenames_len(
          filenames_len, argc, argv,
          &last_flag_ind)) {  //Добавляем флаги и имена файлов
    int long_flag_number;
    //добавляем флаги
    for (int i = 1; i <= last_flag_ind; i++) {
      if ((long_flag_number = is_long_flag(argv[i]))) {
        switch (long_flag_number) {
          case 1:
            flags_changer(flags, 'b');
            break;
          case 2:
            flags_changer(flags, 'n');
            break;
          case 3:
            flags_changer(flags, 's');
            break;
        }
      } else {
        for (int j = 1; argv[i][j] != '\0'; j++) {
          flags_changer(flags, argv[i][j]);
        }
      }
    }
    //Добавляем имена файлов
    *filenames = (char **)malloc(sizeof(char *) * (*filenames_len));
    for (int i = last_flag_ind + 1; i < argc; i++) {
      (*filenames)[i - last_flag_ind - 1] = argv[i];
    }
  } else {
    err = 1;
  }
  return err;
}

void apply_flags(FILE *file, flags_struct *flags) {
  char ch;
  int counter = 1;
  int new_string = 1;  //был \n
  int new_string_count = 1;
  while ((ch = getc(file)) != EOF) {
    if (flags->s == 1)
      new_string_count = (ch == '\n' ? new_string_count + 1 : 0);
    if ((flags->s == 1 && new_string_count < 3) || flags->s == 0) {
      if (flags->b == 1 || flags->n == 1) {
        if (new_string == 1 && (ch != '\n' || flags->b == 0)) {
          printf("%6d\t", counter);
          counter++;
          new_string = 0;
        }
        if (ch == '\n') {
          new_string = 1;
        }
      }
      if (flags->e == 1 && ch == '\n') {
        printf("$");
      }
      if (flags->t == 1 && ch == '\t') {
        printf("^I");
      }
      //Вывод содержимого
      if (flags->t == 0 || ch != '\t') {  //  Таб не выводм если есть флаг t
        if (flags->v == 1 && ch != '\n' && ch != '\t') {
          if (ch >= 0 && ch <= 31) {
            printf("^%c", ch + 64);
          } else if (ch == 127) {
            printf("^%c", ch - 64);
          } else {
            printf("%c", ch);
          }
        } else {
          printf("%c", ch);
        }
      }
    }
  }
}