#include "stdio.h"
#include "math.h"

int main() {
    int  N;
    printf("\n inserisci un numero: \n");
    scanf("%d",&N);
    for (int i = 0; i < N; ++i){
        printf("%f",pow(i,2));
    }

}
