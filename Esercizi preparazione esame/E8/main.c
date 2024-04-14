#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int **insert_elemets(int row, int cols);
void print_vector(int *v, int size);
void print_matrix(int **matrix, int row, int col);
void matrix_to_vector_col(int **matrix, int row, int col);
void check_monotona_sequence(int *v, int size,int w,int k,int *w_count);
int main()
{

}

int **insert_elemets(int row, int cols){
    int **matrix= malloc(sizeof(int**)*row);
    for (int i = 0; i < cols; ++i) {
        matrix[i]= malloc(sizeof(int)*cols);
    }
    return matrix;
}

void print_matrix(int **matrix, int row, int col){
    for (int i = 0; i < row; ++i) {
        printf("\n");
        for (int j = 0; j < col; ++j) {
            printf("%d\t",matrix[i][j]);
        }
    }
}

void print_vector(int *v, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d\t",v[i]);
    }
}

void matrix_to_vector_col(int **matrix, int row, int col){
    int vector[row*col],count=0;
    for (int j = 0; j < col; ++j) {
        for (int i = 0; i < row; ++i) {
            matrix[j][i]=vector[count];
            count++;
        }

        count=0;
    }
}

void  check_monotona_sequence(int *v, int size,int w,int k, int *w_count){
    int k_count=0,count_k=0;
    for (int i = 0; i <size ; ++i) {
        if(v[i+1]>=v[i]) {
            k_count++;
        }
    }
    if(k==k_count){
       *w_count;
    }
}

