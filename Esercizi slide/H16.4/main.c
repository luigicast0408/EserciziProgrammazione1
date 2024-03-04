#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

double **insert_elements(int m,int n);
void print_elemets(double **matrix,int m,int n);
void print_vector(double *v,int size);
bool check_distinct_elemets_vector(double *v,int size);
double average_row_col( double *v, int size);
double **average_elemets(int n,int m,double **matrix);



int main()
{
    double **A= insert_elements(2,3);
    double **B= insert_elements(2,2);
    double **C= average_elemets(2,2,A);



    free(A);
    free(B);




}
double **insert_elements(int m, int n) {
    double **matrix = malloc(sizeof(double *) * m);
    for (int i = 0; i < m; ++i) {
        matrix[i] = malloc(sizeof(double) * n);
    }
    srand(time(NULL));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() / (1.0 * RAND_MAX);
        }
    }
    print_elemets(matrix, n, m);
    return matrix;
}


void print_elemets(double **matrix,int m,int  n){
    printf("\n________MATRIX_________________\n");
    for (int i = 0; i < m; ++i) {
        printf("\n");
        for (int j = 0; j < n; ++j) {
            printf("%lf\t",matrix[i][j]);
        }
    }
    printf("\n________MATRIX_________________\n");
}

void print_vector(double *v,int size){
    printf("\n________VECTOR_________________\n");
    for (int i = 0; i < size; ++i) {
        printf("%lf\t",v[i]);
    }
    printf("\n________VECTOR_________________\n");
}


bool check_distinct_elemets_vector(double *v,int size) {
    for (int i = 0; i <size ; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (v[i]==v[j])
                return true;
        }
    }
    return false;
}

double average_row_col(double *v, int size) {
    int sum=0;
    for (int i = 0; i <size ; ++i) {
        sum+=v[i];
    }
    return (sum/size);
}

double **average_elemets(int n,int m,double **matrix){
    double vector_row[n*m],vector_col[n*m],average_row[n*m],average_col[n*m];
    int count_row=0,count_col=0,count_a_row=0,count_a_col=0;
    for (int i = 0; i < m; ++i) { //righe
        for (int j = 0; j <n ; ++j) {
            matrix[i][j]=vector_row[count_row];
            count_row++;
        }
        count_row=0;
        average_row[count_a_row]=average_row_col(vector_row,count_row)/m;
        count_a_row++;
        print_vector(vector_row,count_row);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[j][i]=vector_col[count_col];
            count_col++;
        }
        count_col=0;
        average_col[count_a_col]=average_row_col(vector_row,count_row)/n;
        count_a_col++;
    }
    print_vector(average_row,count_a_row);

    for (int i = 0; i < count_a_col*count_a_row; ++i) {
        printf("->%f",(vector_row[i]/vector_col[i])/2);
    }

    return matrix;
}

// TODO: 14/12/2013 da finire e cotrollare