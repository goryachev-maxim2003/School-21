#include "times.h"

int main() {
    char str[1000] = "../";
    char *filename = strInput(str);
    strcat(str, filename);
    free(filename);
    FILE *file = fopen(str, "r+b");
    // FILE *file = fopen("../datasets/door_state_2", "r+b");
    int menu_item;
    if (file == NULL || scanf("%d", &menu_item) != 1) {  //Файл
        printf("n/a");
    } else {
        //нулевой пункт - вывод содержимого файла в консоль,
        if (menu_item == 0) {
            timeOutput(file);
        }
        //первый пункт - вывод отсортированного содержимого файла,
        else if (menu_item == 1) {
            quick_sort(file, 0, get_records_count_in_file(file) - 1);
            timeOutput(file);
        }
        //второй пункт - добавление записи и вывод отсортированного содержимого файла на экран.
        else if (menu_item == 2) {
            int year, month, day, hour, minute, second, status, code;
            if (scanf("%d %d %d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second, &status,
                      &code) == 8 &&
                (status == 0 || status == 1)) {
                Time time = {year, month, day, hour, minute, second, status, code};
                fseek(file, 0, SEEK_END);
                fwrite(&time, sizeof(Time), 1, file);
                rewind(file);
                quick_sort(file, 0, get_records_count_in_file(file) - 1);
                timeOutput(file);
                // 1 2 3 4 5 6 7 8
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        rewind(file);
        fclose(file);
    }
    return 0;
}