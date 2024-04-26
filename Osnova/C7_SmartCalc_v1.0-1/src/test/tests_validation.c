#include "../tests.h"

// 1. Начало - не бинарная операция и не точка.
START_TEST(valid_rule_1) {
  ck_assert_int_eq(validation("*"), ERROR);
  ck_assert_int_eq(validation("/ 234"), ERROR);
  ck_assert_int_eq(validation("^"), ERROR);
  ck_assert_int_eq(validation("mod"), ERROR);
  ck_assert_int_eq(validation(") * 5"), ERROR);
  ck_assert_int_eq(validation("atan(5)"), OK);
  ck_assert_int_eq(validation("asin(5)"), OK);
  ck_assert_int_eq(validation("acos(5)"), OK);
  ck_assert_int_eq(validation("tan(5)"), OK);
  ck_assert_int_eq(validation("sin(5)"), OK);
  ck_assert_int_eq(validation("cos(5)"), OK);
  ck_assert_int_eq(validation("sqrt(5)"), OK);
  ck_assert_int_eq(validation("-5"), OK);
  ck_assert_int_eq(validation("+5"), OK);
}
END_TEST

// 2. После бинарного оператора или + - есть (не бинарная операция, не + -, и не
// точка)
START_TEST(valid_rule_2) {
  ck_assert_int_eq(validation("1 * *"), ERROR);
  ck_assert_int_eq(validation("1 / ^"), ERROR);
  ck_assert_int_eq(validation("1 ^ /"), ERROR);
  ck_assert_int_eq(validation("1 mod +"), ERROR);
  ck_assert_int_eq(validation("1 + mod"), ERROR);
  ck_assert_int_eq(validation("1 - -"), ERROR);

  ck_assert_int_eq(validation("1 * ."), ERROR);
  ck_assert_int_eq(validation("1 / ."), ERROR);
  ck_assert_int_eq(validation("1 ^ ."), ERROR);
  ck_assert_int_eq(validation("1 mod ."), ERROR);
  ck_assert_int_eq(validation("1 + ."), ERROR);
  ck_assert_int_eq(validation("1 - ."), ERROR);

  ck_assert_int_eq(validation("1 * ( 1 + 1 )"), OK);
  ck_assert_int_eq(validation("1 / 3"), OK);
  ck_assert_int_eq(validation("1 ^ x"), OK);
  ck_assert_int_eq(validation("1 mod x"), OK);
  ck_assert_int_eq(validation("1 + 1234"), OK);
  ck_assert_int_eq(validation("1 - 3.421"), OK);
}
END_TEST

// 3. После точки может быть цифра, перед точкой может быть цифра, точка 1 раз в
// числе
START_TEST(valid_rule_3) {
  ck_assert_int_eq(validation(".ln(10) "), ERROR);
  ck_assert_int_eq(validation("(.atan(10)) "), ERROR);
  ck_assert_int_eq(validation(".5"), ERROR);
  ck_assert_int_eq(validation("5 + .5"), ERROR);
  ck_assert_int_eq(validation("5 + 5."), ERROR);
  ck_assert_int_eq(validation("5 + 5.4554.("), ERROR);
  ck_assert_int_eq(validation("5 + .5.4554"), ERROR);
  ck_assert_int_eq(validation("5 + 5..4554"), ERROR);
  ck_assert_int_eq(validation("5.455.4"), ERROR);
  ck_assert_int_eq(validation("5.455.4. + 3"), ERROR);
  ck_assert_int_eq(validation("5.45.5.4 + 3"), ERROR);
  ck_assert_int_eq(validation("5.45.5.4 + 3 + 4 + 34 + 341"), ERROR);
  ck_assert_int_eq(validation("5.45.5.4 + 5.45.5.4"), ERROR);
  ck_assert_int_eq(validation("5.455.4 + 5.45.4"), ERROR);
  ck_assert_int_eq(validation("5.4554 + 5.454"), OK);
  ck_assert_int_eq(validation("5 + 5.2"), OK);
}
END_TEST

// 4. После '(' может быть (не бинарная операция, не ')', не точка)
START_TEST(valid_rule_4) {
  ck_assert_int_eq(validation("atan( * ) "), ERROR);
  ck_assert_int_eq(validation("atan( ^ ) "), ERROR);
  ck_assert_int_eq(validation("atan( mod  7) "), ERROR);
  ck_assert_int_eq(validation("log(3 mod  7) "), OK);
  ck_assert_int_eq(validation("(3 mod 7) "), OK);
  ck_assert_int_eq(validation("()"), ERROR);
  ck_assert_int_eq(validation("(.4)"), ERROR);
  ck_assert_int_eq(validation("sin(-5)"), OK);
  ck_assert_int_eq(validation("sin(+5)"), OK);
  ck_assert_int_eq(validation("sin()"), ERROR);
  ck_assert_int_eq(validation("sin(x)"), OK);
}
END_TEST

