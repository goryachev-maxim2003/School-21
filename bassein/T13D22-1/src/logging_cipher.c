#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"
#define LOG_FILE "log.log"
#define LOG_LEN_MESSAGE 1000

#define START_MESSAGE "program started;"
#define CONTENT_MESSAGE1 "The contents of the file \""
#define CONTENT_MESSAGE2 "\" have been dumped;"
#define CLEANED_FILES_MESSAGE "Files m1.h and m2.h from derectory /ai_module were cleaned;"
#define CIPHER_MESSAGE \
    "Files m1.c and m2.c from derectory /ai_module was cleaned were encrypted with the Caesar cipher;"
#define SHIFT_ERROR_MESSAGE "Shift in the Caesar cipher must be a number;"
#define MENU_ERROR_MESSAGE "Menu item does not exist or requires additional action;"
#define END_MESSAGE "program ended;"
#define MENU_ERROR_MESSAGE_IN_FUNCTION "Menu item does not exist;"
#define FILE_ERROR_MESSAGE "File does not exist or file is empty;"

char *strInput(char *str);
int intInput(int *num, FILE *log_file);
int foutput(char *filename, FILE *log_file);
int fadd(char *filename, char *str, FILE *log_file);
void cipher(char *filename, int shift, FILE *log_file);

char *filename = NULL;
int was1 = 0;

int main() {
    FILE *log_file = log_init(LOG_FILE);
    logcat(log_file, START_MESSAGE, info);
    int num = -1;
    char log_message[LOG_LEN_MESSAGE];
    while (intInput(&num, log_file)) {
        if (num == 1) {
            if (filename != NULL) free(filename);
            filename = strInput(filename);
            if (foutput(filename, log_file)) {
                was1 = 1;
                // log open
                strcpy(log_message, "File \"");
                strcat(log_message, filename);
                strcat(log_message, "\" open;");
                logcat(log_file, log_message, info);
            };
        } else if (num == 2 && was1) {
            char *str = "";
            str = strInput(str);
            if (fadd(filename, str, log_file)) {
                foutput(filename, log_file);
                strcpy(log_message, CONTENT_MESSAGE1);
                strcat(log_message, filename);
                strcat(log_message, CONTENT_MESSAGE2);
                logcat(log_file, log_message, info);
            }
            free(str);
            was1 = 0;
        } else if (num == 3) {
            //Отчистка .h
            FILE *f = fopen("ai_modules/m2.h", "w");
            fclose(f);
            f = fopen("ai_modules/m2.h", "w");
            fclose(f);
            logcat(log_file, CLEANED_FILES_MESSAGE, info);
            //Шифр цезаря
            int shift;
            if (scanf("%d", &shift) == 1) {
                cipher("ai_modules/m1.c", shift, log_file);
                cipher("ai_modules/m2.c", shift, log_file);
                logcat(log_file, CIPHER_MESSAGE, info);
            } else {
                printf("n/a\n");
                logcat(log_file, SHIFT_ERROR_MESSAGE, warning);
            }
            while (getchar() != '\n')
                ;
        } else {
            printf("n/a\n");
            logcat(log_file, MENU_ERROR_MESSAGE, warning);
            was1 = 0;
        }
        num = -1;
    }
    if (filename != NULL) free(filename);

    logcat(log_file, END_MESSAGE, info);
    log_close(log_file);
    return 0;
}

char *strInput(char *str) {
    str = malloc(sizeof(char));
    char ch;
    int len = 0;
    ch = getchar();
    while (ch != '\n') {
        str[len] = ch;
        str = realloc(str, sizeof(char) * (++len + 1));
        ch = getchar();
    }
    str[len] = '\0';
    return str;
}

int intInput(int *num, FILE *log_file) {
    int next = 1;
    if (scanf("%d", num) != 1) {  //Не число
        while (getchar() != '\n')
            ;                 //Чтобы произвести считывание без числа
    } else if (*num == -1) {  //-1
        next = 0;
    } else if (getchar() != '\n') {  //не -1, тогда проверяем конец
        printf("n/a\n");
        logcat(log_file, MENU_ERROR_MESSAGE_IN_FUNCTION, warning);
    }
    return next;
}

int foutput(char *filename, FILE *log_file) {
    char c;
    int flag = 1;
    FILE *file = fopen(filename, "r");
    if (file == NULL || (c = getc(file)) == EOF) {  //Нет файла или пустой
        printf("n/a\n");
        logcat(log_file, FILE_ERROR_MESSAGE, warning);
        flag = 0;
    } else {
        putc(c, stdout);  //Выводим первый символ(считан из условия выше)
        while ((c = getc(file)) != EOF) putc(c, stdout);
        putc('\n', stdout);
    }
    if (file != NULL) fclose(file);
    return flag;
}

int fadd(char *filename, char *str, FILE *log_file) {
    int flag = 1;
    FILE *file = fopen(filename, "a");
    if (file == NULL) {  //Нет файла или пустой
        printf("n/a\n");
        logcat(log_file, FILE_ERROR_MESSAGE, warning);
        flag = 0;
    } else {
        fprintf(file, "%s", str);
        fclose(file);
    }
    return flag;
}

void cipher(char *filename, int shift, FILE *log_file) {
    char *code = malloc(sizeof(char));
    FILE *file = fopen(filename, "r+");

    if (file == NULL) {
        printf("n/a\n");
        logcat(log_file, FILE_ERROR_MESSAGE, warning);
    } else {
        int len = 0;
        char c;
        while ((c = getc(file)) != EOF) {
            code[len] = c;
            char *new_data = realloc(code, sizeof(char) * (++len + 1));
            if (new_data != NULL) code = new_data;
        }
        code[len] = '\0';
        rewind(file);
        for (char *p = code; *p != '\0'; p++) {
            if (*code >= 'A' && *p <= 'Z') {
                fprintf(file, "%c", 'A' + (*p - 'A' + shift) % 26);
            } else if (*p >= 'a' && *p <= 'z') {
                fprintf(file, "%c", 'a' + (*p - 'a' + shift) % 26);
            } else {
                fprintf(file, "%c", *p);
            }
        }
        fclose(file);
    }
    if (code != NULL) free(code);
}