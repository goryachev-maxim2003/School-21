#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *str) {
    int length = 0;
    for (; str[length]; length++)
        ;
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    return *str1 - *str2;
}

char *s21_strcpy(char *destination, const char *source) {
    for (int i = 0; i <= s21_strlen(source); i++)  //<= чтобы записать 0
        destination[i] = source[i];
    return destination;
}
char *s21_strcat(char *destination, const char *source) {
    int len_d = s21_strlen(destination);
    for (int i = len_d; i <= len_d + s21_strlen(source); i++) {  //<= чтобы записать 0
        destination[i] = source[i - len_d];
    }
    return destination;
}

char *s21_strchr(const char *str, int c) {
    int ind = -1;
    for (int i = 0; i <= s21_strlen(str); i++) {  //<= чтобы записать считать 0
        if (str[i] == c) {
            ind = i;
            break;
        }
    }
    return (ind == -1) ? NULL : (char *)str + ind;
}

char *s21_strstr(const char *haystack, const char *needle) {
    int ind = -1;
    int len_needle = s21_strlen(needle);
    int len_haystack = s21_strlen(haystack);
    for (int i = 0; i < len_haystack; i++) {
        int equal = 1;
        for (int j = 0; j < len_needle; j++) {
            if (needle[j] != haystack[i + j]) {
                equal = 0;
                break;
            }
        }
        if (equal) {
            ind = i;
            break;
        }
    }
    return (ind == -1) ? NULL : (char *)haystack + ind;
}