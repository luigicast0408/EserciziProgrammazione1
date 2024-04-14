#include "stdio.h"

int main() {
    float num1, num2;
    int N;
    do {
        printf("\n inserisci il  1° numero\n");
        scanf("%f", &num1);
        printf("\n inserisci il  2° numero\n");
        scanf("%f", &num2);
        printf("\nInserisci un numero intero > 1 \n");
        scanf("%d", &N);
    } while (((num1 == num2) || (num1 > 0 && num2 > 0)) && (num1 > num2) && (N < 1));

    int arrotandaN1 = (int) num1;
    int arrotandaN2 = (int) num2;
    printf("\nIl numero in virgola mobi le e' %f\nIl numero arrotonadto e'%d\n", num1, arrotandaN1);
    printf("\nIl numero in virgola mobi le e' %f\nIl numero arrotonadto e'%d\n", num2, arrotandaN2);

    int p;
    printf("\nInsersici P\n");
    scanf("%d", &p);
    //float i = p;
    for (p = arrotandaN1; p <= arrotandaN2; p++) {
        int sommamin = 0;
        for (int j = 0; j < N-1; ++j) {
            sommamin += p;
        }
        int somma_max=0;
        for (int j = 0; j < 2*N; ++j) {
            somma_max += p;
        }
        printf("Per p = %d, la somma dei %d numeri minori di p è %d, e la somma dei %d numeri maggiori di p è %d.\n", p, N-1, sommamin, 2*N, somma_max);
    }

 pippo 5
 paperino 8
}