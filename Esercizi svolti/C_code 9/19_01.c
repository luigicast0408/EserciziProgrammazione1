#include <stdio.h>
#include <stdlib.h>

/* allocazione dinamica di tipi primitivi */ 
int main(){

  /* Operatore new del C++ */

  int b; //stack 
  int *a = (int *) malloc(sizeof(int)); // un intero sul free store

  double *d = (double *) malloc(sizeof(int)); // un double sul free store
  
  *a = 10; 
  *d = 34.123466;  
    

  printf("\n *a=%d, *d=%f", *a, *d); 

}
