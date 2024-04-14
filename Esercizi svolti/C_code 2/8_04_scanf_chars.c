#include <stdio.h> 

/* Primo uso di scanf */ 

int main(){

    char uncarattere; 
    char unaltrocarattere[2]; 
	
    printf("\n Inserisci un carattere: ");
    scanf("%c", &uncarattere); // 1 carattere, si puo' anche scrivere come %1c

    printf("\n Inserisci un altro carattere: ");
    scanf("%1s", unaltrocarattere); // 1 carattere, ma andra' lasciato spazio per il carattere finale '\0'

    printf("\nuncarattere: %c, unaltrocarattere: %s", uncarattere, unaltrocarattere);
}
