#include <stdio.h> 
#include "flush_stdin.h"

/* Primo uso di scanf(). 
Specificando la massima lunghezza dell'array (linea 19), si lasciano 
ulteriori caratteri nel buffer, che finirebbero 
per essere acquisiti da eventuali ulteriori letture */ 

int main(){

    char buffer3[11]={};
    char buffer1[6]={0};
    char buffer2[10]={0};
    char flush; 

    printf("\n Inserisci una stringa di max 5 caratteri: ");
    // provare ad inserire 123456789
    // NB: con scanf non vi e' alcun controllo inerente la
    // lunghezza dei dati da scrivere nel buffer!
    // Ma il programmatore puo' in realta' specificarlo nella stringa di formato: %5s
    scanf("%5s", buffer1); // 5 indica che vanno letti al massimo 5 caratteri!

    // NB output del buffer2 (vs %5s..)! 
    printf("\nbuffer1: %s, buffer2: %s \n", buffer1, buffer2);

    // consumare i caratteri in eccedenza nel buffer di input (stdin) 
    fprintf(stderr, "\nflushing.."); 
    // EOF si verifica, nel canale stdin, solo quando 
    // l'utente digita CTRL+d (linux/unix) oppure quando digita CTRL+z (windows) 
//    while((flush = fgetc(stdin))!='\n' && flush !=EOF)
//	fprintf(stderr, " flush=%c ", flush);
    flush_stdin(); 

    // NB scanf non consuma il carattere '\n'
    fprintf(stderr, " flush=%u ", flush); // stampa il codice ascii dell'ultima lettura

    printf("\nProvo a leggere qualcos'altro, inserire una stringa di max 10 caratteri: ");
    scanf("%s", buffer3);
    printf("buffer3: %s", buffer3);

    // i caratteri oltre il quinto sono stati copiati in buffer3!! 
    // per possibile soluzione vedi prossimo esempio svolto, unitamente ad uso di fgets() e fgetc() 
}
