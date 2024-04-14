#include <stdlib.h>
#include <stdio.h>

int main(){ 

  printf("\n %d", atoi("012")); 
  printf("\n %d", atoi("aa012")); // output == 0 !! 
  printf("\n %d", atoi("0")); 
  printf("\n %d", atoi("-12")); 

  printf("\n %f", atof("0.14")); 
  printf("\n %f", atof("aa0.12")); // output: 0. No controllo errore...

  // Meglio con sscanf().. 

  float f1; 
    int ret; 
  if((ret=sscanf("0.14", "%f",  &f1))<1)
    fprintf(stderr, "\n Error getting number with sscanf()..");

  else
    printf("\n Read float (f1): %f, ret=%d", f1, ret); 

  //In caso di errore..
  float f2; 
  if((ret=sscanf("a0.14", "%f",  &f2))<1)
    fprintf(stderr, "\n Error getting number f2 with sscanf()..");

  else
    printf("\n Read float (f2): %f, ret=%d", f2, ret); 
     
}
