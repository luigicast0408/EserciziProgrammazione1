#include <stdio.h>

int main(){

    printf("1234 \t 1234"); 
    printf("\n1234 \v"); // corrisponde ad un tab "verticale", ovvero una sequenza di new line 
    printf("\n1234 \b"); // dovrebbe emettere un "bip"
    printf("\n123456789 \r 9876-\n");  // il cursore ritorna indietro, 9876- sara' stampato al posto di 12345

    printf("%%\n"); 

    printf("\nvirgolette singole: 'Hello world!' vorgolette doppie: \"Hello world!\" \n"); 


}
