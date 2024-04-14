#include <stdio.h>



// Uso di sizeof!! 

int main(){

   //How many bytes? It (partially) depends on the implementation. 
   printf( "signed char  -> %lu \n", sizeof (signed char));
   printf( "unsigned char  -> %lu \n", sizeof (unsigned char));
   printf( "short int  -> %lu \n", sizeof (short int));
   printf( "int        -> %lu \n", sizeof (int));  
   printf( "unsigned int -> %lu \n", sizeof (unsigned int));
   printf( "long int   -> %lu \n", sizeof (long ));
   printf( "long long  -> %lu \n", sizeof (long long));
   printf( "float      -> %lu \n", sizeof (float));
   printf( "double     -> %lu \n", sizeof (double));
   printf( "long double-> %lu \n", sizeof (long double)); 
   printf( "void *-> %lu \n", sizeof(void *));

}
