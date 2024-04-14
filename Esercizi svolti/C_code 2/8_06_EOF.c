#include <stdio.h> 

int main(){ 

    char buffer[100]; 
    short int n=10; 
    int ret; 

    /* Provare ad inserire alcune stringhe. 
    * a piacere, durante la k-esima scanf(), digitare CTRL-d oppure CTRL-z (windows)
    * --> tutti i successivi tentativi di lettura restituiranno EOF
    * questo spiega il "concetto" di EOF per cio che concerne lo stream di input
    * una volta che l'utente digita EOF lo stream non e' piu utilizzabile 
    * i
    */  

    int i=0;
    while(i++<n){
	printf("\n scanf() #%d (out of %d): ", i, n);
	if((ret=scanf("%s", buffer))==EOF) // NB scanf restituisce il numero di token letti
	    fprintf(stderr, "\n scanf #%d: EOF!", i);
	else {
	    fprintf(stderr, "\n Read %d elements", ret); 
	    printf("\n buffer: %s ", buffer);	
	}
    }
     
}
