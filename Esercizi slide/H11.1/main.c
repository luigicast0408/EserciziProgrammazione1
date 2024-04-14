#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

int main() {
    float x, y;
    //float moltiplicazione;
    int scelta;
    printf("\nprimo o secondoi quesito?\n");
    scanf("%d", &scelta);
    switch (scelta) {
        case 1: {

            do {
                // primo caso
                printf("\nInserisci x (>0)\n");
                scanf("%f", &x);
                printf("\nInserisci y (<0)\n");
                scanf("%f", &y);
            } while (x < 0 && y > 1);

            while (x <0) { // < (max)
                printf("\nRisutato della moltilpicazione: %e\n", x *= y);
            }
            if (x*=y==0)
                printf("Hai raggiunto lo zero");
            break;
        }
        case 2: {

            do {
                // primo caso
                printf("\nInserisci x (<0)\n");
                scanf("%f", &x);
                printf("\nInserisci y(<0)\n");
                scanf("%f", &y);
            } while (x > 0 && y < 1);
            while (x <0) { // < (max)
                printf("\nRisutato della moltilpicazione: %el\n", x *= y);
            }
            if (x*=y==0)
                printf("Hai raggiunto lo zero");
            break;
        }
        default: {
            printf("Errore!");
            break;
        }
    }
}
