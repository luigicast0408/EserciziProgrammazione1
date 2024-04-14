#include <stdlib.h>
#include <stdio.h>

void f(int v[], unsigned short n){
    printf("\n f(..)");
  return; 
}

void g(int *v, unsigned short n){
    printf("\n g(..)");
  return;
}

void h(int **v, unsigned short n, unsigned short m){
    printf("\n h(..)");
  return; 
}

void k(int *v[], unsigned short n, unsigned short m){
    printf("\n k(..)");
  return;
}

void foo(int ***v, int n, int m, int l){
    printf("\n foo(..)");
  return; 
}

void bar(int **v[], int n, int m, int l){
    printf("\n bar(..)");
  return; 
}


int main(){

  unsigned short n = 5; 
  unsigned short m = 10; 
  unsigned short l = 7; 

  // array monodimensionale
  int *v = (int*) malloc(sizeof(int)*n);

  // array bidimensionale n x m
  int *w[n];
  for(unsigned short c = 0; c<n; c++)
    w[c] = (int *) malloc(sizeof(int)*m); 

  int ***z = (int***) malloc(sizeof(int **)*n);
  for(unsigned short c = 0; c<n; c++){
    z[c] = (int **) malloc(sizeof(int *)*m);
    for(unsigned short j=0;j<m; j++)
      z[c][j] = (int *) malloc(sizeof(int)*l); 
  }

  f(v, n); // array monodimensionale 
  g(v, n);

  h(w, n, m); //array bidimensionale
  k(w, n, m);

  foo(z, n, m, l); //array a tre dimensioni
  bar(z, n, m, l);
}
