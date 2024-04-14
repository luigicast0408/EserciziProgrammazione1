//Per compilare l'intero programma: "gcc PTR_13.cpp array_ptr.c" 
//oppure creare un progetto con un ide e includere il file header, il file 
//sorgente PTR_13.c ed il file sorgente array_ptr.c

#include <stdio.h>
#include <stdlib.h>

int main(){

    int maxsize=5;

    int *iptr;  //pointer to the dynamic array
    int  *iptrold; // auxiliary pointer

    int num;  //get input by the user

    iptr = (int *) malloc(sizeof(int)*maxsize); // allocazione array

    int count=0;

   int ret; // for IO

    printf("\nEnter a number: "); // chiede il primo numero all'utente
    ret=scanf("%d", &num);

    while(ret!=EOF) // per finire basta premere CTRL-d
    {
        if (count < maxsize)
        {
            iptr[count] = num; // OK, conserva il valore nel primo posto disponibile 
            count++; // e incrementa il contatore
        }
	else
        {
            printf("\nReached maxsize");
            iptrold=iptr; // conserviamo il puntatore all'area di memoria attuale
            iptr = (int *) malloc(sizeof(int)*(maxsize*2));
            for (int i=0; i<maxsize; i++) // copia i valori nella nuova area di memoria 
	      *(iptr+i) = *(iptrold+i);

	    free(iptrold); //libera area puntata da iptrold
            iptrold=NULL; // adesso iptrold e' NULL
  
            iptr[count] = num; //conserva il valore
            count++; // incrementa il contatore
            maxsize=maxsize*2; // aggiorna maxsize

        }
        printf("\nEnter a number: ");
        ret=scanf("%d", &num);
  }
}


