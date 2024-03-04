#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
char** insert_strings(int rows,int cols);
void print_matrix(char **matrix,int rows,int cols);
int main()
{
 char **matrix= insert_strings(2,2);
 print_matrix(matrix,2,2);
}

char** insert_strings(int rows,int cols){
    char ** matrix= malloc(sizeof(char *)*rows);
    for (int i = 0; i < cols ; ++i) {
        matrix= malloc(sizeof(char)*cols);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("\nInserisci la stringa alla posizione %d \n",i);

        }
    }
    return matrix;
}

void print_matrix(char **matrix,int rows,int cols){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Matrix[%d]->%s",i,matrix[i]);
        }
    }
}
