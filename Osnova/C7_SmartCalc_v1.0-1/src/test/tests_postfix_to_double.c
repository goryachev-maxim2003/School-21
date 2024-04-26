#include "../tests.h"

START_TEST(stack) {
  numbers_stack* stack = n_init(1.1);
  ck_assert_double_eq(stack->value, 1.1);
  ck_assert_double_eq(stack->next == NULL, 1);
  n_push(&stack, 2.);
  ck_assert_double_eq(stack->value, 2.);
  ck_assert_double_eq(stack->next->value, 1.1);
  ck_assert_double_eq(n_pop(&stack), 2.);
  ck_assert_double_eq(stack->value, 1.1);
  ck_assert_double_eq(stack->next == NULL, 1);
  n_push(&stack, 3.23);
  ck_assert_double_eq(stack->value, 3.23);
  ck_assert_double_eq(stack->next->value, 1.1);
  ck_assert_double_eq(n_pop(&stack), 3.23);
  ck_assert_double_eq(stack->value, 1.1);
  n_push(&stack, 1.1);
  n_push(&stack, 1.1);
  n_push(&stack, 2.);
  n_push(&stack, 6.);
  n_destroy(stack);
}
END_TEST

START_TEST(test_operation_status) {
  ck_assert_int_eq(operation_status(ATAN), UNARY_OP);
  ck_assert_int_eq(operation_status(ASIN), UNARY_OP);
  ck_assert_int_eq(operation_status(ACOS), UNARY_OP);
  ck_assert_int_eq(operation_status(TAN), UNARY_OP);
  ck_assert_int_eq(operation_status(SIN), UNARY_OP);
  ck_assert_int_eq(operation_status(COS), UNARY_OP);
  ck_assert_int_eq(operation_status(SQRT), UNARY_OP);
  ck_assert_int_eq(operation_status(LOG), UNARY_OP);
  ck_assert_int_eq(operation_status(LN), UNARY_OP);
  ck_assert_int_eq(operation_status(UPLUS), UNARY_OP);
  ck_assert_int_eq(operation_status(UMINUS), UNARY_OP);
  ck_assert_int_eq(operation_status('^'), BINARY_OP);
  ck_assert_int_eq(operation_status(MOD), BINARY_OP);
  ck_assert_int_eq(operation_status('/'), BINARY_OP);
  ck_assert_int_eq(operation_status('*'), BINARY_OP);
  ck_assert_int_eq(operation_status('+'), BINARY_OP);
  ck_assert_int_eq(operation_status('-'), BINARY_OP);
}
END_TEST

START_TEST(test_push_number) {
  int stack_is_init = 0;
  numbers_stack* stack = NULL;
  push_number(2.22, &stack, &stack_is_init);
  push_number(3.455, &stack, &stack_is_init);
  push_number(45.45, &stack, &stack_is_init);
  push_number(0., &stack, &stack_is_init);
  ck_assert_double_eq(n_pop(&stack), 0.);
  ck_assert_double_eq(n_pop(&stack), 45.45);
  ck_assert_double_eq(n_pop(&stack), 3.455);
  ck_assert_double_eq(n_pop(&stack), 2.22);
  n_destroy(stack);
}
END_TEST

START_TEST(test_execute) {
  ck_assert_double_eq(execute_binary('^', 2., 4.), 16.);
  ck_assert_double_eq(execute_binary(MOD, 5., 2), 1.);
  ck_assert_double_eq(execute_binary('/', 6., 2.), 3.);
  ck_assert_double_eq(execute_binary('*', 6., 3.), 18.);
  ck_assert_double_eq(execute_binary('+', 2., 2.), 4.);
  ck_assert_double_eq(execute_binary('-', 2.25, 1.25), 1.);
  ck_assert_double_eq(execute_unary(ATAN, 1), atan(1));
  ck_assert_double_eq(execute_unary(ASIN, 1), asin(1));
  ck_assert_double_eq(execute_unary(ACOS, 1), acos(1));
  ck_assert_int_eq(fabs(execute_unary(TAN, 1) - tan(1)) < EPS, 1);
  ck_assert_double_eq(execute_unary(SIN, 1), sin(1));
  ck_assert_double_eq(execute_unary(COS, 1), cos(1));
  ck_assert_double_eq(execute_unary(SQRT, 1), sqrt(1));
  ck_assert_double_eq(execute_unary(LOG, 1), log10(1));
  ck_assert_double_eq(execute_unary(LN, 1), log(1));
  ck_assert_double_eq(execute_unary(UMINUS, 1), -1);
  ck_assert_double_eq(execute_unary(UPLUS, 1), 1);
}
END_TEST

START_TEST(test_p_to_d) {
  char buf[100000];
  double x = 2.23;

  infix_to_postfix("sqrt(x ^ 4)", buf);
  double true_result = sqrt(pow(x, 4));
  ck_assert_int_eq(postfix_to_double(buf, x) - true_result < EPS, 1);

  infix_to_postfix("12 + 2.2 * 2 + sqrt(x ^ (2 + 2)) + 6 * (-5)", buf);
  true_result = 12. + 2.2 * 2. + sqrt(pow(x, (2. + 2.))) + 6 * (-5);
  ck_assert_int_eq(postfix_to_double(buf, x) - true_result < EPS, 1);

  infix_to_postfix("sqrt(2.5)", buf);
  true_result = sqrt(2.5);
  ck_assert_int_eq(postfix_to_double(buf, x) - true_result < EPS, 1);
}

TCase* tests_postfix_to_double(void) {
  TCase* tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, stack);
  tcase_add_test(tcase, test_operation_status);
  tcase_add_test(tcase, test_push_number);
  tcase_add_test(tcase, test_execute);
  tcase_add_test(tcase, test_p_to_d);

  return tcase;
}