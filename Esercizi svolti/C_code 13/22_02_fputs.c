/* Esempio di scrittura di linee di testo su un file -- fputs */ 

#include <stdio.h> 
#include <stdlib.h> 

int main(){

    const char *filename = "output_fputs.txt";
    const char *mode = "w"; 
    char s[51]; 

    FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s", filename, mode); 
	perror(""); 
    }

    printf("\n Opened file %s for writing..", filename); 


    int onemore=1;
    int nw=0;

	do{
	    printf("\n Inserisci una linea di testo (max 50 caratteri) oppure CTRL-d/CTRL-z: "); 

	    if(fgets(s, 51, stdin)==NULL){
		fprintf(stderr, "\n Error reading text from stdin, possibly EOF..");
		onemore=0;
	    }
	    else {
		if(fputs(s,  fp)==EOF){
		    fprintf(stderr, "\n Error writing on file %s", filename);
		    onemore=0;
		}
		else
		    nw++; 
	    }
	}while(onemore && !feof(fp));	

	// chiude il file 
	if(fclose(fp)==EOF) // implica in ogni caso una invocazione della funzione fflush()..
	    perror("\n Error closing file ..");
	else
	    printf("\n File %s closed, %d lines written", filename, nw); 
	return 0;
    }
