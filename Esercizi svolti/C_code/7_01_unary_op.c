#include <stdio.h>

int main(){
    
  int kk=10;
  kk++; // add 1 to kk
  kk--; // subtract 1 from kk 
  kk+=10; // add 10 to kk. 
  kk=kk+10; //same as above

  // kk++ e' come eseguire la sequenza v = kk; kk = kk+1;
  // ++kk e' come seguire la sequenza  kk = kk+1; v = kk

  printf( "kk= %d \n", kk);
  printf( "(kk--)= %d \n", (kk--)); 
  printf( "(--kk)= %d\n", (--kk));
  printf( "kk= %d \n", kk);

   return 0;

}
