#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define rows 2
#define colums 2

void insert_elements(int matrix[rows][colums]);
int average_column_element_tot(int matrix[rows][colums], int y);
void print_matrix(int matrix[rows][colums], int rows1, int colums1);
float average(int *v, int dim);
void print_vector(int *v, int dim);

int main() {
    int matrix[rows][colums];
    int y = 20;
    insert_elements(matrix);
    print_matrix(matrix, rows, colums);
    int ris = average_column_element_tot(matrix, y);
    printf("ris=%d\n", ris);

    return 0;
}

void insert_elements(int matrix[rows][colums]) {
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            matrix[i][j] = rand() % 1000;
        }
    }
}

int average_column_element_tot(int matrix[rows][colums], int y) {
    int count = 0, temp[rows * colums], n_col = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            temp[count] = matrix[i][j];
            count++;

            if (average(temp, count) <= y) {
                n_col++;
                count = 0;
            }
        }
        print_vector(temp, count);
    }
    return n_col;
}

void print_matrix(int matrix[rows][colums], int rows1, int colums1) {
    for (int i = 0; i < rows1; ++i) {
        printf("\n");
        for (int j = 0; j < colums1; ++j) {
            printf("%d\t", matrix[i][j]);
        }
    }
}

float average(int *v, int dim) {
    int sum = 0;
    for (int i = 0; i < dim; ++i) {
        sum += v[i];
    }
    for (int i = 0; i < dim; ++i) {
        v[i] = 0;
    }
    return sum / (float)dim;
}

void print_vector(int *v, int dim) {
    printf("\n_______________VETTORE__________________\n");
    for (int i = 0; i < dim; ++i) {
        printf("%d\t", v[i]);
    }
    printf("\n_______________VETTORE__________________\n");
}
