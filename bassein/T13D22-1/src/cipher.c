#include <stdio.h>
#include <stdlib.h>

char *strInput(char *str);
int intInput(int *num);
int foutput(char *filename);
int fadd(char *filename, char *str);
void cipher(char *filename, int shift);

char *filename = NULL;
int was1 = 0;

int main() {
    int num = -1;
    while (intInput(&num)) {
        if (num == 1) {
            if (filename != NULL) free(filename);
            filename = strInput(filename);
            if (foutput(filename)) was1 = 1;
        } else if (num == 2 && was1) {
            char *str = "";
            str = strInput(str);
            if (fadd(filename, str)) {
                foutput(filename);
            }
            free(str);
            was1 = 0;
        } else if (num == 3) {
            //Отчистка .h
            FILE *f = fopen("ai_modules/m2.h", "w");
            fclose(f);
            f = fopen("ai_modules/m2.h", "w");
            fclose(f);
            //Шифр цезаря
            int shift;
            if (scanf("%d", &shift) == 1) {
                cipher("ai_modules/m1.c", shift);
                cipher("ai_modules/m2.c", shift);
            } else {
                printf("n/a\n");
            }
            while (getchar() != '\n')
                ;
        } else {
            printf("n/a\n");
            was1 = 0;
        }
        num = -1;
    }
    if (filename != NULL) free(filename);
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

int intInput(int *num) {
    int next = 1;
    if (scanf("%d", num) != 1) {  //Не число
        while (getchar() != '\n')
            ;                 //Чтобы произвести чсчитывание без числа
    } else if (*num == -1) {  //-1
        next = 0;
    } else if (getchar() != '\n') {  //не -1, тогда проверяем конец
        printf("n/a\n");
    }
    return next;
}

int foutput(char *filename) {
    char c;
    int flag = 1;
    FILE *file = fopen(filename, "r");
    if (file == NULL || (c = getc(file)) == EOF) {  //Нет файла или пустой
        printf("n/a\n");
        flag = 0;
    } else {
        putc(c, stdout);  //Выводим первый символ(считан из условия выше)
        while ((c = getc(file)) != EOF) putc(c, stdout);
        putc('\n', stdout);
    }
    if (file != NULL) fclose(file);
    return flag;
}

int fadd(char *filename, char *str) {
    int flag = 1;
    FILE *file = fopen(filename, "a");
    if (file == NULL) {  //Нет файла или пустой
        printf("n/a\n");
        flag = 0;
    } else {
        fprintf(file, "%s", str);
        fclose(file);
    }
    return flag;
}

void cipher(char *filename, int shift) {
    char *code = malloc(sizeof(char));
    FILE *file = fopen(filename, "r+");

    if (file == NULL) {
        printf("n/a\n");
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
