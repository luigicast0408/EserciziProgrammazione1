#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define R 2
#define C 2
void insert_elemets(int A[R][C]);
void print_matrix(int A[R][C]);
int main(){
    int A[R][C];
    insert_elemets(A);


}
void insert_elemets(int A[R][C]){
    srand(time(NULL));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            A[i][j]=rand()%1000;
        }
    }
    print_matrix(A);
}

void print_matrix(int A[R][C]){
    for (int i = 0; i < R; ++i) {
        printf("\n");
        for (int j = 0; j <C ; ++j) {
            printf("%d\t",A[i][i]);
        }
    }
}

bool request(int A[R][C],short k, short w){

    for (int j = 0; j < C; ++j) {
        int conteggioSequenzaCrescente = 1;
        for (int i = 1; i < R; ++i) {
            if (A[i][j] > A[i - 1][j]) {
                //*(A+i   A)
              conteggioSequenzaCrescente++;

                if (conteggioSequenzaCrescente >= k) {
                    return true;
                }
            } else {
                conteggioSequenzaCrescente = 1;
            }
        }
    }
    return false;
}
