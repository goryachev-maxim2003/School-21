#include "logger.h"

#include <time.h>

#include "log_levels.h"

FILE *log_init(char *filename) {
    FILE *file = fopen(filename, "w");
    return file;
}

char *get_status(int status) {
    char *status_name;
    switch (status) {
        case debug:
            status_name = "DEBUG";
            break;
        case trace:
            status_name = "TRACE";
            break;
        case info:
            status_name = "INFO";
            break;
        case warning:
            status_name = "WARNING";
            break;
        case error:
            status_name = "ERROR";
            break;
    }
    return status_name;
}

int logcat(FILE *log_file, char *message, log_level level) {
    int flag = 1;
    if (log_file == NULL) {
        flag = 0;
    } else {
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        fprintf(log_file, "%s ", get_status(level));
        fprintf(log_file, "%02d:%02d:%02d ", local->tm_hour, local->tm_min, local->tm_sec);
        for (; *message != '\0'; message++) fprintf(log_file, "%c", *message);
        fprintf(log_file, "%c", '\n');
    }
    return flag;
}

int log_close(FILE *log_file) {
    int flag = 1;
    if (fclose(log_file) == EOF) flag = 0;
    return flag;
}