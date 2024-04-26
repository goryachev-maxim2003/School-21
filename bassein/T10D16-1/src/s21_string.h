#ifndef DATA_STAT_H
#define DATA_STAT_H

int s21_strlen(const char *str);

int s21_strcmp(char *str1, char *str2);

char *s21_strcpy(char *destination, const char *source);

char *s21_strcat(char *destination, const char *source);

char *s21_strchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

#endif