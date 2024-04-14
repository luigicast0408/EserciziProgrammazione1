/* Esempio di lettura di record in un file ad accesso casuale. 

Uso della funzione fread, che consente di leggere bytes dal file. 

I bytes saranno memorizzato all'interno di un record (struct). 
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

    const char *filename = "data.bin"; // see example 22_02.c
    const char *mode = "r"; // read mode. The stream is positioned at the end of the file 

    struct record my_record; 

    int ret;
    unsigned short nread = 0; 

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
	}

	else{
	    printf("\n Read: [%s %s %hu]", my_record.nome, my_record.cognome, my_record.eta);	     	
	    nread++;
	}

    }while(!feof(fp)); // finche' il file contiene dati

    printf("\n Read %hu record from file %s", nread, filename); 

    // chiude il file  
    if(fclose(fp)==EOF)
	perror("\n Error closing file ..");
    return 0;
}
