#include "times.h"

int is_digit(char c);
int is_data(const char *s);

int main() {
    int day, month, year;
    char point1, point2;
    char str[1000] = "../";
    char *filename = strInput(str);
    strcat(str, filename);
    free(filename);
    FILE *file = fopen(str, "rb");
    if (file == NULL) {
        printf("n/a");
    } else {
        if (scanf("%d %c %d %c %d", &day, &point1, &month, &point2, &year) != 5 || point1 != '.' ||
            point2 != '.') {
            printf("n/a");
        } else {
            Time time;
            while (fread(&time, sizeof(Time), 1, file) == 1) {
                if (time.day == day && time.month == month && time.year == year) {
                    printf("%d", time.code);
                }
            }
        }

        // char data[11];
        // char number[11];
        // scanf("%s", data);
        // if (is_data(data)){
        //     printf("n/a");
        // }
        // else{
        //     //printf("%s", data);
        //     strcpy(number, data);
        //     day = atoi(number);
        //     printf("%d\n", day);
        // }

        rewind(file);
        fclose(file);
    }
    return 0;
}

// int is_digit(char c){
//     return (c>='0' && c<='9') ? 1 : 0;
// }
// int is_data(const char* s) {
//     int flag = 1;
//     if(!is_digit(s[0])) flag = 0;
//     else if(!is_digit(s[1])) flag = 0;
//     else if('.' != s[2]) flag = 0;
//     else if(!is_digit(s[3])) flag = 0;
//     else if(!is_digit(s[4])) flag = 0;
//     else if('.' != s[5]) flag = 0;
//     else if(!is_digit(s[6])) flag = 0;
//     else if(!is_digit(s[7])) flag = 0;
//     else if(!is_digit(s[8])) flag = 0;
//     else if(!is_digit(s[9])) flag = 0;
//     return flag;

// }