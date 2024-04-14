#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
#define M 4

char **insert_elements(int n, int m);

void print_vector(char v[], int size);

void print_elements(char **matrix, int n, int m);

bool check_dist_elements(char vector[], int dim);

bool row_col_check(char *v, int dim, char *c);

bool matrix_to_vector_row(char **matrix, int n, int m, char *c, float w);

bool matrix_to_vector_col(char **matrix, int n, int m, char *c, float w);

int main() {
    char **matrix = insert_elements(N, M);
    print_elements(matrix, N, M);

    char characters[] = {'A', 'B', 'C', 'D'};
    float threshold = 0.5;

    bool row_result = matrix_to_vector_row(matrix, N, M, characters, threshold);
    bool col_result = matrix_to_vector_col(matrix, N, M, characters, threshold);

    if (row_result || col_result) {
        printf("\nThere exists a row or column with a percentage greater than %.2f\n", threshold);
    } else {
        printf("\nNo row or column has a percentage greater than %.2f\n", threshold);
    }

    // Don't forget to free allocated memory
    for (int i = 0; i < N; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

char **insert_elements(int n, int m) {
    char **matrix = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = (char *)malloc(sizeof(char) * m);
    }
    char car = 'A';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = car++;
        }
    }
    return matrix;
}

void print_vector(char v[], int size) {
    printf("\n________________Vettore\n");
    for (int i = 0; i < size; ++i) {
        printf("%c\t", v[i]);
    }
    printf("\n________________Vettore\n");
}

void print_elements(char **matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%c\t", matrix[i][j]);
        }
    }
}

bool check_dist_elements(char vector[], int dim) {
    for (int i = 0; i < dim; ++i) {
        for (int j = i + 1; j < dim; ++j) {
            if (vector[i] == vector[j]) {
                return false;
            }
        }
    }
    return true;
}

bool row_col_check(char *v, int dim, char *c) {
    int count = 0;
    for (int i = 0; i < dim; ++i) {
        for (int j = i + 1; j < dim; ++j) {
            if (v[i] == c[j]) {
                count++;
            }
        }
    }
    return true;
}

bool matrix_to_vector_row(char **matrix, int n, int m, char *c, float w) {
    for (int i = 0; i < n; ++i) {
        char *vector = (char *)malloc(sizeof(char) * m);
        int count = 0;

        for (int j = 0; j < m; ++j) {
            vector[count] = matrix[i][j];
            count++;
        }

        bool result = row_col_check(vector, count, c);
        free(vector);

        if ((float)count / m > w && result) {
            return true;
        }
    }
    return false;
}

bool matrix_to_vector_col(char **matrix, int n, int m, char *c, float w) {
    for (int j = 0; j < m; ++j) {
        char *vector = (char *)malloc(sizeof(char) * n);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            vector[count] = matrix[i][j];
            count++;
        }

        bool result = row_col_check(vector, count, c);
        free(vector);

        if ((float)count / n > w && result) {
            return true;
        }
    }
    return false;
}
