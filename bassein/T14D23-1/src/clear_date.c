#include "times.h"

int is_digit(char c);
int is_data(const char *s);

int main() {
    int day1, month1, year1, day2, month2, year2;
    char point1, point2, point3, point4, space;
    char str[1000] = "../";
    char *filename = strInput(str);
    strcat(str, filename);
    free(filename);
    FILE *file = fopen(str, "rb");
    if (file == NULL) {
        printf("n/a");
    } else {
        if (scanf("%d %c %d %c %d %c %d %c %d %c %d", &day1, &point1, &month1, &point2, &year1, &space, &day2, &point3, &month2, &point4, &year2) != 11 || point1 != '.' ||
            point2 != '.' || point3 != '.' || point4 != '.') {
            printf("n/a");
        } else {
            Time time;
            while (fread(&time, sizeof(Time), 1, file) == 1) {
                if (time.day > day1 && time.month == month1 && time.year == year1) {
                    printf("%d", time.code);
                }
            }
        }

        rewind(file);
        fclose(file);
    }
    return 0;
}