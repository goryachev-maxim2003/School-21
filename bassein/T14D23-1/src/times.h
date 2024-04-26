#ifndef TIMES_H
#define TIMES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year, month, day, hour, minute, second, status, code;
} Time;

void timeOutput(FILE *file);
Time read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const Time *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void quick_sort(FILE *file, int first, int last);
int compare(Time time1, Time time2);

char *strInput(char *str);

#endif