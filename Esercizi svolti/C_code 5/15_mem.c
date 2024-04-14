#include <stdio.h>
#include <stdlib.h>

//allocazione statica di variabile puntatore (DATA) 
//Scope del puntatore global globale!! 
int *p_global;

//allocazione statica di intero (DATA) 
// Scope globale!!
int global = 10; 

void foo(){
   p_global = (int *) malloc(sizeof(int)); 
   //variabili p_global e global certamente accessibili
  printf("\n foo(), *p_global: %d, global: %d", *p_global, global); 
}

int main(){

  //allocazione automatica (STACK)
  //scope della variabile local locale!!
  int local = 1;

  //allocazione dinamica (HEAP)
  //ma scope del puntatore dynamic locale!! 
  int *dynamic = (int *) malloc(sizeof(int));

  foo();

  printf("\n main(), *p_global: %d, global: %d", *p_global, global);
}
