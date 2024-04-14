#include <stdio.h> 

/* Primo uso di scanf 
* Lettura di stringhe. 
*/ 

int main(){

    // una stringa e' formata da una sequenza di caratteri oltre il carattere '\0'
    char nome[31] = {0}; // tutti i caratteri saranno inizialmente '\0'
    char cognome[31] = {0}; // tutti i caratteri saranno inizialmente '\0'
    char buffer1[6]={0};
    char buffer2[10]={0};

    printf("\n Inserisci il tuo nome (max 30 caratteri): ");
    scanf("%s", nome); 
    printf("\n Inserisci il tuo cognome (max 30 caratteri): ");
    scanf("%s", cognome); 

    printf("\n Nome e cognome: %s %s \n", nome, cognome);

    // NB: con scanf non vi e' alcun controllo inerente la  
    // lunghezza dei dati da scrivere nel buffer, a meno che non
    // sia specificato dal programmatore con un modificatore di 
    // di massima ampiezza --> es: %10s  
    
    printf("\n Inserisci una stringa di max 5 caratteri: ");
    // provare ad inserire 123456789
    scanf("%s", buffer1);

    // NB output del buffer2! 
    // Buffer2 viene allocato immediatamente dopo nello stack
    // scanf() copiera' (erroneamente) i caratteri in eccesso 
    // all'interno di buffer2
    printf("buffer1: %s, buffer2: %s \n", buffer1, buffer2); 

    // --> vedi prossimo esempio 8_04_scanf_B.c
}
