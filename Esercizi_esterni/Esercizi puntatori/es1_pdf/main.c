#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int resolve_eq2(double a_coeff, double b_coeff, double c_coeff, double *x1, double *x2);

int main() {
    double a, b, c;

    printf("\nInserisci il coefficiente della a (ax)\n");
    scanf("%lf", &a);

    printf("\nInserisci il coefficiente della b (bx)\n");
    scanf("%lf", &b);

    printf("\nInserisci il coefficiente della c (cx)\n");
    scanf("%lf", &c);

    double x1, x2;
    int result = resolve_eq2(a, b, c, &x1, &x2);

    if (result == 1) {
        printf("X1: %f\n", x1);
        printf("X2: %f\n", x2);
    } else {
        printf("No real roots.\n");
    }

    return 0;
}

int resolve_eq2(double a_coeff, double b_coeff, double c_coeff, double *x1, double *x2) {
    double delta = pow(b_coeff, 2) - 4 * a_coeff * c_coeff;

    if (delta >= 0) {
        *x1 = (-b_coeff - sqrt(delta)) / (2 * a_coeff);
        *x2 = (-b_coeff + sqrt(delta)) / (2 * a_coeff);
        return 1;
    } else {
        return 0;
    }
}
