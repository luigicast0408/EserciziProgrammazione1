#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int **insert_elements(int n,int m);
void print_elemets(int **matrix,int n,int m);
int sum_row(int *v,int size);
int mul_col(int *v,int size);
int *sum_mul_row_col(int **matrix,int n,int m);
void print_vector(int *v,int size);
int main()
{
    int n,m,k;
    printf("\nQuante righe vuoi?(N)\n");
    scanf("%d",&n);

    printf("\nQuante colonne vuoi?(M)\n");
    scanf("%d",&m);

    printf("\nQuante righe vuoi?(K)\n");
    scanf("%d",&k);

 int**matrix1= insert_elements(n,m);
 int**matrix2= insert_elements(n,k);
 int *p= sum_mul_row_col(matrix1,n,m);
 print_vector(p,m*n);
free(matrix1);
free(matrix2);
free(p);
}
int **insert_elements(int m,int n){

    int **matrix= malloc(sizeof(int*)*m);
    for (int i = 0; i < m; ++i) {
        matrix[i]= malloc(sizeof(int)*n);
    }
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j]=rand()%1000;
        }
    }
    print_elemets(matrix,n,m);
    return matrix;
}

void print_elemets(int **matrix,int n,int m){
    printf("\n________MATRIX_________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%d\t",matrix[i][j]);
        }
    }
    printf("\n________MATRIX_________________\n");
}

int mul_col(int *v,int size){
    int m=1;
    for (int i = 0; i <size; ++i)
        m*=v[i];
    return m;
}

int sum_row(int *v,int size){
    int sum=0;
    for (int i = 0; i < size; ++i)
        sum+=v[i];
    return sum;
}

int *sum_mul_row_col(int **matrix,int n,int m){
    int temp[20],count_row=0,count_col=0,cont_s=0;
    int temp_col[20],s_row[20];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp[count_row]=matrix[i][j];
            count_row++;
        }
        s_row[cont_s]=sum_row(temp,count_row);
        cont_s++;
        print_vector(temp,count_row);
    }
    int s_col[20],cont_s_col=0;
    for (int i = 0; i <m ; ++i) {
        for (int j = 0; j < n; ++j) {
            temp_col[count_col]=matrix[j][i];
            count_col++;
        }
        s_col[i]=mul_col(temp_col,count_col);
        cont_s_col++;
        print_vector(temp_col,  cont_s_col);
    }
    int *division= malloc(sizeof(int)*(cont_s*cont_s_col));
    for (int i = 0; i < cont_s*cont_s_col; ++i) {
        division[i]=s_row[i]/s_col[i];
        printf("%d\t",s_row[i]/s_col[i]);
    }
    return division;
    //free(division);

}

void print_vector(int *v,int size){
    printf("\n________VECTOR_________________\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t",v[i]);
    }
    printf("\n________VECTOR_________________\n");
}