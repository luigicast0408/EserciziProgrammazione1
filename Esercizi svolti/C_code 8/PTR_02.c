#include <stdio.h>

int main(){
  
   int vals[] = {4,3,2,1};
  
   int *ptr = vals;
   ptr++;

   printf("\n *ptr: %d", *ptr);

   ptr+=2;
   printf("\n *ptr: %d", *ptr);

   ptr-=1; // now point to 2 
       
}
