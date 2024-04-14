#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
   double D[10];
   int A[10];
   srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        D[i] = 1.25 + (rand() / (RAND_MAX / (90.0 - 1.25 + 1) + 1));
    }
    for (int i = 0; i < 10; ++i) {
        A[i]=10+(rand()%(50-10+1)+10);
    }
    double *ptr_D=D;
    printf("\n*ptr_D=%p\n",ptr_D);
    int *ptr_A=A;
    printf("\n*ptr_A=%p\n",ptr_A);

    for (int i = 0; i < 10; ++i) {
        if(i%2!=0){
            printf("D[%d] = %lf (indirizzo: %p)\n", i, *(ptr_D + i), (void *)(ptr_D + i));
            printf("D[%d] = %lf (indirizzo: %p)\n", i, D[i], (void *)&D[i]);
        } else {
            printf("A[%d] = %d (indirizzo: %p)\n", i, *(ptr_A + i), (void *) (ptr_A + i));
            printf("A[%d] = %d (indirizzo: %p)\n", i, A[i], (void *) &A[i]);
        }
    }



}
