#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **insert_elements(int n, int m);
void print_elements(char **M, int n, int m);
void check_palindrome(char **M, int n, int m);
bool palindrome(char v[], int dim);
void print_vector(int v[], int size);

int main() {
    char **M = insert_elements(5, 5);
    print_elements(M, 5, 5);
    check_palindrome(M, 5, 5);

    return 0;
}

char **insert_elements(int n, int m) {
    char **M = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; ++i) {
        M[i] = (char *)malloc(sizeof(char) * m);
    }
    char car = 'A';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            M[i][j] = car++;
        }
    }
    return M;
}

void print_elements(char **M, int n, int m) {
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%c\t", M[i][j]);
        }
    }
}

void check_palindrome(char **M, int n, int m) {
    int temp_row[20];
    int temp_col[20];

    for (int i = 0; i < n; ++i) {
        char temp[100];
        int count = 0;

        // Copy the row elements to temp array
        for (int j = 0; j < m; ++j) {
            temp[count] = M[i][j];
            count++;
        }

        // Null-terminate the temp array
        temp[count] = '\0';

        // Check if the row is a palindrome
        if (palindrome(temp, count)) {
            printf("\nRow %d is a palindrome.", i + 1);
            temp_row[i] = 1;
        } else {
            printf("\nRow %d is not a palindrome.", i + 1);
            temp_row[i] = -1;
        }
    }
    print_vector(temp_row,n);

    for (int i = 0; i < m; ++i) {
        char temp[100];
        int count = 0;

        // Copy the column elements to temp array
        for (int j = 0; j < n; ++j) {
            temp[count] = M[j][i];
            count++;
        }

        // Null-terminate the temp array
        temp[count] = '\0';

        // Check if the column is a palindrome
        if (palindrome(temp, count)) {
            printf("\nColumn %d is a palindrome.", i + 1);
            temp_col[i] = 1;
        } else {
            printf("\nColumn %d is not a palindrome.", i + 1);
            temp_col[i] = -1;
        }
    }
    print_vector(temp_row,m);
}

bool palindrome(char v[], int dim) {
    for (int i = 0; i < dim / 2; ++i) {
        if (v[i] != v[dim - i - 1]) {
            return false;
        }
    }
    return true;
}

void print_vector(int v[], int size) {
    printf("\n________________Vettore\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t",v[i]);
    }
    printf("\n________________Vettore\n");
}