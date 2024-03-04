#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *file_name;
    int n;
    int m;
} InputParams;

typedef struct {
    double **matrix;
    int rows;
    int cols;
} Matrix;

InputParams readInput(int argc, char *argv[]);
Matrix allocateMatrix(int rows, int cols);
void fillMatrix(Matrix mat, const char *file_name);
void printMatrix(Matrix mat);
void normalize(Matrix src, Matrix dest);
void sortMatrixCols(Matrix mat);
void freeMatrix(Matrix mat);

int main(int argc, char *argv[]) {
    InputParams input = readInput(argc, argv);

    Matrix A = allocateMatrix(input.n, input.m);
    fillMatrix(A, input.file_name);

    Matrix B = allocateMatrix(input.n, input.m);
    normalize(A, B);

    printf("** A **\n");
    printMatrix(A);

    printf("** B **\n");
    printMatrix(B);

    sortMatrixCols(B);

    printf("** B (sorted columns) **\n");
    printMatrix(B);

    // Cleanup
    freeMatrix(A);
    freeMatrix(B);

    return 0;
}

InputParams readInput(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file_name> <N> <M>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    InputParams params;
    params.file_name = argv[1];
    params.n = atoi(argv[2]);
    params.m = atoi(argv[3]);

    if (params.n < 5 || params.n > 10 || params.m < 5 || params.m > 10) {
        fprintf(stderr, "N and M must be between 5 and 10.\n");
        exit(EXIT_FAILURE);
    }

    return params;
}

Matrix allocateMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        mat.matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return mat;
}

void fillMatrix(Matrix mat, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            fscanf(file, "%lf", &mat.matrix[i][j]);
        }
    }

    fclose(file);
}

void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%f ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

void normalize(Matrix src, Matrix dest) {
    // Trova il massimo valore per ogni colonna
    double maxValues[src.cols];
    for (int j = 0; j < src.cols; j++) {
        maxValues[j] = src.matrix[0][j];
        for (int i = 1; i < src.rows; i++) {
            if (src.matrix[i][j] > maxValues[j]) {
                maxValues[j] = src.matrix[i][j];
            }
        }
    }

    // Normalizza la matrice
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            dest.matrix[i][j] = src.matrix[i][j] / maxValues[j];
        }
    }
}

void sortMatrixCols(Matrix mat) {
    // Implementa un semplice bubble sort per ogni colonna
    for (int j = 0; j < mat.cols; j++) {
        for (int i = 0; i < mat.rows; i++) {
            for (int k = i + 1; k < mat.rows; k++) {
                if (mat.matrix[i][j] > mat.matrix[k][j]) {
                    double temp = mat.matrix[i][j];
                    mat.matrix[i][j] = mat.matrix[k][j];
                    mat.matrix[k][j] = temp;
                }
            }
        }
    }
}

void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.matrix[i]);
    }
    free(mat.matrix);
}