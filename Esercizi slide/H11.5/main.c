#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    float N;
    for (int i = 0; i < 3; ++i) {
        printf("\nInserisci il %d numero\n",i+1);
        scanf("%f",&N);
        printf("\nIl numero arrotodando e' %d\n",(int) N);
    }
}
