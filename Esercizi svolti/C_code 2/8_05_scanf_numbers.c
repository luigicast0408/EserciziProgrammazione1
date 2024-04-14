#include <stdio.h> 
#include "flush_stdin.h"

/* Primo uso di scanf */ 

int main(){

    // una stringa e' formata da una sequenza di caratteri oltre il carattere '\0'
    int unintero; 
    float unfloat; 
    double undouble; 

    long int uninterolungo; 

    printf("\n Inserisci un intero: ");
    scanf("%d", &unintero); 

    printf("\n Inserisci numero con la virgola: ");
    scanf("%f", &unfloat); 

    printf("\n Inserisci numero con la virgola (in doppia precisione): ");
    scanf("%lf", &undouble); 

    printf("\nEcco i tre numeri: %d %f %.8f \n", unintero, unfloat, undouble); 

    printf("\n Inserisci un intero di max 3 cifre: ");
    
    scanf("%3d", &unintero); // usa il modificatore di ampiezza di campo 
    printf("\n Unintero: %d\n", unintero);

    flush_stdin(); 

    printf("\n Inserisci un intero lungo: ");
    
    scanf("%ld", &uninterolungo); // usa il modificatore di ampiezza di campo 
    printf("\n Uninterolungo: %ld\n", uninterolungo);
    
}
