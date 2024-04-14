/* Esempio di lettura di caratteri da file -- fscanf() */ 

#include <stdio.h> 
#include <stdlib.h> 

#define SIZE 30 

int main(){

    const char *filename = "output.txt"; // see example 22_02.c
    const char *mode = "r"; 

    FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s", filename, mode); 
	perror(""); 
    }

    char s1[SIZE], s2[SIZE]; 	  
    int ret; 
    unsigned int line_read = 0; 
    unsigned short onemore = 1; 

    while(onemore){
	ret=fscanf(fp, "%s %s", s1, s2); // produce eventualmente EOF (-1) 
	if(feof(fp)){
	    printf("\n\n Reached END OF FILE.."); 
	    onemore = 0; 
	}
	else if(ret==2){ // potrebbe aver letto un numero di elementi minore di 2..
	    fprintf(stdout, "\n Read: \"%s %s\" ", s1, s2);
	    line_read++;
	}
	else{ 
	    fprintf(stderr, "\n Read error, ret=%d \n ", ret);
	    onemore = 0; 
	}
    }

    fprintf(stdout, "\n Read %d lines of text..", line_read); 

    // chiude il file 
    if(fclose(fp)==EOF) 
	perror("\n Error closing file ..");
    return 0;
}
