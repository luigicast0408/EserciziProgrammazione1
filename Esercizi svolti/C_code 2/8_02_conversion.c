#include <stdio.h>

int main(){

    float x = -12345.678; 

    printf("\nx: %+20.3f", x); // .5 --> 5 cifre decimali 

    printf("\nx: %+020.3f", x);  // 20 cifre in totale (segno, punto e cifre)
    // lo '0' prima del 20 --> padding di '0' al posto degli spazi 
    // '+' anteporre il segno prima del numero 
    
    printf("\nx: %-+20.3f", x); // '-' --> allineamento a sinistra (no padding) 

    double y = 123456789.123456; //15 caratteri oltre il punto 

    printf("\ny: %-+10.6f", y); // lunghezza minima 10, ma output piu lungo..OK

    // long, unsigned, char 
    long a = 10000000000;
    printf("\na=%ld", a); // ok, a e' un long int..
    printf("\na=%d", a); // NO! a e' un long int, genera un warning..

    long k = 10e12; // long 
    printf("\n k=%ld", k);

    printf("\n k=%e", (double) k); // serve un type-cast

    unsigned i = 123456; 
    printf("\ni=%u", i); 

    char c = 'h';
    printf("\nx=%hhd", c); // e' un numero..

    printf("\nx=%c", c); // stampa il carattere..

    // stampare una stringa o un carattere? 
    const char *messaggio = "Hello world!";
    printf("\nmessaggio=%s", messaggio); // e' un numero..

    // notazione esponenziale 
    printf("\ny=%e", y); // notazione esponenziale (occhio alla precisione!)
    printf("\ny=%.15g", y); // notazione esponenziale (massima precisione ammessa)
    printf("\ny=%.15g", y); // notazione esponenziale se necessario 

    double z = 12345.12345; 
    // g--> notazione esponenziale (se esponente < -4 o maggiore della precisione specificata)
    printf("\nz=%.10g", z); 

   //stampare in formato esadecimale 
   // la stampa del numero double mostra segno, mantissa ed esponente (IEEE 754)
   printf("\ndouble in hex format: %a", 223.45678); // lettere minuscole 
   printf("\ndouble in hex format: %A", -223.45678); // lettere maiuscole
   printf("\ninteger in hex format: %x", 1234); // lettere minuscole 
   printf("\ninteger in hex format: %x\n", -1234); // lettere maiuscole
}
