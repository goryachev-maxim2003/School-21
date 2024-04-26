#include "../tests.h"

START_TEST(stack) {
  operations_stack* stack = init(op('c', 1));
  ck_assert_int_eq(stack->op.value, 'c');
  ck_assert_int_eq(stack->op.priority, 1);
  ck_assert_int_eq(stack->next == NULL, 1);
  push(&stack, op('s', 2));
  ck_assert_int_eq(stack->op.value, 's');
  ck_assert_int_eq(stack->op.priority, 2);
  ck_assert_int_eq(stack->next->op.value, 'c');
  ck_assert_int_eq(stack->next->op.priority, 1);
  operation o = pop(&stack);
  ck_assert_int_eq(o.value, 's');
  ck_assert_int_eq(o.priority, 2);
  ck_assert_int_eq(stack->op.value, 'c');
  ck_assert_int_eq(stack->op.priority, 1);
  ck_assert_int_eq(stack->next == NULL, 1);
  push(&stack, op('!', 3));
  ck_assert_int_eq(stack->op.value, '!');
  ck_assert_int_eq(stack->op.priority, 3);
  ck_assert_int_eq(stack->next->op.value, 'c');
  ck_assert_int_eq(stack->next->op.priority, 1);
  o = pop(&stack);
  ck_assert_int_eq(o.value, '!');
  ck_assert_int_eq(o.priority, 3);
  ck_assert_int_eq(stack->op.value, 'c');
  ck_assert_int_eq(stack->op.priority, 1);

  push(&stack, op('c', 1));
  push(&stack, op('c', 1));
  push(&stack, op('s', 2));
  push(&stack, op('k', 5));
  destroy(stack);
}
END_TEST

START_TEST(test_operation_to_struct) {
  char symbols[NUMBER_OF_OPERATIONS + 2] = {
      ATAN, ASIN, ACOS, SQRT, TAN, SIN, COS, MOD,   LN,    LOG,
      '^',  '(',  ')',  '/',  '*', '+', '-', UPLUS, UMINUS};
  int priotiry[NUMBER_OF_OPERATIONS + 2] = {3, 3, 3, 3, 3, 3, 3, 2, 3, 3,
                                            4, 5, 5, 2, 2, 1, 1, 3, 3};
  const char* str = "atan asin acos sqrt tan sin cos mod ln log ^ ( ) / * + -";
  int i = 0;
  operation o = op('\0', 0);
  for (const char* p = str; *p != '\0'; p++) {
    if (*p == ' ') continue;
    o = operation_to_struct(&p, 0);
    ck_assert_int_eq(o.value, symbols[i]);
    ck_assert_int_eq(o.priority, priotiry[i]);
    i++;
  }
  const char* p = "+-";
  o = operation_to_struct(&p, 1);
  ck_assert_int_eq(o.value, UPLUS);
  ck_assert_int_eq(o.priority, 3);
  p++;
  o = operation_to_struct(&p, 1);
  ck_assert_int_eq(o.value, UMINUS);
  ck_assert_int_eq(o.priority, 3);
}
END_TEST

TCase* tests_infix_to_postfix(void) {
  TCase* tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, stack);
  tcase_add_test(tcase, test_operation_to_struct);

  return tcase;
}