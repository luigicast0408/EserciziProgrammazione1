#include <stdio.h>

/* 
 * NB: Per attivare i warning sulle conversioni, 
 * usare il seg. flag di GCC: -Wconversion 
 */ 

int main(){

   //COMPILATION WARNING: overflow!
   int b=(1.0E100); 
   printf("\n b=1.0E100 (no cast), %d ", b);

   //NO warning, ma casting inutile
   int a=(int) (1.0E100);
   printf("\n a=1.0E100 (with cast): %d", a);
  
   //Anche qui casting e' inutile, nessun  warning
  //ma nella conversione a int perdiamo informazioni
   int c=(int) (1.123456);
   printf("\n c=1.123456 (with cast): %d", c);

   //rounding to int value
    //per arrotondare correttamente
   float price = 34.6;
   int rounded = price + 0.5;

   printf("\n Price: %f, price rounded: %d",price, rounded);

    //rounding to int value, but want to leave 
    //the result in a floating point variable. 
    //How? Explicit conversion
   float rounded1 = (int) (price + 0.5);
   printf("\n Price (float) : %f, float rounded: %f", price, rounded1);
  
}
