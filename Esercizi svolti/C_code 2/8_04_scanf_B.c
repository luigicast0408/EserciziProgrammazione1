#include <stdio.h> 

/* Uso di scanf(), lettura di stringhe. 
Specificando la massima ampiezza di campo 
ovvero che scanf dovra' leggere non piu' di n caratteri..  */ 

int main(){

    char buffer3[11]={};
    char buffer1[6]={0};
    char buffer2[10]={0};

    printf("\n Inserisci una stringa di max 5 caratteri: ");
    // %5s indica che scanf deve leggere non piu' di 5 caratteri 
    scanf("%5s", buffer1); 

    // provare ad inserire 123456789
    // NB output del buffer2 (OK) 
    printf("\nbuffer1: %s, buffer2: %s \n", buffer1, buffer2);

    printf("\nProvo a leggere qualcos'altro, inserire una stringa di max 10 caratteri: ");
    scanf("%s", buffer3);
    printf("buffer3: %s", buffer3);

    // i caratteri oltre il quinto sono stati copiati (dalla scanf) in buffer3!! 
    
    // --> vedi esempio 8_04_scanf_c.c
}
