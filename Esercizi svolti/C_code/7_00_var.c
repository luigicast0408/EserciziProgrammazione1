#include <stdio.h> // input / output

int main(){

  //1-SIMPLE VARIABLE DEFINITIONS and initialization
  int a=-10;

  //2-COMPILATION ERROR, bad values
 // int j="34"; 
  float k = 10.6; 


  //COMPILATION error, bad names for variables
  //int 6john = 10; // the name cannot start with a number!
 // int can volume; // the name cannot have any space!
  //float double=50.6; // we cannot use a reserved word!

  //int p = 10;
  //int ai = 56 * p;
  //ERROR at compile-time. The instruction above will give a compilation error. p should be defined before its use

  const int Z = 12;
  
//  Z=23; //Compilation error!
  
  int kk=10;
  kk++; // add 1 to kk
  kk+=1; 
  kk = kk +1; 
  kk--; // subtract 1 from kk 
  kk+=10; // add 10 to kk. 
  kk=kk+10; //same as above

  //uso dell'operatore unario in forma prefissa
  int somma = (++kk) + 1; 
  printf("somma = %d, e kk=%d", somma, kk); 

  //uso dell'operatore unario in forma postfissa
  int somma2 = (kk++) + 1; 
  printf("somma2 = %d, ma kk=%d", somma2,kk); 

   return 0;

}
