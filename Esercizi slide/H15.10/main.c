#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define  N 2
#define  M 3

void insert_elemets(unsigned int matrix[N][M]);

void average_row(unsigned int matrix[N][M], unsigned short a, unsigned short b, int w);

bool check_number(unsigned short a, unsigned short b);

void print_matrix(unsigned int matrix[N][M]);

void print_vector(int vett[], int dim);


int main() {
    unsigned int matrix[N][M];
    insert_elemets(matrix);
    average_row(matrix,0,1,5.0);
}

void insert_elemets(unsigned int matrix[N][M]) {
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    print_matrix(matrix);
}

void average_row(unsigned int matrix[N][M], unsigned short a, unsigned short b, int w) {
    int sum = 0, cont = 0;
    int temp[20];
    if (check_number(a, b) == true) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                temp[cont] = sum += matrix[i][j];
                cont++;
            }
            sum=0;
        }
    } else {
        exit(-1);
    }
    print_vector(temp,cont);

}

bool check_number(unsigned short a, unsigned short b) {
    if (a >= 0 && a < b && b <= N) {
        return true;
    } else {
        return false;
    }
}

void print_matrix(unsigned int matrix[N][M]) {
    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < M; ++j) {
            printf("%d\t", matrix[i][j]);
        }
    }
}

void print_vector(int vett[], int dim) {
    for (int i = 0; i < dim; ++i) {
        printf("%d\t", vett[i]);
    }
}
