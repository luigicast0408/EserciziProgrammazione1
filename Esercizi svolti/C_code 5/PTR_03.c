#include <stdio.h>

int main(){

  float c = 0.4;
  
  //pointers initialization
  float *ptr = NULL;

  if(!ptr)
    fprintf(stderr, "ptr is an invalid pointer!");

  else 
    fprintf(stderr, "ptr is not NULL!");
    
  ptr = &c;

  if(!ptr)
    fprintf(stderr, "ptr is an invalid pointer!");

  else 
    fprintf(stderr, "ptr is not NULL!");
  
  int *p;
  p = &c; // NO! Warning!     
   printf("\n *p: %d", *p); // !! ?? 
     

}
