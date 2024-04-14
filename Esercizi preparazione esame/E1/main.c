#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void insert_elemets(int A[][10][10], int *k_dim, int *n_dim);

void print_elemets(int A[][10][10],  int *k_dim,  int *n_dim);

int min(const int v[], int N);

int max(const int v[], int N);

bool request_digonal(int A[][10][10],  int *k_dim, int *n_dim, int w);

void print_vector(int *v, int N);

int main() {
    int A[10][10][10];
    int k_dim = 5, n_dim = 5,w=30;
    int *ptr_k_dim = &k_dim, *ptr_n_dim = &n_dim;
    insert_elemets(A, ptr_k_dim, ptr_n_dim);
    print_elemets(A, ptr_k_dim, ptr_n_dim);
    bool value = request_digonal(A, ptr_k_dim, ptr_n_dim, w);
    printf("value->%d",value);
    if (value == true) {
        printf("hello\n");
    }

    //& no perchè sto chiedendo lindirizzo (ptr_k_dim) altrimenti *ptr_k_dim;
}

void insert_elemets(int A[][10][10],  int *k_dim,  int *n_dim) {
    srand(time(NULL));
    for (int i = 0; i < *k_dim; ++i) {
        for (int j = 0; j < *n_dim; ++j) {
            for (int k = 0; k < *n_dim; ++k) {   //valore *n_dim
                A[i][j][k] = rand() % 100;
            }
        }
    }
    //printf("test1:%d\n",*k_dim);
    //printf("test2:%d\n",*n_dim);

}

void print_elemets(int A[][10][10], int *k_dim,  int *n_dim) {
    for (int i = 0; i < *k_dim; ++i) {
        for (int j = 0; j < *n_dim; ++j) {
            for (int k = 0; k < *n_dim; ++k) {   //valore *n_dim
                printf("el->%d\n", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


bool request_digonal(int A[][10][10], int *k_dim, int *n_dim, int w) {
    int count = 0;
    int temp[10000];
    for (int i = 0; i < *k_dim; ++i) {
        for (int j = 0; j < *n_dim; ++j) {
            for (int k = 0; k < *n_dim; ++k) {
                temp[count] = A[i][k][k];
                count++;
            }
        }
    }
    print_vector(temp,count);
    int max_f = max(temp, count);
    int min_f = min(temp, count);
    printf("\n max-> %d\n",max_f);
    printf("\n min-> %d\n",min_f);
    printf("\nespessione if %f\n",((double)max_f + min_f) / 2.0);


    if (((double)max_f + min_f) / 2.0 <= w) {
        return true;
    } else {
        return false;
    }


}

int min(const int *v, int N) {

    int min = v[0];
    for (int i = 0; i < N; ++i)
        if(v[i]<min) {min=v[i];}
    return min;
}

int max(const int *v, int N) {
    int max = v[0];
    for (int i = 0; i < N; ++i)
        if(v[i]>max) {max=v[i];}
    return max;
}

void print_vector(int *v, int N){
    printf("____________Vettore__________________\n");
    printf("Indirizzo del vettore: %p\n", (void*)v);  // Aggiunto per debug

    for (int i = 0; i < N; ++i) {
        printf("vett[%d]->%d\t", i, v[i]);
    }
    printf("\n____________Vettore__________________\n");
}


