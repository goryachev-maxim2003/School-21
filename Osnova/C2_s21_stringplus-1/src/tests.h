#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include "s21_string.h"
#include <check.h>
#include <string.h>

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

TCase *s21_insert_test(void);
TCase *s21_memchr_test(void);
TCase *s21_memcmp_test(void);
TCase *s21_memcpy_test(void);
TCase *s21_memset_test(void);
TCase *s21_sprintf_test(void);
TCase *s21_strchr_test(void);
TCase *s21_strcspn_test(void);
TCase *s21_strerror_test(void);
TCase *s21_strlen_test(void);
TCase *s21_strncat_test(void);
TCase *s21_strncmp_test(void);
TCase *s21_strncpy_test(void);
TCase *s21_strpbrk_test(void);
TCase *s21_strrchr_test(void);
TCase *s21_strstr_test(void);
TCase *s21_strtok_test(void);
TCase *s21_to_lower_test(void);
TCase *s21_to_upper_test(void);
TCase *s21_trim_test(void);

#endif  // SRC_S21_TEST_H_