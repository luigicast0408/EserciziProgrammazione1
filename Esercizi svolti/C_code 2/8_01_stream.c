#include <stdio.h>

int main(){
    printf("Hello world (stdout)!\n"); 

    //oppure 

    fprintf(stdout, "Hello world (stdout)!\n"); 

    //oppure stderr..

    fprintf(stderr, "Hello world (stderr)!\n"); 

    /*compilare il programma: 
    *	gcc -o 8_01 8_01_stream.c
    * poi eseguire con "redirezione" dello standard output su disco 
    *	./8_01 > output.txt 
    * ancora: 
    *	./8_01 > output.txt 2>&1 
    * qual e' la differenza? 
    * NB: ignorare l'ordine dei messaggi conservati su file, 
    * cio' e' probabilmente dovuto alla bufferizzazione 
    * dello output, cosa che non avviene per lo stderr !
    */ 
    

}
