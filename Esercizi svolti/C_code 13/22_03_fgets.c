/* Esempio di lettura di linee di testo da un file, funzione fgets */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 51

int main(){

    const char *filename = "output_fputs.txt"; // see example 22_02.c
    const char *mode = "r";

    printf("\n Opening file %s", filename);

    FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s", filename, mode);
	perror("");
    }

    char s[SIZE];
    unsigned int line_read = 0;
    unsigned short onemore = 1;

    while(onemore){
	if(fgets(s, SIZE, fp)==NULL){
	    if(feof(fp)){ // fine del file 
		fprintf(stderr, "\n\n END OF FILE..");
		onemore=0;
	    }

	    else{ // altro errore..
		fprintf(stderr, "\n Read error");
		onemore = 0; 
	    }
	}

	else { // ok 
	    fprintf(stdout, "\n Read: \"%s ", s);
	    line_read++;
	}
    }

    fprintf(stdout, "\n Read %d lines of text..", line_read); 

    // chiude il file 
    if(fclose(fp)==EOF) 
	perror("\n Error closing file ..");
    return 0;
}
