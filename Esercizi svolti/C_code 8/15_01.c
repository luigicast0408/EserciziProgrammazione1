#include <stdio.h>

#define V_L 8

#define SIZE 5

/* Stampa gli elementi del vettore 
  mediante aritmetica dei 
  puntatori e operatore [] + indici 
*/ 
void f(int a[]){
  //stampa il puntatore 
  printf("\nf(), a: %p ", a);
  //stampa il valore all'indice 0 (primo elemento) 
  printf("\nf(), a[0]: %d", a[0]);
  //stampa il valore del primo elemento mediante aritmetica dei puntatori  
  printf("\nf(), *a: %d", *a);

  //stampa il valore del puntatore del secondo elemento 
  printf("\nf(), a: %p", a);
  //stampa il valore dello elemento all'indice 1
  printf("\nf(), a[1]: %d", a[1]);
  //stampa il valore del secondo elemento 
  printf("\nf(), *(a+1)=: %d", *(a+1));

   printf("\n"); 
}

/* 
  Mostra la relazione 
  tra gli indirizzi del 
  vettore passato come argomento, 
  per mostrare che lo array e' fatto di 
  celle di memoria contigue. 
*/
//void showAddr(int *v, int n);  
void showAddr(int  v[], int n){
  printf("\n showAddr() \n");
  int *prev = NULL; 
   for(int i=0; i<n; i++){
      printf("Address-of(v[%d])=%p", i, &(v[i])); 
      if(&v[i] == prev+1)
	printf(" == Address-of(v[%d])+1 (Pointer arithmetic) \n", (i-1));
      else 
	printf("\n");
      prev = &v[i];
    }
}

int main(){

  //Array allocato sullo stack 
  int a[SIZE] = {1,2,3,4,5};

  showAddr(a, SIZE); 

  f(a);
}
