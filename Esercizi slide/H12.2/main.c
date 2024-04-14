#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int min(int N, int M) {
    return N < M ? N : M;
}

int main(){
    int N,M;

    do{
        //primo numero
        printf("\ninsersici N\n");
        scanf("%d",&N);

        //secondo numero
        printf("\ninsersici M\n");
        scanf("%d",&M);
    } while(N<1 && M<1); //condizione
    double Matrix[N][M];

    srand(time(NULL));
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j < M; ++j) {
            Matrix[i][j]=((double) rand()) / RAND_MAX;
        }
    }
    float num,m=0;
    printf("\ninserisci un numero:\n");
    scanf("%f",&num);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <M ; ++j) {
            m*=Matrix[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < M; ++j) {
            printf("%f",Matrix[i][j]);
        }
    }

    N = min(N,M);
    float matrix_q[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <M ; ++j) {
            Matrix[i][j]=matrix_q[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < N; ++j) {
            printf("%f",matrix_q[i][j]);
        }

    }








}

