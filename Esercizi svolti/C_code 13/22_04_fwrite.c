/* Esempio di scrittura di record in un file ad accesso casuale. 
Uso della funzione fwrite (blocchi), che consente di scrivere bytes. 
*/ 

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

struct record { 
    char nome[30]; 
    char cognome[30];
    unsigned short eta; 
}; 

int main(){

    const char *filename = "data.bin"; // vedi esempio 22_02.c
    const char *mode = "a+"; 

    struct record record_to_write; 

    unsigned short nwrite = 0; 
    int ret;  
    unsigned short onemore = 1; 

    FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s", filename, mode); 
	perror(""); 
    }

    do{
	printf("Inserire nome, cognome, eta' separati da spazi: ");
	if((ret=scanf("%s %s %hu", record_to_write.nome, record_to_write.cognome, &record_to_write.eta))==EOF)
	    onemore = 0;  
	else if (ret<3)
	    fprintf(stderr, "\n Numero di elementi immessi non sufficiente!");

	else{
	    if(fwrite(&record_to_write, sizeof(struct record), (size_t) 1, fp)<1){
		perror("\n Error writing record "); 
		onemore = 0; 
	    }

	    else
		nwrite++;
	    }
	
    }while(onemore); // finche' l'utente non preme CTRL-z oppure CTRL-d (windows)

    printf("\n Written %hu record in file %s", nwrite, filename); 

    // chiude il file  
    if(fclose(fp)==EOF) 
	perror("\n Error closing file ..");
    return 0;
}
