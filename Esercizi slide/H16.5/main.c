#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char **insert_string(int rows, int cols);
void print_matrix(char **matrix, int rows, int cols);
bool check_row_col_string(char **matrix, int rows, int cols, short w, short k);

int main() {
    char **matrix = insert_string(4, 4);
    print_matrix(matrix, 4, 4);

    if (check_row_col_string(matrix, 4, 4, 2, 3)) {
        printf("\nThere is at least one row and one column with at least 2 strings of length less than 3.\n");
    } else {
        printf("\nNo such row and column found.\n");
    }

    // Free memory
    for (int i = 0; i < 4; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

char **insert_string(int rows, int cols) {
    char **matrix = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i] = malloc(sizeof(char) * (cols + 1));  // +1 for null terminator
    }
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = ((char)(rand() % 26 + 97));
        }
        matrix[i][cols] = '\0';  // null-terminate the string
    }
    return matrix;
}

void print_matrix(char **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        printf("\n");
        for (int j = 0; j < cols; ++j) {
            printf("%s\t", matrix[i]);
        }
    }
}

bool check_row_col_string(char **matrix, int rows, int cols, short w, short k) {
    int count_row_k = 0;

    for (int i = 0; i < rows; ++i) {
        int count_row = 0;
        for (int j = 0; j < cols; ++j) {
            if (strlen(matrix[i]) < k) {
                count_row++;
            }
        }
        if (count_row >= w) {
            count_row_k++;
        }
    }

    int count_col_k = 0;
    for (int j = 0; j < cols; ++j) {
        int count_col = 0;
        for (int i = 0; i < rows; ++i) {
            if (strlen(matrix[i]) < k) {
                count_col++;
            }
        }
        if (count_col >= w) {
            count_col_k++;
        }
    }

    return (count_row_k >= 1 && count_col_k >= 1);
}
