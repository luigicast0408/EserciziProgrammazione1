#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define M1 10

#define N2 7
#define M2 5



/* 1) Va bene solo se il parametro attuale
  rappresenta un array bidimensionale allocato
  dinamicamente.
*/ 
void f1(double *x[], int n, int m){

  printf("\n"); 

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      printf(" x[%d][%d]=%.4f", i, j, x[i][j]);
    printf("\n"); 
  }

  printf("\n");

}

/* Forma equivalente alla 1)
*/
void f2(double **x, int n, int m){

  printf("\n"); 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      printf(" x[%d][%d]=%.4f", i, j, x[i][j]);
    printf("\n"); 
  }

  printf("\n");
}

/* 
 * Bisogna passare una matrice allocata 
 * sul segmento DATA o sullo stack. 
*/ 
void f3(double z[][M2], int n){

  printf("\n"); 
  for(int i=0; i<n; i++){
    for(int j=0; j<M2; j++)
      printf(" z[%d][%d]=%.4f", i, j, z[i][j]);
    printf("\n"); 
  }

  printf("\n");
}

/* Allocazione dinamica vs automatica/statica
* di matrici e passaggio come argomenti di funzioni. 
*/
int main(){

  srand(111222333);

  //allocazione dinamica di uno array di N1 punt. a double 
  double **x = (double **) malloc(sizeof(double *)*N1); 

  //oppure allocazione automatica di un array di N2 punt. a double
  double * y[N2]; // 

  //una matrice z, allocazione automatica 
  double z[N1][M2];

  //dynamic allocation of x
  for(int j=0; j<N1; j++)
    x[j] = (double *) malloc(sizeof(double)*M1);
  
  //dynamic allocation of the rows of y
  for(int j=0; j<N2; j++)
    y[j] = (double *) malloc(sizeof(double)*M2);
  
  //initialization of x
  for(int i=0; i<N1; i++)
    for(int j=0; j<M1; j++)
      x[i][j] = rand()/(double) RAND_MAX;

  //initialization of y
  for(int i=0; i<N2; i++)
    for(int j=0; j<M2; j++)
      y[i][j] = rand()/(double) RAND_MAX;

  //initialization of z
  for(int i=0; i<N1; i++)
    for(int j=0; j<M2; j++)
      z[i][j] = rand()/(double) RAND_MAX;

  printf("\n f1(x)..");
  f1(x, N1, M1); //ok

  printf("\n f2(x)..");
  f2(x, N1, M1); //ok

  //f3(x, N2); // Errore di compilazione!

  printf("\n f1(y)..");
  f1(y, N2, M2);

  printf("\n f2(y)..");
  f2(y, N2, M2);
  //f3(y, N2);//  Errore di compilazione!

  printf("\n f3(z)..");
  f3(z, N1);

  //f2(z, N1, M2); // Errore di compilazione!! 

  printf("\n Inoltre: sizeof(z)= %zd", sizeof(z));
  printf("..infatti: N1=%d, M2=%d. N1xM2xsizeof(double)=%zd", N1, M2, N1*M2*sizeof(double)); 

  printf("\n Invece: sizeof(x)=%zd, sizeof(y)=%zd", sizeof(x), sizeof(y)); 
  printf("..infatti: N2=%d, sizeof(double)xN2=%zd", N2, N2*sizeof(double));

    printf("\n");
}
