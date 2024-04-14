#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAGGIO_CERCHIO 1
#define RAPPORTO (M_PI / 4)

int main() {
    int N_punti, punticerchio = 0;
    double x, y;
    srand(time(0));

    printf("\nQuanti punti vuoi generare?\n");
    scanf("%d", &N_punti);

    for (int i = 0; i < N_punti; ++i) {
        x = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        //((double)rand() / RAND_MAX)  converte il numero casuale da intero a virgola mobile, fornendo un valore compreso tra 0.0 e 1.0.
        //* 2.0: moltiplica il valore ottenuto per 2.0, portando il range a 0.0 - 2.0.
        //- 1.0: sottrae 1.0 dal risultato, portando il range a -1.0 - 1.0.
        y = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

        printf("\nX=%f   Y=%f\n", x, y);
        printf("Verifica: %f\n", (pow(x, 2) + pow(y, 2)));

        if ((pow(x, 2) + pow(y, 2)) <= 1)
            punticerchio++;

    }

    double rapporto = (double)punticerchio / N_punti;

    printf("\nrapporto calcolato=%f    Rapporto dato=%f\n", rapporto, RAPPORTO);

    if (rapporto == RAPPORTO) {
        printf("\nE' uguale\n");
    }

    return 0;
}
