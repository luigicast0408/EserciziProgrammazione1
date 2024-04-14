#include <limits.h>

#include <float.h>

#include <stdio.h>

int main(){

  printf("INT_MIN: %d \n", INT_MIN);
  printf("INT_MAX: %d \n\n", INT_MAX);

  printf("FLOAT_MIN: %E \n", FLT_MIN); // modulo 
  printf("FLOAT_MAX: %E \n\n", FLT_MAX); // modulo 

  printf("DOUBLE_MIN: %E \n", DBL_MIN); // modulo 
  printf("DOUBLE_MAX: %E \n\n", DBL_MAX); // modulo 

  printf("LONG DOUBLE_MIN: %LE \n", LDBL_MIN); // modulo 
  printf("LONG DOUBLE_MAX: %LE \n\n", LDBL_MAX); // modulo 

  printf("FLT_DIG: %d \n", FLT_DIG); // precisione float
  printf("DBL_DIG: %d \n", DBL_DIG); // precisione double
  printf("LDBL_DIG: %d \n", LDBL_DIG); // precisione double

}
