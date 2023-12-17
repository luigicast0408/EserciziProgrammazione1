#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(){

  srand(111222333);

  unsigned int *a = (unsigned int *) malloc(sizeof(unsigned int) *SIZE); //allocazione dinamica di uno array di int
  
  //allocazione dinamica di un array di double 
  double *x; 
  x= (double*) malloc(sizeof(double) * SIZE);  

  for(int j=0; j<SIZE; j++){
    x[j] = rand()/(double) RAND_MAX;
    a[j] = rand()%1000; 
  }

  //accesso agli elementi mediante operatore [] e indice     
  for(int j=0; j<SIZE; j++){
    printf("\n a[%d]=%u, x[%d]=%.4f", j, a[j],j, x[j]);
  }
   
  //accesso agli elementi mediante aritmetica dei puntatori 
  for(int j=0; j<SIZE; j++){
    printf("\n a[%d]=%u, x[%d]=%.4f", j, *(a+j), j, *(x+j));
  }

  //valore del puntatore x
  printf("\n puntatore x prima della free(): %p", x);

  //deallocazione del blocco di mem. puntato da x
  free(x); 

  //valore del punt. dopo la deallocazione 
  printf("\n puntatore x dopo la free(): %p", x);

  //buona norma, dopo deallocazione, 
  //scrivere NULL nel puntatore.
  //Inoltre, prima del tentativo di 
  //deallocazione controllare, il valore del puntatore. 

  if(a){ // MEGLIO
    free(a);
    a = NULL; // MACRO C
  }

  //senza il controllo su a, una seconda free() 
  //avrebbe risultato indefinito (e.g. crash)

}
