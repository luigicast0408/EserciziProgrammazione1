/* Apertura di un file con varie modalit\`a. 

La funzione perror() interpreta l'ultimo errore avvenuto 
durante una system call o funzione di libreria (variabile errno), 
e stampa il messaggio corrispondente. 

Per l'esecuzione di questo esempio si assume che, all'interno della directory di lavoro, esista solo il file input1.txt. 

input4.txt e input5.txt saranno aperti in modalita' w+ e a (append), in qusto caso i 
due files saranno creati dalla chiamata fopen(). 

La chiamata per input1.txt andra' a buon fine perche' il file esiste. 

Le chiamate per input2.txt (r) ed input3.txt (r+)  produrranno un 
errore in quanto i due files non esistono e tali modalita' non prevedono 
la creazione di nuovi files. 

*/ 


#include <stdio.h> 

int main(){

    const char *f[5] = {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    const char *mode[] = {"r", "r", "r+", "w+", "a"}; 

    FILE *fpArr[5]; 

    for(int i=0; i<5; i++){
	fpArr[i] = fopen(f[i], mode[i]);
	if(!fpArr[i]){ 
	    fprintf(stderr, "\n Error opening file %s with mode %s:  ", f[i], mode[i]);
	    perror(""); // vedi documentazione di perror()
        }
	else
	    printf("\n Opening file %s with mode %s: success", f[i], mode[i]);
    }
}
