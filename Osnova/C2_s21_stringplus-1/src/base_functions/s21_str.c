#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *result = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int res = INT_MAX;
  s21_size_t i = 0;
  while (i < s21_strlen(str1)) {
    s21_size_t j = 0;
    int tmp = 0, flag = 0;
    while (j < s21_strlen(str2)) {
      if (str1[i] == str2[j]) {
        flag = 1;
        tmp = i;
        break;
      }
      j++;
    }
    i++;
    if (tmp < res && flag) {
      res = tmp;
    }
  }
  return res == INT_MAX ? (int)s21_strlen(str1) : res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++) {
  };
  return len;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t l = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++, l++) {
    dest[l] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  while (i < n) {
    if (str1[i] < str2[i]) {
      res = -(str2[i] - str1[i]);
    }
    if (str1[i] > str2[i]) {
      res = str1[i] - str2[i];
    }
    if (res != 0) {
      break;
    }
    i++;
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t index = 0;
  while (index < n && src[index] != '\0') {
    dest[index] = src[index];
    index++;
  }
  if (s21_strlen(src) < n) {
    while (index < s21_strlen(dest)) {
      dest[index] = '\0';
      index++;
    }
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        res = (str1 + i);
        break;
      }
    }
    if (res != s21_NULL) {
      break;
    }
  }
  return (char *)res;
}

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      res = (str + i);
    }
  }
  return (char *)res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(haystack); i++) {
    if (haystack[i] == needle[0]) {
      int flag = 1;
      for (s21_size_t j = i, k = 0;
           j < s21_strlen(haystack) && k < s21_strlen(needle); j++, k++) {
        if (haystack[j] != needle[k]) {
          flag = 0;
        }
      }
      if (flag) {
        res = (haystack + i);
        break;
      }
    }
  }
  return (char *)res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *buf;
  if (str != s21_NULL) {
    buf = str;
  }
  char *token = buf;
  if (buf[0] == '\0') {
    token = s21_NULL;
  } else {
    int flag = 0;
    for (char *b = buf; *b != '\0'; b++) {
      for (const char *d = delim; *d != '\0'; d++) {
        if (*b == *d) {
          *b = '\0';
          buf = b + 1;
          if (b == token) {
            token++;
            continue;
          }
          flag = 1;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
  }
  return token == s21_NULL ? 0 : s21_strlen(token) > 0 ? token : s21_NULL;
}