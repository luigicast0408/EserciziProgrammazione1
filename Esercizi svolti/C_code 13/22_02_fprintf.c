/* Esempio di scrittura di linee di testo su un file mediante fprintf */ 

#include <stdio.h> 
#include <stdlib.h>
FILE *open_file(char *mode, char *file_name);

/* genera stringhe random */
void gen_strings(unsigned short l1, unsigned short l2, char **s1, char **s2){

    *s1 = (char *) malloc(sizeof(char) * (l1+1));
    *s2 = (char *) malloc(sizeof(char) * (l2+1));

    //generate alphabetical characters 
    for(unsigned short i=0; i<l1; i++){
	(*s1)[i] = (char) (rand() %('z' - 'a' + 1) + 'a');
    }
    (*s1)[l1] = 0;

    //generate numerical characters 
    //generate alphabetical characters 
    for(unsigned short i=0; i<l2; i++){
	(*s2)[i] = (char) (rand() %('9' - '0' + 1) + '0');
    }
    (*s2)[l2] = 0;
}

int main(){

    char *filename = "output.txt";
    char *mode = "w";

    /*FILE *fp = fopen(filename, mode); // append
    if(!fp){
	fprintf(stderr, "\n Error opening file %s with mode %s", filename, mode); 
	perror("ERRORRRR! "); 
    }*/

    //printf("\n Opened file %s for writing..", filename);
    FILE *fp= open_file(mode,filename);

    char *s1, *s2; 	  
    int ret; 

    for(int i=0; i<10; i++){
	gen_strings((unsigned short) (rand()%10 + 5), (unsigned short) (rand()%5 + 5), &s1, &s2);
	if((ret=fprintf(fp, "%s %s\n", s1, s2))<0){
	    perror("\n Error writing to file ..");
	    break;  
	}

	else {
	    // per scaricare il buffer sul file..
	    fflush(fp);  // provare a commentare.. 
	    printf("\n written %d characters", ret);  
	    free(s1); 
	    free(s2); 	
	}
    }

    // chiude il file 
    if(fclose(fp)==EOF) // implica in ogni caso una invocazione della funzione fflush()..
	perror("\n Error closing file ..");
    else
	printf("\n File %s closed", filename); 
    return 0;
}

FILE *open_file(char *mode, char *file_name){
    FILE *fp= fopen(file_name,mode);
    if(!fp){
        fprintf(stderr, "\n Error opening file %s with mode %s", file_name, mode);
        perror("ERRORRRR! ");

    }
    return fp;

}