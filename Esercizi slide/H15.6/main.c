#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void insert_value(int *A,int *B, int dim);
int check_value(int *A,int *B, int dim);
void print_vector(int *v, int dim);

int main()
{
    int dim=10,A[dim],B[dim];
    insert_value(A,B,dim);
    check_value(A,B,dim);

}
void insert_value(int *A,int *B, int dim){
    srand(time(NULL));
    for (int i = 0; i < dim; ++i) {
        do {
            A[i]=rand()%1000;
            B[i]=rand()%1000;
        }while(B[i]==0);
    }
    print_vector(A,dim);
    print_vector(B,dim);
}

int check_value(int *A,int *B, int dim) {
    srand(time(NULL));
    int cont_1=0;
    for (int i = 0; i < dim; ++i) {
        if(A[i]/B[i]<1){
            B[i]=A[i];
            A[i]=rand()%(200-100+1)+100;
        }
        else if (A[i]/B[i]>1) {
            A[i]=B[i];
            B[i]=rand()%100;
        }
        else if (A[i]/B[i]==1){
            B[i]=A[i];
            A[i]=0;
            cont_1++;
        }
    }
    print_vector(A,dim);
    print_vector(B,dim);
    return cont_1;
}

void print_vector(int *v, int dim){
    printf("\n_______________VETTORE__________________\n");
    for (int i = 0; i <dim ; ++i) {
        printf("%d\t",v[i]);
    }
    printf("\n_______________VETTORE__________________\n");
}