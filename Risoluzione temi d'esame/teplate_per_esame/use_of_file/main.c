#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);

int main()
{

}

FILE *open_file(const char *file_name, const char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("\nFile opened successfully (file name->%s, mode->%s)\n", file_name, mode);
        return file_pointer;
    } else {
        perror("Error opening file");
        exit(-1);
    }
}

void close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("\nError closing file ..");
        exit(-1);
    } else {
        printf("\nFile closed with success\n");
    }
}
