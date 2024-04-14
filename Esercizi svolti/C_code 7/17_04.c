#include <stdio.h>

int main(){

  int a=10; 
  float x = 43.567; 
  double alpha = 123.456789123; 

  char str[100];

  sprintf(str, " Intero a: %d, x: %.6f, alpha: %.12f", a, x, alpha); 

  printf("str: %s\n ", str); 

}
