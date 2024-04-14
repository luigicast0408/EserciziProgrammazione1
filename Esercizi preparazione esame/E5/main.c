#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **insert_elements(int row, int col);
void print_matrix(int **matrix, int row, int col);
int *average_row_col(int **matrix_A, int **matrix_B, int row_A, int col_A, int row_B, int col_B, int *size);
void print_vector(int *vet, int size);

int main() {
    int rows_A, col_A, rows_B, col_B;
    int size;
    do {
        printf("\nQuante righe vuoi? (1° matrice):\n");
        scanf("%d", &rows_A);

        printf("\nQuante colonne vuoi? (1° matrice):\n");
        scanf("%d", &col_A);

        printf("\nQuante righe vuoi? (2° matrice):\n");
        scanf("%d", &rows_B);

        printf("\nQuante colonne vuoi? (2° matrice):\n");
        scanf("%d", &col_B);

        if (rows_A != rows_B || col_A != col_B) {
            printf("\nPUOI INSERIRE SOLO I DATI PER DUE MATRICI IDENTICHE...\n");
        }
    } while (rows_A != rows_B || col_A != col_B);

    int **matrix_A = insert_elements(rows_A, col_A);
    int **matrix_B = insert_elements(rows_B, col_B);

    print_matrix(matrix_A, rows_A, col_A);
    print_matrix(matrix_B, rows_B, col_B);

    int *result = average_row_col(matrix_A, matrix_B, rows_A, col_A, rows_B, col_B, &size);
    print_vector(result, size);

    // Libera la memoria allocata per le matrici e il vettore
    for (int i = 0; i < rows_A; ++i) {
        free(matrix_A[i]);
    }
    free(matrix_A);

    for (int i = 0; i < rows_B; ++i) {
        free(matrix_B[i]);
    }
    free(matrix_B);

    free(result);

    return 0;
}

int **insert_elements(int row, int col) {
    int **matrix = malloc(sizeof(int *) * row);
    for (int i = 0; i < row; ++i) {
        matrix[i] = malloc(sizeof(int) * col);
    }
    srand(time(NULL));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = rand() % 1000;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return matrix;
}

void print_matrix(int **matrix, int row, int col) {
    printf("\n_______Matrix____________\n");
    for (int i = 0; i < row; ++i) {
        printf("\n");
        for (int j = 0; j < col; ++j) {
            printf("%d\t", matrix[i][j]);
        }
    }
    printf("\n_______Matrix____________\n");
}

int *average_row_col(int **matrix_A, int **matrix_B, int row_A, int col_A, int row_B, int col_B, int *size) {
    int s_row = 0, s_col = 0, count_row = 0, count_col = 0;

    int *temp_row = malloc(sizeof(int) * row_A);
    int *temp_col = malloc(sizeof(int) * col_B);
    int *average = malloc(sizeof(int) * (row_A * col_B));

    // Calcola la media delle righe
    for (int i = 0; i < row_A; ++i) {
        for (int j = 0; j < col_A; ++j) {
            s_row += matrix_A[i][j];
        }
        temp_row[count_row] = s_row / col_A;
        count_row++;
        s_row = 0; // Azzera la somma per la prossima riga
    }

    // Calcola la media delle colonne
    for (int j = 0; j < col_B; ++j) {
        for (int i = 0; i < row_B; ++i) {
            s_col += matrix_B[i][j];
        }
        temp_col[count_col] = s_col / row_B;
        count_col++;
        s_col = 0; // Azzera la somma per la prossima colonna
    }

    // Calcola la media finale
    for (int i = 0; i < count_row; ++i) {
        for (int j = 0; j < count_col; ++j) {
            average[i * count_col + j] = temp_row[i] / temp_col[j];
        }
    }

    *size = count_col * count_row;

    free(temp_row);
    free(temp_col);

    return average;
}

void print_vector(int *vet, int size) {
    printf("\n_____________Vettore__________\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t", vet[i]);
    }
    printf("\n_____________Vettore__________\n");
}
