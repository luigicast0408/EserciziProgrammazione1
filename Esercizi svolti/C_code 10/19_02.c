#include <stdlib.h>
#include <stdio.h>

#define SIZE 10


/* Allocazione dinamica di array monodimensionali */
int main(){

  srand(111222333); 

  int *a = (int *) malloc(sizeof(int) * SIZE); //allocazione dinamica di un array di int
  
  //allocazione dinamica di un array di double 
  double *x = (double *) malloc(sizeof(double) * SIZE); 

  for(int j=0; j<SIZE; j++){
    x[j] = rand()/(double) RAND_MAX;
    a[j] = rand()%1000; 
  }
    
  for(int j=0; j<SIZE; j++){
    printf("\n a[%d]=%d, x[%d]=%.4f", j, a[j], j, x[j]); 
  }

    printf("\n");  

  for(int j=0; j<SIZE; j++){
    printf("\n a[%d]: %d, x[%d]: %.4f", j, *(a+j), j, *(x+j)); 
  }

    printf("\n");  
}
