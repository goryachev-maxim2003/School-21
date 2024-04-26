#include <stdio.h>
struct my_struct
{};

//Функция чтения записи заданного типа из файла по ее порядковому номеру.
struct my_struct read_record_from_file(FILE *pfile, int index)
{
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);

    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    rewind(pfile);
    return record;
}

//Функция записи записи указанного типа в файл по указанному порядковому номеру.
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index)
{
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

// Функция взаимного переноса двух записей в файле по их индексам.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2)
{
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

// Функция для получения размера файла в байтах.
int get_file_size_in_bytes(FILE *pfile)
{
    int size = 0;
    fseek(pfile, 0, SEEK_END);    
    size = ftell(pfile);        
    rewind(pfile);              
    return size;
}

//Функция для получения количества записей в файле
int get_records_count_in_file(FILE *pfile)
{
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}
