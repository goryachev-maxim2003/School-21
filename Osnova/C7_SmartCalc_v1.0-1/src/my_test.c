#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_GUI_functions.h"
#include "s21_calculate.h"
#include "s21_creditCalc.h"
#include "s21_depositCalc.h"
#include "s21_infix_to_postfix.h"
#include "s21_postfix_to_double.h"
#include "s21_validation.h"

void print(double n) { printf("%lf\n", n); }
int main() {
  double interest_charges;
  double tax_sum;
  double end_sum;

  addSum a = {1, 3000, 2};
  addSum b = {2, -9000, 3};
  addSum c = {1, 4000, 2};

  int k = 3;
  addSum *arr = calloc(k, sizeof(addSum));
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;

  depositCalc(500000, 9, 50, 13, MONTHLY, WITH_CAPITALIZATION,
              &interest_charges, &tax_sum, &end_sum, arr, k);
  printf("interest_charges = %lf, tax_sum = %lf, end_sum = %lf\n",
         interest_charges, tax_sum, end_sum);

  free(arr);
  return 0;
}