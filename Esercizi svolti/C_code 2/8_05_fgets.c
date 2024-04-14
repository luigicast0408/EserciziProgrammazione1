#include <stdio.h> 
#include <string.h>
#include "flush_stdin.h"

#define SIZE 6

/* 
* Alternativa a scanf, ovvero fgets() 
* Uso di fgetc() per scartare eventuali ulteriori caratteri rimasti nel 
* buffer di input, attraverso la funzione flush_stdin() implementata 
* nel sorgente flush.c. 
* Uso condizionato della funzione flush_stdin()
*/  

int main(){

    // una stringa e' formata da una sequenza di caratteri oltre il carattere '\0'
    char buffer1[SIZE]={0};
    char buffer2[SIZE]={0};
    printf("\n Inserisci una stringa per buffer1 (max 5 caratteri): ");
    //fgets(..., stdin) legge dallo standard input SIZE-1 caratteri, gli altri saranno lasciati sul buffer di input!
    // alternativa a scanf() in cui si specifica la massima ampiezza della stringa..
    // NB: la funzione fgets pone nel buffer anche eventuale carattere di new line '\n'
    if(!fgets(buffer1, SIZE, stdin))
	fprintf(stderr, "fgets(), errore!"); 

    // Esempio: La stringa Ciao (4 caratteri) --> buffer: c i a o '\n' \0 / 5 caratteri H16.4 E L L O 0
    // '\n' viene eventualmente inserito nel buffer dalla funzione fgets()     
    if(buffer1[SIZE-2]!='\n' && strlen(buffer1)==(SIZE-1))
	flush_stdin();     
    else // e se volessimo poi eliminare il carattere '\n'
	buffer1[strlen(buffer1)-1]='\0'; 

    printf("\n Inserisci una stringa per buffer2 (max 5 caratteri): ");
    if(!fgets(buffer2, SIZE, stdin))
	fprintf(stderr, "fgets(), errore!"); 

    if(buffer1[SIZE-2]!='\n' && strlen(buffer1)==(SIZE-1))
	flush_stdin();
    else 
	buffer2[strlen(buffer2)-1]='\0'; 

    printf("\n buffer1: %s, buffer2: %s", buffer1, buffer2);
}
