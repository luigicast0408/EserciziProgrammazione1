#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    float cateto1, cateto2;

    do {
        printf("\nInserisci il primo cateto: ");
        scanf("%f", &cateto1);
        printf("\nInserisci il secondo cateto: ");
        scanf("%f", &cateto2);
    } while (cateto1 < 0 || cateto2 < 0);

    float ipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    printf("\nL'ipotenusa e' %.2f\n", ipotenusa);

    return 0;
}
