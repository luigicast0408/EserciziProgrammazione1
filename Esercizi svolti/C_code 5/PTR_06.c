#include <stdio.h>

#include <time.h>
#include <stdlib.h>

//prototipo della funzione,
//di norma si scrive in un file header
//la fuzione non potra' modificare i valori degli elementi puntati da a e b
int *sum(const int *a, const int *b, int n); 

int main()
{
    
  srand(time(0));

  int *p1 = (int *) malloc(sizeof(int)*10);	
  int *p2 = (int *) malloc(sizeof(int)*10);	

  for(int i=0; i<10; i++ ){ //random values
    p1[i] = rand()%100;
    p2[i] = rand()%100;
  }

  for(int i=0; i<10; i++ ){ //print values
    printf("p1[%d]=%d", i,p1[i]);
  }

   printf("\n");
  
  for(int i=0; i<10; i++ ){ //print values
    printf("p2[%d]=%d", i,p2[i]);
  }

   printf("\n");

  int *c = sum(p1, p2, 10);

  for(int i=0; i<10; i++ ){ //print values
    printf("c[%d]=%d", i,c[i]);
  }


   printf("\n");

 return 0;
}

int *sum(const int *a, const int *b, int n){
  int *res = (int *) malloc(sizeof(int)*n); //allocate the array into the free store

  for(int i=0; i<n; i++)
    res[i] = a[i] + b[i];
  
  return res;  
}