// 5. Количество открыввающихся и закрывающихся скобок одинаковое
START_TEST(valid_rule_5) {
  ck_assert_int_eq(validation("atan(((((6.4554))))) "), OK);
  ck_assert_int_eq(validation("asin(((((6)))))) "), ERROR);
  ck_assert_int_eq(validation("log((((((6))))) "), ERROR);
  ck_assert_int_eq(validation("2 + 4 * (5 + 2 * (3 + 5.6))"), OK);
  ck_assert_int_eq(validation("2 + 4 * ((5 + 2 * (3 + 5.6))"), ERROR);
  ck_assert_int_eq(validation("2 + 4 * (5) + ) * 2 * (3 + 5.6))"), ERROR);
  ck_assert_int_eq(validation("5) + (5"), ERROR);
  ck_assert_int_eq(validation("(4+5)) + (5"), ERROR);
}
END_TEST

// 6. после ')' бинарная операция , +-, ')'
START_TEST(valid_rule_6) {
  ck_assert_int_eq(validation("5.45 + cos(4) ^ 5"), OK);
  ck_assert_int_eq(validation("5.45 + cos(4) . 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + cos(4) 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + cos(4) mod sin((x))"), OK);
  ck_assert_int_eq(validation("5.45 + cos(4) sin(x)"), ERROR);
  ck_assert_int_eq(validation("5.45 + cos(4) x"), ERROR);
  ck_assert_int_eq(validation("5.45 + cos(4) (4)"), ERROR);
  ck_assert_int_eq(validation("5.45 + (cos(4))"), OK);
}
END_TEST

// 7. После x: бинарная операция , +-, ')'
START_TEST(valid_rule_7) {
  ck_assert_int_eq(validation("5.45 + x ^ 5"), OK);
  ck_assert_int_eq(validation("5.45 + x) . 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + x) 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + x mod sin((x))"), OK);
  ck_assert_int_eq(validation("5.45 + x sin(x)"), ERROR);
  ck_assert_int_eq(validation("5.45 + x x"), ERROR);
  ck_assert_int_eq(validation("5.45 + x (4)"), ERROR);
  ck_assert_int_eq(validation("5.45 + (4)"), OK);
}
END_TEST

// 9. Послее цифры: цифра '.', ,бинарная операция, +-, ')'
START_TEST(valid_rule_9) {
  ck_assert_int_eq(validation("5.45 + 4 ^ 5"), OK);
  ck_assert_int_eq(validation("5.45 + 4) . 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + 4) 5"), ERROR);
  ck_assert_int_eq(validation("5.45 + 4 mod sin((x))"), OK);
  ck_assert_int_eq(validation("5.45 + 4 ln(x)"), ERROR);
  ck_assert_int_eq(validation("5.45 + 4 x"), ERROR);
  ck_assert_int_eq(validation("5.45 + 4 (4)"), ERROR);
  ck_assert_int_eq(validation("5.45 + (4)"), OK);
}
END_TEST

// 8. Последним символом может быть только: число, x, ')'
START_TEST(valid_rule_8) {
  ck_assert_int_eq(validation("atan( "), ERROR);
  ck_assert_int_eq(validation("sin( "), ERROR);
  ck_assert_int_eq(validation("+ "), ERROR);
  ck_assert_int_eq(validation("2 + "), ERROR);
  ck_assert_int_eq(validation("2 * "), ERROR);
  ck_assert_int_eq(validation("2 * ("), ERROR);
  ck_assert_int_eq(validation("( "), ERROR);
  ck_assert_int_eq(validation("sin(5) . "), ERROR);
  ck_assert_int_eq(validation("sin(5) . "), ERROR);
  ck_assert_int_eq(validation("4 )("), ERROR);
}
END_TEST

START_TEST(valid_random) {
  ck_assert_int_eq(
      validation("2.354 + 2.123 * 5.000 + ((5^(sin(x*(2 mod 5)) * x)))"), OK);
  ck_assert_int_eq(
      validation("2.354 + 2.12.3 * 5.000 + ((5^(sin(x*(2 mod 5)) * x)))"),
      ERROR);
  ck_assert_int_eq(validation("asin( acos( x ) )"), OK);
  ck_assert_int_eq(validation("xx"), ERROR);
  ck_assert_int_eq(validation("5x"), ERROR);
  ck_assert_int_eq(validation("x5"), ERROR);
  ck_assert_int_eq(validation("-x*5"), OK);
}
END_TEST

TCase *tests_validation(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, valid_rule_1);
  tcase_add_test(tcase, valid_rule_2);
  tcase_add_test(tcase, valid_rule_3);
  tcase_add_test(tcase, valid_rule_4);
  tcase_add_test(tcase, valid_rule_5);
  tcase_add_test(tcase, valid_rule_6);
  tcase_add_test(tcase, valid_rule_7);
  tcase_add_test(tcase, valid_rule_8);
  tcase_add_test(tcase, valid_rule_9);
  tcase_add_test(tcase, valid_random);

  return tcase;
}
