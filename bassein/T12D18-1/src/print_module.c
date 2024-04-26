#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t now;
    time(&now);
    struct tm* local = localtime(&now);
    printf("%s %02d:%02d:%02d ", Log_prefix, local->tm_hour, local->tm_min, local->tm_sec);
    for (; *message != '\0'; message++) print(*message);
}
// new