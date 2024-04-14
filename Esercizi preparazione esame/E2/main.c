#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void insert_elements(char M[][20], int rows);
void string_palindrome(char M[][20], int rows);
void print_string(char M[][20], int N);
bool check_palindrome(char str[]);

int main() {
    char M[20][20];
    int rows = 2;
    insert_elements(M, rows);
    string_palindrome(M, rows);
    return 0;
}

void insert_elements(char M[][20], int rows) {
    for (int i = 0; i < rows; ++i) {
        printf("\nInserisci la %d stringa:\n", i + 1);
        scanf("%s", M[i]);
    }
}

void string_palindrome(char M[][20], int rows) {
    char temp[20][20];
    for (int i = 0; i < rows; ++i) {
        bool res = check_palindrome(M[i]);
        if (res == true) {
            printf("%s is a palindrome.\n", M[i]);
        } else {
            printf("%s is not a palindrome.\n", M[i]);
        }
    }
    print_string(temp, rows);
}

void print_string(char M[][20], int N) {
    for (int i = 0; i < N; ++i) {
        printf("%s\t", M[i]);
    }
}

bool check_palindrome(char str[]) {
    char temp[20];
    //int len = strlen(str);


    for (int i = strlen(str)- 1, j = 0; i >= 0; --i, ++j) {
        temp[j] = str[i];
    }

    temp[strlen(str)] = '\0';

    printf("\nstr -> %s\n", str);
    printf("temp -> %s\n", temp);

    return strcmp(str, temp) == 0;
}
// todo da rivedere