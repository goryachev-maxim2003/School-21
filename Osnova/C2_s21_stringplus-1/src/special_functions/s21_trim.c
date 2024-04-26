#include "../s21_string.h"

char *Substring(const char *str, s21_size_t from, s21_size_t to) {
  char *sub = (char *)s21_NULL;
  s21_size_t length = to - from;

  sub = (char *)calloc(sizeof(char) * (length) + 1, 1);
  if (sub) {
    for (s21_size_t i = from; i < to; i++) {
      sub[i - from] = str[i];
    }
  }
  return sub;
}

void *s21_trim(const char *str, const char *trim_chars) {
  char *result = (char *)s21_NULL;
  if (str) {
    s21_size_t stringLength = (str == s21_NULL) ? 0 : s21_strlen(str);
    s21_size_t lastTrimCharLocationStart, lastTrimCharLocationEnd;
    int firstNonTrimCharFound;
    if (trim_chars) {
      /* Find whitepaces at the start. */
      lastTrimCharLocationStart = 0;
      firstNonTrimCharFound = 0;
      for (s21_size_t i = 0; i < stringLength && !firstNonTrimCharFound; i++) {
        if (s21_strchr(trim_chars, (int)str[i])) {
          lastTrimCharLocationStart = i + 1;
        } else {
          firstNonTrimCharFound = 1;
        }
      }

      /* Find whitepaces at the end. */
      lastTrimCharLocationEnd = stringLength;
      firstNonTrimCharFound = 0;
      for (long int i = stringLength - 1; i >= 0 && !firstNonTrimCharFound;
           i--) {
        if (s21_strrchr(trim_chars, (int)str[i])) {
          lastTrimCharLocationEnd = i;
        } else {
          firstNonTrimCharFound = 1;
        }
      }
      if (lastTrimCharLocationStart < lastTrimCharLocationEnd) {
        result =
            Substring(str, lastTrimCharLocationStart, lastTrimCharLocationEnd);
      } else {
        result = Substring(str, stringLength, stringLength);
      }
    } else
      result = Substring(str, 0, stringLength);
  }
  return result;
}