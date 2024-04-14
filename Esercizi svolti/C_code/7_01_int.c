#include <limits.h>
#include <math.h>
#include <stdio.h>


int main()
{
  /* Interi, letterali, overflow, rappresentazione in complemento a due. */ 

  //Un INTERO con un letterale intero
  int int1 = 234918743; // OK 

  //Overflow
  int int2 = 23491874399; // Overflow positivo. Segnalato dal compilatore? 
  printf("int1: %d, int2: %d; int2 dovrebbe essere invece %ld \n", int1, int2, 23491874399L);

  //LONG..
  long long1 = 23491874399; // OK, no overflow
  printf("long1: %ld", long1);

  //uso di un letterale in forma esadecimale
  printf("\nNow setting short1 and short2 as 0xffff\n"); 
  unsigned short short1 = 0xffff;
  //uso di un letterale in forma esadecimale per un intero corto CON SEGNO..
  //NB: RAPPRESENTAZIONE COMPLEMENTO A DUE...
  short short2 = 0xffff; // corrispondente valore decimale?   
  printf("short1 (unsigned): %hd, short2 (signed): %hd\n", short1, short2);

  //Divisioni tra interi
  printf("3/2= %d", 3/2);
   
  printf("3/0= %d", 3/0); // la cpu genera un'eccezione
  //1/0=? 

  //cout << "1/0=" << 1/0 << endl; 

} // end main()
