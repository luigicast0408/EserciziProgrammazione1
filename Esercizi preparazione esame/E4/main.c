#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void insert_elemets(int A[][20],int rows_A,int column_A,int B[][20],int rows_B,int column_B);
void print_vector(int *v, int n);
void print_matrix(int M[][20], int rows,int colums);
void check_sum_matrix(int A[][20],int rows_A,int column_A,int B[][20],int rows_B,int column_B);

int main()
{
    int A[20][20],B[20][20];
    int  rows_A=2,rows_B=2,colums_A=2,colums_B=2;
    insert_elemets(A,rows_A,colums_A,B,rows_B,colums_B);
    check_sum_matrix(A,rows_A,colums_A,B,rows_B,colums_B);


}
void insert_elemets(int A[][20],int rows_A,int column_A,int B[][20],int rows_B,int column_B) {
    srand(time(NULL));
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < column_A; ++j) {
            A[i][j]=rand()%((20-10)+1)+10;
        }
    }
    print_matrix(A,rows_A,column_B);

    srand(time(NULL));
    for (int i = 0; i < rows_B; ++i) {
        for (int j = 0; j < column_B; ++j) {
            B[i][j]=rand()%((30-10)+1)+10;
        }
    }
    print_matrix(B,rows_B,column_B);
}

void check_sum_matrix(int A[][20],int rows_A,int column_A,int B[][20],int rows_B,int column_B){
    int sum_row[20],sum=0,count=0;
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < column_A; ++j) {
            sum_row[count]=sum+=A[i][j];

        }
        count++;
        sum=0;
    }
    print_vector(sum_row,count);
    int sum_colums[20];
    sum=0,count=0;
    for (int i = 0; i < rows_B; ++i) {
        for (int j = 0; j < column_B; ++j) {
            sum_colums[count]=sum+=B[i][j];

        }
    }
    print_vector(sum_colums,count);

}
void print_vector(int *v, int n) {
    printf("\n___________vector________\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t",v[i]);
    }
    printf("\n___________vector________\n");
}

void print_matrix(int M[][20], int rows,int colums){
    printf("\n___________matrix_________\n");
    for (int i = 0; i < rows; ++i) {
        printf("\n");
        for (int j = 0; j <colums ; ++j) {
            printf("%d\t",M[i][j]);
        }
    }
    printf("\n___________matrix_________\n");
}

