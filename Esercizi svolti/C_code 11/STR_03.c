#include <string.h> //strlen(), strcpy(), etc
#include <stdlib.h> // atoi, atol, etc
#include <stdio.h>



int main(){
  
  char str1[] = "1";
  char str2[] = "12";
  char str3[] = "13a";
  char str4[] = "a13";
  char str5[] = "0";

  int n; 

  // atoi 
  printf("\n** atoi(const char *s) **"); 
  printf("\n %d", atoi(str1)); 
  printf("\n %d",  atoi(str2)); 
  printf("\n %d", atoi(str3)); 
  printf("\n %d", atoi(str4));  // error! 
  printf("\n %d", atoi(str5));  // zero! 

  printf("\n ** atoi()/atof() **"); 
  int l = atoi("1000000000000"); //overflow
  printf( "l: %d", l); 

  long int k = atol("1000000000000"); //long
  printf( "k: %ld", k); 

  double x = atof("4.567");
  printf( "\n x: %f", x);

  x = atof("4.5E10");
  printf( "\n x: %f", x); 

  x = atof("4.5k"); //ok 
  printf( "\n x: %f", x); 

  x = atof("k4.5"); //ERR
  printf( "\n x: %f", x);  
}
