#include <stdio.h>
#include <stdlib.h>


void printfile(FILE *file);

int main(int argc, char** argv){
    // FILE *file;
    // if (argc==2){
    //     char* file_name  = argv[1];
    //     FILE *file = fopen(argv[1], "r");
    //     if (file==NULL){
    //         printf("n/a");
    //     }
    //     else{
    //         printfile(file);
    //     }
    // }
    // fclose(file);
    printf("asdasd");
    return 0;
}

void printfile(FILE *file){
    char ch;
    while((ch=getc (file)) != EOF)
        printf ("%c", ch);
}