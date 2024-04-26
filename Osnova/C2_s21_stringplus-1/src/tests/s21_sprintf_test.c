#include "../tests.h"

// Спецификатор с
START_TEST(sprintf_c_1) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%c", 'q');
  sprintf(str2, "%c", 'q');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "  %c  ", 'q');
  sprintf(str2, "  %c  ", 'q');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%c %c%c ", 'q', ' ', '\n');
  sprintf(str2, "%c %c%c ", 'q', ' ', '\n');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_4) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%c  ", '\0');
  sprintf(str2, "%c  ", '\0');
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор d
START_TEST(sprintf_d_1) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%d", 123);
  sprintf(str2, "%d", 123);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%d", -200);
  sprintf(str2, "%d", -200);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%d %d %d", 1, -2, 3);
  sprintf(str2, "%d %d %d", 1, -2, 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[40];
  char str2[40];
  s21_sprintf(str1, "%-1d %-5d %+d %-2d %+d", 100, -2, 3, 4000, -5);
  sprintf(str2, "%-1d %-5d %+d %-2d %+d", 100, -2, 3, 4000, -5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор f
START_TEST(sprintf_f_1) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%f", 12.3);
  sprintf(str2, "%f", 12.3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%f", -20.0);
  sprintf(str2, "%f", -20.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[40];
  char str2[40];
  s21_sprintf(str1, "%f %f %f", 1.12345678, -2.12345678, 3.12345678);
  sprintf(str2, "%f %f %f", 1.12345678, -2.12345678, 3.12345678);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_4) {
  char str1[80];
  char str2[80];
  s21_sprintf(str1, "%-1f %-5f %+f %-2f %+f", 100.00000000, -21234.87654321,
              3.0, 4000.123456, -5.23456789);
  sprintf(str2, "%-1f %-5f %+f %-2f %+f", 100.00000000, -21234.87654321, 3.0,
          4000.123456, -5.23456789);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор s
START_TEST(sprintf_s_1) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, " %s", "hello world");
  sprintf(str2, " %s", "hello world");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "  %s  ", "hello \0world");
  sprintf(str2, "  %s  ", "hello \0world");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, " %s %s%s ", "hello", "", "world\n");
  sprintf(str2, " %s %s%s ", "hello", "", "world\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%s%s", "", " ");
  sprintf(str2, "%s%s", "", " ");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, " %s world", "hello");
  sprintf(str2, " %s world", "hello");
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор u
START_TEST(sprintf_u_1) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%u", 200);
  sprintf(str2, "%u", 200);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "  %u %u %u  ", 1, 2, 3);
  sprintf(str2, "  %u %u %u  ", 1, 2, 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_3) {
  char str1[40];
  char str2[40];
  s21_sprintf(str1, "%-1u %-5u %u %-2u %u", 100, 2, 3, 4000, 5);
  sprintf(str2, "%-1u %-5u %u %-2u %u", 100, 2, 3, 4000, 5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Комбинации
START_TEST(sprintf_combo_1) {
  char str1[60];
  char str2[60];
  s21_sprintf(str1, "%c %d %f %s %u %%", 'W', -100, -123.12345678,
              "Hello world", 12345678);
  sprintf(str2, "%c %d %f %s %u %%", 'W', -100, -123.12345678, "Hello world",
          12345678);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_combo_2) {
  char str1[60];
  char str2[60];
  s21_sprintf(str1, "%c %d %f %s %u %%", ' ', -0, -0.0, "", 0);
  sprintf(str2, "%c %d %f %s %u %%", ' ', -0, -0.0, "", 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// флаг -
START_TEST(sprintf_width_minus_1) {
  char str1[60];
  char str2[60];
  s21_sprintf(str1, "%-1c %-10d %-3f %-5s %-3u %%", 'W', -100, -123.12345678,
              "Hello world", 12345678);
  sprintf(str2, "%-1c %-10d %-3f %-5s %-3u %%", 'W', -100, -123.12345678,
          "Hello world", 12345678);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// флаг +
START_TEST(sprintf_width_plus_1) {
  char str1[60];
  char str2[60];
  s21_sprintf(str1, "%1c %+10d %+3f %5s %3u %%", 'W', -100, -123.12345678,
              "Hello world", 12345678);
  sprintf(str2, "%1c %+10d %+3f %5s %3u %%", 'W', -100, -123.12345678,
          "Hello world", 12345678);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precision_d_u_1) {
  char str1[200];
  char str2[200];
  s21_sprintf(str1, "%.0d %.5d %.3d %.8d %.0d %.5u %.3u %.8u", -12345, -12345,
              -12345, -12345, 12345, 12345, 12345, 12345);
  sprintf(str2, "%.0d %.5d %.3d %.8d %.0d %.5u %.3u %.8u", -12345, -12345,
          -12345, -12345, 12345, 12345, 12345, 12345);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precision_f_1) {
  char str1[200];
  char str2[200];
  s21_sprintf(str1, "%.0f %.5f %.3f %.8f", -1.12345, 1.12345, -1.12345,
              1.12345);
  sprintf(str2, "%.0f %.5f %.3f %.8f", -1.12345, 1.12345, -1.12345, 1.12345);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precision_s_1) {
  char str1[200];
  char str2[200];
  s21_sprintf(str1, "%.0s %.5s %.3s %.8s", "hello", "hello", "hello", "hello");
  sprintf(str2, "%.0s %.5s %.3s %.8s", "hello", "hello", "hello", "hello");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_and_precision_1) {
  char str1[200];
  char str2[200];
  s21_sprintf(str1, "%10.5d %6.3f %12.10u %8.5s", -100, -123.12345678, 12345678,
              "hello world");
  sprintf(str2, "%10.5d %6.3f %12.10u %8.5s", -100, -123.12345678, 12345678,
          "hello world");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_and_precision_2) {
  char str1[60];
  char str2[60];
  s21_sprintf(str1, "%3.5d %3.6f %8.10u %3.5s", -100, -123.12345678, 12345678,
              "hello world");
  sprintf(str2, "%3.5d %3.6f %8.10u %3.5s", -100, -123.12345678, 12345678,
          "hello world");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_loop_int) {
  char buf1[200];
  char buf2[200];
  char str[8];
  int numbers[6] = {0, 1, -1, 334, 1232, -1234};
  char flags[5] = {'+', '-', ' ', '#', '0'};
  char lengths[2] = {'h', 'l'};
  int weigths[3] = {0, 9, 2};
  int precision[3] = {9, 0, 3};  // Не делать больше 10!
  int i = 0;
  char specifiers[6] = {'i', 'd', 'o', 'u', 'x', 'X'};
  for (int spec = 0; spec < 6; spec++) {
    for (int fl = 0; fl < 5; fl++) {
      for (int weig = 0; weig < 3; weig++) {
        for (int len = 0; len < 2; len++) {
          for (int pre = 0; pre < 3; pre++) {
            for (int num = 0; num < 6; num++) {
              if (i == 474) continue;  // Werror format
              str[0] = '%';
              str[1] = flags[fl];
              str[2] = '0' + weigths[weig];
              str[3] = '.';
              str[4] = '0' + precision[pre];
              str[5] = lengths[len];
              str[6] = specifiers[spec];
              str[7] = '\0';
              sprintf(buf2, str, numbers[num]);
              s21_sprintf(buf1, str, numbers[num]);

              ck_assert_str_eq(buf1, buf2);
              i++;
            }
          }
        }
      }
    }
  }
}
END_TEST

// Спецификатор %
START_TEST(sprintf_percent_test) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%%as;dmas%%");
  sprintf(str2, "%%as;dmas%%");
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор p
START_TEST(sprintf_p_test) {
  char str1[20];
  char str2[20];
  s21_sprintf(str1, "%p", str1);
  sprintf(str2, "%p", str1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор o
START_TEST(sprintf_o_test) {
  char str1[30];
  char str2[30];
  s21_sprintf(str1, "%o %o", 1215, -123);
  sprintf(str2, "%o %o", 1215, -123);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Спецификатор e
START_TEST(sprintf_e_test) {
  char str1[300];
  char str2[300];
  s21_sprintf(str1, "%.e %.5e %10.3e %.10e", 1215.45, -123.55, 0., 4125.12);
  sprintf(str2, "%.e %.5e %10.3e %.10e", 1215.45, -123.55, 0., 4125.12);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ceil_round) {
  char str1[50];
  char str2[50];
  s21_sprintf(str1, "%.0e %.f %.6f %.5e", 9999.9999, 1215.6, 123.1234567,
              -7.777777);
  sprintf(str2, "%.0e %.f %.6f %.5e", 9999.9999, 1215.6, 123.1234567,
          -7.777777);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test) {
  char str1[50];
  char str2[50];
  s21_sprintf(str1, "%x %#X %*.*Lf %#o %hu %lu %010d", 123, 123, 10, 3,
              (long double)123.123, 1211, (short unsigned int)100,
              (long unsigned int)100, -10);
  sprintf(str2, "%x %#X %*.*Lf %#o %hu %lu %010d", 123, 123, 10, 3,
          (long double)123.123, 1211, (short unsigned int)100,
          (long unsigned int)100, -10);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_test) {
  char str1[50];
  char str2[50];
  int n1;
  int n2;
  s21_sprintf(str1, "%x %#X %*.*Lf %#o %hu %lu %010d %n", 123, 123, 10, 3,
              (long double)123.123, 1211, (short unsigned int)100,
              (long unsigned int)100, -10, &n1);
  sprintf(str2, "%x %#X %*.*Lf %#o %hu %lu %010d %n", 123, 123, 10, 3,
          (long double)123.123, 1211, (short unsigned int)100,
          (long unsigned int)100, -10, &n2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

// help tests
START_TEST(s21_sprintf_d) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%d>|<%-3.d>|<%5.7d>|<%10d>|<%#d>|<%-d>|<%+d>|<%ld>|<% .d>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%#e>|<%#.e>|<%#5.e>|<%#.0e>|<%#0.0e> %%";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%6.4c>|<%-6.4c>|<%4.10lc>|<%-4.10lc>|<%-0lc>";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "<% 30.1E>|<% 30.E>|<%030.0E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%i><%3.i><%5.7i><%10i><%#i><%-i><%+i><%.i><% .i>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_on) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %o %n  %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(s21_sprintf_o) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%o><%3.o><%5.7o><%10o %#o %-o %+o %.o % .o>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_p) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0p><%06p><%05.7p><%0.7p Oof %0.p>";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% s><% 3.s><% 5.7s><% 10s GOD %.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_u) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%u><%3.u><%5.7u><%10u><%#u><%-u><%+u><%.u><% .u>";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%g>|<%g>|<%4g>|<%5.6g>";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, 1000., 10.1, num, num),
                   s21_sprintf(str2, str3, num, 1000., 10.1, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%x><%3.x><%5.7x><%10x><%#x><%-x><%+x><%.x><% .x>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_h) {
  char *s21_test_str = (char *)calloc(256, sizeof(char));
  char *lib_test_str = (char *)calloc(256, sizeof(char));

  short e = 0;
  short f = 32767;
  unsigned short b = 65535;
  int lib_res = sprintf(lib_test_str, "|%hi| |%hd| |%hu|", e, f, b);
  int s21_res = s21_sprintf(s21_test_str, "|%hi| |%hd| |%hu|", e, f, b);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_sprintf_l) {
  char *s21_test_str = (char *)calloc(256, sizeof(char));
  char *lib_test_str = (char *)calloc(256, sizeof(char));
  long i = INT_MAX;
  long a = INT_MIN;
  unsigned long b = 4294967295;
  int lib_res = sprintf(lib_test_str, "|%li| |%ld| |%lu|", i, a, b);
  int s21_res = s21_sprintf(s21_test_str, "|%li| |%ld| |%lu|", i, a, b);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_sprintf_empty) {
  char *s21_test_str = (char *)calloc(512, sizeof(char));
  char *lib_test_str = (char *)calloc(512, sizeof(char));

  int lib_res = sprintf(lib_test_str, "%c", '\0');
  int s21_res = s21_sprintf(s21_test_str, "%c", '\0');

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

TCase *s21_sprintf_test(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, sprintf_c_1);
  tcase_add_test(tcase, sprintf_c_2);
  tcase_add_test(tcase, sprintf_c_3);
  tcase_add_test(tcase, sprintf_c_4);

  tcase_add_test(tcase, sprintf_d_1);
  tcase_add_test(tcase, sprintf_d_2);
  tcase_add_test(tcase, sprintf_d_3);
  tcase_add_test(tcase, sprintf_d_4);

  tcase_add_test(tcase, sprintf_f_1);
  tcase_add_test(tcase, sprintf_f_2);
  tcase_add_test(tcase, sprintf_f_3);
  tcase_add_test(tcase, sprintf_f_4);

  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_s_2);
  tcase_add_test(tcase, sprintf_s_3);
  tcase_add_test(tcase, sprintf_s_4);
  tcase_add_test(tcase, sprintf_s_5);

  tcase_add_test(tcase, sprintf_u_1);
  tcase_add_test(tcase, sprintf_u_2);
  tcase_add_test(tcase, sprintf_u_3);

  tcase_add_test(tcase, sprintf_combo_1);
  tcase_add_test(tcase, sprintf_combo_2);

  tcase_add_test(tcase, sprintf_width_minus_1);
  tcase_add_test(tcase, sprintf_width_plus_1);

  tcase_add_test(tcase, sprintf_precision_d_u_1);
  tcase_add_test(tcase, sprintf_precision_f_1);
  tcase_add_test(tcase, sprintf_precision_s_1);

  tcase_add_test(tcase, sprintf_width_and_precision_1);
  tcase_add_test(tcase, sprintf_width_and_precision_2);

  tcase_add_test(tcase, sprintf_loop_int);

  tcase_add_test(tcase, sprintf_percent_test);

  tcase_add_test(tcase, sprintf_p_test);

  tcase_add_test(tcase, sprintf_o_test);

  tcase_add_test(tcase, sprintf_e_test);

  tcase_add_test(tcase, sprintf_ceil_round);

  tcase_add_test(tcase, sprintf_x_test);

  tcase_add_test(tcase, sprintf_n_test);

  // help tests
  tcase_add_test(tcase, s21_sprintf_d);
  tcase_add_test(tcase, s21_sprintf_u);
  tcase_add_test(tcase, s21_sprintf_x);
  tcase_add_test(tcase, s21_sprintf_g);
  tcase_add_test(tcase, s21_sprintf_p);
  tcase_add_test(tcase, s21_sprintf_o);
  tcase_add_test(tcase, s21_sprintf_on);
  tcase_add_test(tcase, s21_sprintf_x);
  tcase_add_test(tcase, s21_sprintf_e);
  tcase_add_test(tcase, s21_sprintf_E);
  tcase_add_test(tcase, s21_sprintf_c);
  tcase_add_test(tcase, s21_sprintf_f);
  tcase_add_test(tcase, s21_sprintf_i);
  tcase_add_test(tcase, s21_sprintf_s);
  tcase_add_test(tcase, s21_sprintf_h);
  tcase_add_test(tcase, s21_sprintf_l);
  tcase_add_test(tcase, s21_sprintf_empty);

  return tcase;
}