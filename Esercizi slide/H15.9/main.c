#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4
void insert_elemets(int matrix[N][N]);
int first_diagonal(int matrix[N][N]);
int second_diagonal(int matrix[N][N]);
void print_vector(int *v, int dim);
void print_matrix(int matrix[N][N],int dim);

int main()
{
  int matrix[N][N];
    insert_elemets(matrix);
    int m_fist=first_diagonal(matrix);
    int m_second=second_diagonal(matrix);
    int ris= abs(m_fist-m_second);
    printf("\nLa media della digonale principale e': %d\n La media della diagonale secondaria e': %d\n "
           "La differenza in  valore assoluto e' %d:\n",m_fist,m_second,ris);
}

void insert_elemets(int matrix[N][N]) {
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j]=rand()%100;
        }
    }
    print_matrix(matrix,N);
}

int first_diagonal(int matrix[N][N]) {
    int temp[100],count=0,sum=0;
    for (int i = 0; i < N; ++i) {
        temp[count]=matrix[i][i];
        sum+=temp[count];
        count++;
    }
    print_vector(temp,count);
    return abs(sum/N);
}

int second_diagonal(int matrix[N][N]){
    int temp[100],count=0,sum=0;
    for (int i = 0; i < N; ++i) {
            temp[count]=matrix[i][N-i-1];
            sum+=temp[count];
            count++;
    }
    print_vector(temp,count);
    return abs(sum/N);
}

void print_vector(int *v, int dim) {
    printf("\n_______________VETTORE__________________\n");
    for (int i = 0; i < dim; ++i) {
        printf("%d\t", v[i]);
    }
    printf("\n_______________VETTORE__________________\n");
}

void print_matrix(int matrix[N][N],int dim) {
    for (int i = 0; i <dim ; ++i) {
        printf("\n");
        for (int j = 0; j < dim; ++j) {
            printf("%d\t",matrix[i][j]);
        }
    }
}