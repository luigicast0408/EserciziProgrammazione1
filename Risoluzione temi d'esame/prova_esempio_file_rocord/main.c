#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORD 200

typedef struct input {
    const char *file_name_in;
    const char *file_name_out;
} input;

typedef struct record {
    char key[30]; // FM 21! 
    int length;
} record;

bool read_input(input *in, int argc, char *argv[]);
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);
record *build_vector(input in, int *size);
bool check_len_string(char *string);
char *remove_symbols(char string[30]);
void filter(record *rec_vet, int size);
void print_vector(record *rec_vet, int size);
void delete_record_duplicates(record *rec_vet, int size);
void write_on_file(input in, record *rec_vec, int size);
void read_file(input in);

int main(int argc, char *argv[]) {
    input in;
    if (read_input(&in, argc, argv) == false) {
        fprintf(stderr, "Error on parameter main()");
    }
    int size;
    record *rec_vector = build_vector(in, &size);
    print_vector(rec_vector, size);

    filter(rec_vector, size);
    print_vector(rec_vector, size);

    delete_record_duplicates(rec_vector, size);
    print_vector(rec_vector, size);

    write_on_file(in, rec_vector, size);
    read_file(in);
    free(rec_vector);
}

bool read_input(input *in, int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Incorrect number of parameters for main()\n");
        return false;
    }
    in->file_name_in = argv[1];
    in->file_name_out = argv[2];
    return true;
}

FILE *open_file(const char *file_name, const char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("File opened successfully (file name: %s, mode: %s)\n", file_name, mode);
        return file_pointer;
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}

void close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    } else {
        printf("File closed with success\n");
    }
}

bool check_len_string(char string[30]) {
    return strlen(string) > 30;
}

record *build_vector(input in, int *size) {
    record *rec_vector = malloc(MAX_RECORD * sizeof(struct record));
    FILE *fp = open_file(in.file_name_in, "r");
    char string[21];
    int count = 0;

    while (fscanf(fp, "%s", string) == 1 && count < MAX_RECORD) {
        strcpy(rec_vector[count].key, string);
        rec_vector[count].length = strlen(rec_vector[count].key);
        count++;
    }
    *size = count - 1;
    printf("\n count->%d\n", *size);
    close_file(fp);
    return rec_vector;
}

char *remove_symbols(char string[30]) {
    char *string_s = strdup(string);
    if (string_s[strlen(string) - 1] == ',' || string_s[strlen(string) - 1] == ';' ||
        string_s[strlen(string) - 1] == '.') {
        string_s[strlen(string) - 1] = '\0';
        printf("Detected punctuation (%s) and filtered it (%s)\n", string, string_s);
    }
    return string_s;
}

void filter(record *rec_vet, int size) {
    printf("\n________________________FILTER_____________\n");
    for (int i = 0; i < size; ++i) {
        char *filtered_string = remove_symbols(rec_vet[i].key);
        strcpy(rec_vet[i].key, filtered_string);
        rec_vet[i].length = strlen(rec_vet[i].key) - 1;
        free(filtered_string);
    }
    printf("\n________________________FILTER_____________\n");
}

void print_vector(record *rec_vet, int size) {
    printf("\n____________VECTOR___________\n");
    for (int i = 0; i < size; ++i) {
        if (rec_vet[i].length > 0) {
            printf("\nrecord[%d]->key(%s) length->(%d)\n", i, rec_vet[i].key, rec_vet[i].length);
        }
    }
    printf("____________VECTOR___________\n");
}

void delete_record_duplicates(record *rec_vet, int size) {
    printf("\n________________________DELETE_____________\n");
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size - 1; ++j) {
            if ((strcmp(rec_vet[i].key, rec_vet[j].key) == 0)) {
                printf("\nFind a duplicate record at the posizion %d (%s,%s) with len %d\n", i, rec_vet[i].key,
                       rec_vet[j].key, rec_vet[j].length);
                rec_vet[j].length = -1;
                //printf("\nFind a duplicate record at the posizion %d (%s,%s) with len %d\n",i,rec_vet[i].key,rec_vet[j].key,rec_vet[j].length);
            }
        }
    }
    printf("\n________________________DELETE_____________\n");
}

void write_on_file(input in, record *rec_vec, int size) {
    printf("\n______WRITE ON FILE___________\n");
    FILE *fp = open_file(in.file_name_out, "wb");
    for (int i = 0; i < size; ++i) {
        if (rec_vec[i].length > 0) {
            fwrite(&(rec_vec[i]), 1, sizeof(record), fp);
            fprintf(fp, "\n");
        }
    }
    close_file(fp);
    printf("\n______WRITE ON FILE___________\n");
}


void read_file(input in) {
    record rec;
    FILE *fp = open_file(in.file_name_out, "rb");
    printf("\n______READ FILE___________\n");

    while (fread(&rec, sizeof(record), 1, fp) == 1 && strcmp(rec.key,"")!=0)   {
        if (rec.length != -1) {
            printf("Read record->key(%s) length->(%d)\n", rec.key, rec.length);
        }
    }

    close_file(fp);
    printf("\n______READ FILE___________\n");
}