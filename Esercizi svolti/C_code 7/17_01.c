#include <stdio.h>

int main(){
  
    char *p = "test"; 
    // NB: p punter\`a ad un blocco di memoria in sola lettura. 
    //p[2] = 'c'; // errore a tempo di esecuzione! 

    const char *p1 = "test"; // OK 
    //p1[2] = 'c'; // errore a tempo di compilazione, corretto!
		  //--> Nessun pericolo di errore a tempo di esecuzione..

    char ptr[] = "test\0"; //carattere null alla fine e' inutile, lo avrebbe aggiunto il compilatore!

    //con la lista di inizializzatori e' invece necessario inserire il carattere null!
    const char ptr1[] = {'a', 'b', 'c', '\0'};
 
    //Attenzione alla mancanza del carattere null (vedi istruzione che stampa ptr2..)
    const char ptr2[] = {'a', 'b', 'c'};    

    //osservare il risultato..
    printf("\n p: %s, ptr: %s, ptr1: %s, ptr2: %s \n", p, ptr, ptr1,  ptr2);

}
