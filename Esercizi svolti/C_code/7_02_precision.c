#include <math.h>
#include <stdio.h>

//FLOATING POINT NUMBERS 

int main()
{

    //single precision
    float b = 5.123456789f;	//precisione singola

    printf("b è in singola precisione, b=%.6f\n", b);
    //7 e 8 cifre, arrotondamento
    printf("b è in singola precisione, b=%.7f\n", b);
    printf("b è in singola precisione, b=%.8f\n", b);

    // double precision    
    double c = 0.123456789123456789123456;
    printf("c è in doppia  precisione, c= %.6f \n", c);
    printf("c è in doppia precisione, c=%.7f \n", c);
    printf("c è in doppia precisione, c=%.8f \n", c);
    printf("c è in doppia precisione, c=%.9f \n", c);

    //20 cifre, arrotodamento dopo la ?? cifra
    printf("c è in doppia precisione, c=%.19f \n", c);

    //4-Scientific notation
    double d = 1E06;		// scientific notation
    double e = 2E-9;		//scientific notation
    float f = 1.3E3;		// scientific notation 
    printf("\n %.3E \n", d);

    printf("%.3E \n", e);
    printf("%.3E \n", f);

    //5-UNINITIALIZED variable (Warning at compile-time if you set the flag "-Wall"). What about the value of NI? 
    int ni;
    printf("\n Var ni was not initialized, ni=%d\n", ni);

    //Constant values
    const int MY_CONSTANT = 60;
    //kk=kk*MY_CONSTANT; // OK 

    //  MY_CONSTANT=10; you cannot assign again a value to a constant
    //compiler error!

    printf("\n MY_CONSTANT= %d\n ", MY_CONSTANT);


  //0.55 = 0.100011001100...1100... (base 2) ovvero numero non rappresentabile in base 2 con numero 
   // finito di cifre
   printf("0.55 double: 6 10 15 20 cifre dopo la virgola..\n");
  printf("%.6f \n", 0.55); // %.xf stampa x cifre dopo la vorgola. Il letterale e' rappresentato, by default come  double
  printf("%.10f \n", 0.55);
  printf("%.15f \n", 0.55);

  printf("%.20f \n", 0.55); // si vede errore di troncamento, dovuto a periodicita'


  // 0.125 rappresentabile 0.001 (base 2)
  printf("%.6f \n", 0.125);
  printf("%.10f \n", 0.125);
  printf("%.15f \n", 0.125);

  printf("%.20f \n", 0.125); // nessun errore di troncamento 

    //1-Errori di rappresentazione (-->arrotondamento)
    double price = 4.35;
    int cents = 100 * price;	// Should be 100 * 4.35 = 435
    printf("\n %f dollars in cents: %d \n", price, cents); 
	
    // non è sempre quel che si vede ...  
    printf("4.35 with 16 digits: %.16f \n", 4.35);
    cents = 100000000 * price; 
    printf("\tThen.. \n"); 
    int result = 4.35 * 100;
    printf("Cents(): %d\n", result);
    //Solution: just add 0.5 to round to the nearest integer   
    
    result = (int) (4.35 * 100 + 0.5); 
    printf("\tBut.. \n"); 
    printf("Cents(+0.5): %d\n", result); 
      /*The binary representation of 4.35 is 100.01 0110 0110 0110 ...
	An exact representation of the number 0.35 in the binary system does not exist
	( as, in the case of 1/3=0.333333 in the decimal system).
	Therefore, computing 4.35 * 100 in binary representation 
	will be 110110010.11111111...
	an "infinite" number of literal 9 as decimal after 434 434.999999...
	But the machine is able to represent only a finite   number of 1s. 
	The results is 434.99999... which, if represented as integer will be 434!!  
        Why? The rounding to an integer discards the fractional part! 
    */
																       /* Errori di approssimazione (troncamento) 
	La radice di 2 è un numero irrazionale, la sua computazione 
	sarà as un certo punto "troncata" quindi calcoliamo un valore troncato */
	
	double r = sqrt(2.0);	//irrational number! 

	double two = r*r; // 2.0 ??? No! 

	printf("\nsqrt(2.0)=%.15f \n", r);
	printf("sqrt(2.0)=%.20f \n", r);

	printf("\nsqrt(2.0) * sqrt(2.0)=%.10f\n", two);
	printf(" (15 cifre) sqrt(2.0) * sqrt(2.0)=%.15f\n", two); 
	printf(" (18 cifre) sqrt(2.0) * sqrt(2.0)=%.18f\n", two);
	printf(" (20 cifre) sqrt(2.0) * sqrt(2.0)=%.20f\n", two);

	printf("\n (20 cifre) 2.0=%.20f\n",2.0);
    }

