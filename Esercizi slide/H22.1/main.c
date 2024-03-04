#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

FILE *open_file(char *file_name, char *mode);

int close_file(FILE *file_pointer);

float **generate_matrix(int M, int N);

void print_matrix(float **matrix, int M, int N);

void write_matrix_on_file(float **matrix, int M, int N);

void read_file_and_load_matrix();

void read_file_and_load_matrix_while();

void calculation_of_transposed_matrix(float **matrix,int M,int N);


int main() {

    float **matrix = generate_matrix(2, 2);
    write_matrix_on_file(matrix, 2, 2);
    read_file_and_load_matrix();
    read_file_and_load_matrix_while();
    calculation_of_transposed_matrix(matrix,2,2);
    free(matrix);

}

FILE *open_file(char *file_name, char *mode) {
    FILE *fp = fopen(file_name, mode);
    if (fp == NULL) {
        fprintf(stderr, "Errore in fase di apertura");
        perror("");
        exit(-1);
    } else
        printf("\nFile open whith success\n");
    return fp;
}

int close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("\n Error closing file ..");
        exit(-1);

    } else {
        printf("\nFile closed with success\n");
        return 0;
    }
}

float **generate_matrix(int M, int N) {
    float **matrix = malloc(sizeof(float *) * M);
    for (int i = 0; i < M; ++i) {
        matrix[i] = malloc(sizeof(float) * N);
    }
    srand(time(NULL));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() / (1.0 * RAND_MAX);
        }
    }
    print_matrix(matrix, M, N);
    return matrix;
}

void print_matrix(float **matrix, int M, int N) {
    printf("\n_________MATRIX__________\n");
    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < M; ++j) {
            printf("%f\t", matrix[i][j]);
        }
    }
    printf("\n_________MATRIX__________\n");
}

void write_matrix_on_file(float **matrix, int M, int N) {
    printf("\n_________________Write matrix________________\n");
    FILE *fp = open_file("output.txt", "a");
    int ret;
    if ((ret = fprintf(fp, "%d   %d \n", N, M)) < 0) {
        fprintf(stderr, "\nWrite error\n");
    } else {
        for (int i = 0; i < M; ++i) {
            fprintf(fp, "\n");
            for (int j = 0; j < N; ++j) {
                if ((ret = fprintf(fp, "%f\t", matrix[i][j])) < 0) {
                    perror("\n Error writing to file ..");
                    break;
                }
            }
        }
        fflush(fp);
    }
    printf("\n_________________Write matrix________________\n");
    close_file(fp);
}

void read_file_and_load_matrix() {
    int ret;

    FILE *fp = open_file("output.txt", "r");
    int N, M;
    if ((ret = fscanf(fp, "%d   %d", &N, &M)) < 0) {
        fprintf(stderr, "Read Error");
    }
    printf("\nN->%d  M->%d\n", N, M);
    float **matrix = malloc(sizeof(float *) * M);
    for (int i = 0; i < M; ++i) {
        matrix[i] = malloc(sizeof(float) * N);
    }
    for (int i = 0; i < N; ++i) {
        fscanf(fp, "\n");
        for (int j = 0; j < M; ++j) {
            fscanf(fp, "%f", &matrix[i][j]);
        }
    }
    print_matrix(matrix, N, M);
    free(matrix);
    close_file(fp);
}

void read_file_and_load_matrix_while() {
    int ret;
    FILE *fp = open_file("output.txt", "r");
    int N, M;
    if ((ret = fscanf(fp, "%d   %d", &N, &M)) < 0) {
        fprintf(stderr, "Read Error");
    }
    float **matrix = malloc(sizeof(float *) * M);
    for (int i = 0; i < M; ++i) {
        matrix[i] = malloc(sizeof(float) * N);
    }
    int i = 0;
    int j = 0;
    while (i < M) {
        fscanf(fp, "\n");
        while (i < N) {
            fscanf(fp, "%f", &matrix[i][j]);
            i++;
        }
        j++;
    }
    print_matrix(matrix, N, M);
    free(matrix);
    close_file(fp);
}

void calculation_of_transposed_matrix(float **matrix,int M,int N){
    printf("\n_________________Write matrix________________\n");
    FILE *fp = open_file("output.txt", "a");
    int ret;
    if ((ret = fprintf(fp, "%d   %d \n", N, M)) < 0) {
        fprintf(stderr, "\nWrite error\n");
    } else {
        for (int j = 0; j < M; ++j) {
            fprintf(fp, "\n");
            for (int i = 0; i < N; ++i) {
                if ((ret = fprintf(fp, "%f\t", matrix[i][j])) < 0) {
                    perror("\n Error writing to file ..");
                    break;
                }
            }
        }
        fflush(fp);
    }
    printf("\n_________________Write matrix________________\n");
    close_file(fp);
}