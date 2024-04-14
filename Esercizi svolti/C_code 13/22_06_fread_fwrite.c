/* Esempio di lettura e scrittura di record in un file ad accesso casuale. 

Il file sara' letto dall'inizio per la ricerca di un record. Quando trovato, 
tale record sara' sostituito con un altro. 

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct record { 
    char nome[30]; 
    char cognome[30];
    unsigned short eta; 
}; 

int main(){

    const char *filename = "data.bin"; // see example 22_02.c
    const char *mode = "r+"; // read/write mode. 

    struct record my_record; 

    int ret;  
    unsigned short onemore = 1; 
    unsigned short nread = 0; 
    unsigned short nwrite = 0; 

    const char *key = "bianchi"; 

    printf("\n NB: Il programma cerchera' un record avente cognome \"bianchi\" e sostituira' il nome con \"XXXXX\"");

    FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s: ", filename, mode); 
	perror("");
	return -1; 
    }

    do{
	if((ret=fread(&my_record, sizeof(struct record), 1, fp))<1){ //may be EOF
	    if(feof(fp))
		printf("\n EOF!");
	    else
		printf("\n problema in lettura! "); 
	    onemore = 0;
	}

	else{
	    printf("\n Read: [%s %s %hu]", my_record.nome, my_record.cognome, my_record.eta);	     	
	    if(strcmp(my_record.cognome, key)==0){
		printf("Record found.."); 
		strcpy(my_record.nome, "XXXXX"); // nome <-- Maria

		// offset negativo, in quanto la testina punta alla fine del record a modificare
		// bisogna fare in modo che punti all'inizio del record per una nuova scrittura
		if(fseek(fp, -sizeof(struct record), SEEK_CUR)<0)
		    perror("\n Error in fseek() call");
		else if(fwrite(&my_record, sizeof(struct record), 1, fp)<1)
		    fprintf(stderr, "\n Error writing the updated record..");
		else
		    nwrite = 1; 

		onemore = 0; 		    
	    }
	    nread++;
	}
	
    }while(onemore); // finche' il file contiene dati o finche' non e' avvenuto l'aggiornamento del dato..

    printf("\n Read %hu record from file %s, written %hu record on file %s", nread, filename, nwrite, filename); 

    // chiude il file  
    if(fclose(fp)==EOF) 
	perror("\n Error closing file ..");
    return 0;
}
