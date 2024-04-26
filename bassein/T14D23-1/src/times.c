#include "times.h"

void timeOutput(FILE *file) {
    Time time;
    while (fread(&time, sizeof(Time), 1, file) == 1)
        printf("%d %d %d %d %d %d %d %d\n", time.year, time.month, time.day, time.hour, time.minute,
               time.second, time.status, time.code);
    rewind(file);
}

Time read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(Time);
    fseek(pfile, offset, SEEK_SET);
    Time record;
    fread(&record, sizeof(Time), 1, pfile);
    rewind(pfile);
    return record;
}

void write_record_in_file(FILE *pfile, const Time *record_to_write, int index) {
    int offset = index * sizeof(Time);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(Time), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    Time record1 = read_record_from_file(pfile, record_index1);
    Time record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(Time); }

void quick_sort(FILE *file, int first, int last) {
    if (first < last) {
        int left = first, right = last;
        Time middle = read_record_from_file(file, (left + right) / 2);
        do {
            while (compare(read_record_from_file(file, left), middle) == -1) left++;
            while (compare(read_record_from_file(file, right), middle) == 1) right--;

            if (left <= right) {
                swap_records_in_file(file, left, right);
                left++;
                right--;
            }
        } while (left <= right);

        quick_sort(file, first, right);
        quick_sort(file, left, last);
    }
}

int compare(Time time1, Time time2) {  // 0 - равно, -1 - первый меньше, 1 - второй меньше
    int flag = 0;
    if (time1.year < time2.year)
        flag = -1;
    else if (time1.year > time2.year)
        flag = 1;
    else {
        if (time1.month < time2.month)
            flag = -1;
        else if (time1.month > time2.month)
            flag = 1;
        else {
            if (time1.day < time2.day)
                flag = -1;
            else if (time1.day > time2.day)
                flag = 1;
            else {
                if (time1.hour < time2.hour)
                    flag = -1;
                else if (time1.hour > time2.hour)
                    flag = 1;
                else {
                    if (time1.minute < time2.minute)
                        flag = -1;
                    else if (time1.minute > time2.minute)
                        flag = 1;
                    else {
                        if (time1.second < time2.second)
                            flag = -1;
                        else if (time1.second > time2.second)
                            flag = 1;
                    }
                }
            }
        }
    }
    return flag;
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