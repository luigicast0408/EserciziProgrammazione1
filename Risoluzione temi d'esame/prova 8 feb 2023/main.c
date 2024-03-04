#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct input {
    const char *file_name_in;
    const char *file_name_out;
} input;

bool read_parameters(int argc, char *argv[], input *in);
bool check_input(const char *file_name_in, const char *file_name_out);
FILE *open_file(const char *file_name, char *mode);
void close_file(FILE *file_pointer);
double ***allocate_matrix(int rows, int cols);
void create_matrix(double ***matrix, int rows, int cols, input in);
void print_matrix(double ***matrix, int rows, int cols);
double average_row(double *vector, int size);
void sparsify(double ***matrix, int rows, int cols);
void collect(double ***matrix, int rows, int cols, input in);
void print_vector(double *vector, int size);
void write_to_file_vector(double *vector, int size, input in);
void deallocate_matrix(double ***matrix, int rows, int cols);

int main(int argc, char *argv[]) {
    input in;
    if (read_parameters(argc, argv, &in) == true) {
        int rows, cols;
        printf("\nEnter number of rows:\n");
        scanf("%d", &rows);

        printf("\nEnter number of columns:\n");
        scanf("%d", &cols);

        double ***matrix = allocate_matrix(rows, cols);
        create_matrix(matrix, rows, cols, in);
        print_matrix(matrix, rows, cols);

        sparsify(matrix, rows, cols);
        print_matrix(matrix, rows, cols);

        collect(matrix, rows, cols, in);
        deallocate_matrix(matrix, rows, cols);
    }
    return 0;
}

bool read_parameters(int argc, char *argv[], input *in) {
    if (argc < 3) {
        fprintf(stderr, "Error in main() parameters.\n");
        return false;
    }
    in->file_name_in = argv[1];
    in->file_name_out = argv[2];
    printf("IN->%s, OUT->%s\n", in->file_name_in, in->file_name_out);
    return check_input(in->file_name_in, in->file_name_out);
}

bool check_input(const char *file_name_in, const char *file_name_out) {
    if (strlen(file_name_in) > 255 || strlen(file_name_out) > 255) {
        fprintf(stderr, "File name length exceeds 255 characters.\n");
        return false;
    } else {
        printf("File name parameters meet the program's specifications.\n");
    }
    return true;
}

FILE *open_file(const char *file_name, char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("File opened successfully (file name->%s, mode->%s)\n", file_name, mode);
        return file_pointer;
    } else {
        fprintf(stderr, "Error opening file %s\n", file_name);
        perror("");
        exit(-1);
    }
}

void close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("Error closing file.");
        exit(-1);
    } else {
        printf("File closed successfully.\n");
    }
}

double ***allocate_matrix(int rows, int cols) {
    double ***matrix = malloc(rows * sizeof(double **));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(double *));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = malloc(sizeof(double));
        }
    }
    return matrix;
}

void create_matrix(double ***matrix, int rows, int cols, input in) {
    FILE *fp = open_file(in.file_name_in, "r");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(fp, "%lf", &(*matrix[i][j]));
        }
    }
    close_file(fp);
}

void print_matrix(double ***matrix, int rows, int cols) {
    printf("\n____________Matrix____________\n");
    for (int i = 0; i < rows; ++i) {
        printf("\n");
        for (int j = 0; j < cols; ++j) {
            printf("%f\t", *matrix[i][j]);
        }
    }
    printf("\n____________Matrix____________\n");
}

double average_row(double *vector, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += vector[i];
    }
    return (sum / size);
}

void sparsify(double ***matrix, int rows, int cols) {
    double row[cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            row[j] = *matrix[i][j];
        }
        double avg = average_row(row, cols);
        for (int j = 0; j < cols; ++j) {
            if (*matrix[i][j] < avg) {
                *matrix[i][j] = 0.0;
            }
        }
    }
}

void collect(double ***matrix, int rows, int cols, input in) {
    double *vector = malloc(sizeof(double) * (rows * cols));
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (*matrix[i][j] != 0.0) {
                vector[count++] = *matrix[i][j];
            }
        }
    }
    write_to_file_vector(vector, count, in);
    print_vector(vector, count);
    free(vector);
}

void print_vector(double *vector, int size) {
    printf("\n________VECTOR_______\n");
    for (int i = 0; i < size; ++i) {
        printf("%f\t", vector[i]);
    }
    printf("\n________VECTOR_______\n");
}

void write_to_file_vector(double *vector, int size, input in) {
    FILE *fp = open_file(in.file_name_out, "w");
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%f\t", vector[i]);
    }
    close_file(fp);
}

void deallocate_matrix(double ***matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}