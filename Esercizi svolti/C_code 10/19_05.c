#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define M1 10

#define N2 7
#define M2 5

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

  //x allocato dinamicamente 
  printf("\n x[1][2]: %.4f", x[1][2]); 
  printf("\n *(*(x+1) + 2): %.4f", *(*(x+1) + 2)); 
  printf("\n *(x[1] + 2): %.4f", *(x[1]+2)); 
  printf("\n (*(x+1))[2]: %.4f", (*(x+1))[2]);
  printf("\n NB: x=%p, *x=%p", x, *x); 
    printf("\n"); 

  //z allocazione automatica/statica
  printf("\n z[1][2]: %.4f", z[1][2]);
  printf("\n *(*(z+1) + 2): %.4f", *(*(z+1) + 2));
  printf("\n *(z[1] + 2): %.4f", *(z[1]+2));
  printf("\n (*(z+1))[2]: %.4f", (*(z+1))[2]);
  printf("\n NB: z=%p, *z=%p", z, *z);
  printf("\n");

  //attenzione! 
  printf("*(z+1)[2]: %.4f, z[3][0]: %.4f", *(z+1)[2], z[3][0]); 
    printf("\n"); 
}
