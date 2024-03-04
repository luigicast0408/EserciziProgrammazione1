#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

typedef struct input {
    int a;
    int b;
    double alpha;
    double beta;
} input;

bool readInput(input *check, int argc, char *argv[]);

bool check_input(int a, int b, double alpha, double beta);

double ***allocate_matrix(int rows, int cols);

void fill_matrix(double ***matrix, int rows, int cols, input in);

void print_matrix(double ***matrix, int rows, int cols);

double ***transposeMatrix(double ***matrix, int rows, int cols);

void deallocate_matrix(double ***matrix, int rows,int cols);


int main(int argc, char *argv[]) {
    input in;
    if (!readInput(&in, argc, argv)) {
        fprintf(stderr, "Errore di input\n");
        return 1;
    }

    int rows = in.a;
    int cols = in.b;

    double ***matrix = allocate_matrix(rows, cols);
    fill_matrix(matrix, rows, cols, in);
    print_matrix(matrix, rows, cols);

    double ***tr_matrix = transposeMatrix(matrix, rows, cols);
    print_matrix(tr_matrix, cols, rows);  // Nota il cambio di righe e colonne

    deallocate_matrix(matrix, rows, cols);
    deallocate_matrix(tr_matrix, cols, rows);  // Nota il cambio di righe e colonne

    return 0;
}
bool readInput(input *check, int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Errore nei parametri della funzione main()");
        return false;
    }

    char *ptr1, *ptr2, *ptr3, *ptr4;
    check->a = strtol(argv[1], &ptr1, 10);
    check->b = strtol(argv[2], &ptr2, 10);
    check->alpha = strtof(argv[3], &ptr3);
    check->beta = strtof(argv[4], &ptr4);

    return check_input(check->a, check->b, check->alpha, check->beta);
}

bool check_input(int a, int b, double alpha, double beta) {
    if (a >= 5 && a <= 20) {
        printf("\n il parametro (a) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (a) non rispetta le specifiche\n");
        return false;
    }

    if (b >= 5 && b <= 20) {
        printf("\n il parametro (b) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (b) non rispetta le specifiche\n");
        return false;
    }

    if (alpha >= 10.0 && alpha <= 20.0) {
        printf("\n il parametro (alpha) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (alpha) non rispetta le specifiche\n");
        return false;
    }

    if (beta >= 1.0 && beta <= 5.0) {
        printf("\n il parametro (beta) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (beta) non rispetta le specifiche\n");
        return false;
    }

    return true;
}

double ***allocate_matrix(int rows, int cols) {
    double*** matrix = (double***)malloc(rows * sizeof(double**));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double**)malloc(cols * sizeof(double*));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double*)malloc(sizeof(double));
        }
    }

    return matrix;
}

void fill_matrix(double ***matrix, int rows, int cols, input in) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double element = (double)get_random() / UINT_MAX;
            if (element > 0.2) {
                *matrix[i][j] = (double)get_random() / UINT_MAX * (2 * in.beta) + (in.alpha - in.beta);
            } else {
                *matrix[i][j] = 0.0;
            }
        }
    }
}

void print_matrix(double ***matrix, int rows, int cols) {
    printf("\n________Matrix_____________\n");
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; ++j) {
            printf("%f\t", *matrix[i][j]);
        }
    }
    printf("\n________Matrix_____________\n");
}

double ***transposeMatrix(double ***matrix, int rows, int cols) {
    double ***transpose_matrix = allocate_matrix(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            *transpose_matrix[i][j] = *matrix[j][i];
        }
    }
    return transpose_matrix;
}

void deallocate_matrix(double ***matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}