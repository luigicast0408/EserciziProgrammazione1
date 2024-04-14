#include <stdio.h>
#include <limits.h>

int main(){

   // 1-Integer overflow!
   printf("\nOverflow: INT_MAX=%d, INT_MAX+1000=%d", INT_MAX, INT_MAX+1000);
   
   // 2-No overflow! Suffix used! Compiler knows that 1000L is a long and applies a  promotion
   printf("\nNo overflow: INT_MAX=%d, INT_MAX+1000=%ld", INT_MAX, INT_MAX+1000L);

   /*
   * Suffixes:  LL for long long, L for long, f for float
   */
   
   //The result will be an integer, no conversion to floating point
   printf("\n\nNo promotion: (3+4+6)/2=%f", (3+4+6)/2); 

   //Now the printed result should be fine, 2.0 is a double
   printf("\nPromotion to double: (3+4+6)/2=%f", (3+4+6)/2.0); 

   //The result should be fine also in this case, 2.0 is a float. We use a suffix
   printf("\nPromotion to float: (3+4+6)/2=%f", (3+4+6)/2.0f);
  
   //overflow for a float say us we have obtained infinity! 
    float res = 10E10*10E30;
    printf("'\n\nUn risultato float molto grande : %f", res);

}
