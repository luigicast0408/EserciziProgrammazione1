#include <stdio.h>

#include <math.h> //Infinity, NAN, pow, sqrt, log, 

int main()
{   
   double unoZero = 0.0; 
   double unValoreNonNullo = 1.0; 
   double unValoreStrano = NAN; //valore "Not A Number"
   
   printf("\nUn double che vale zero : %f", unoZero);
   printf("\nUn double che vale uno : %f", unValoreNonNullo);
   printf("\nUn double che non vale un numero : %f", unValoreStrano);  

    printf("\n** Passaggi al limite: **\n");

	//IEEE 754 
	//1/0 = Inf
   printf("\nSe divido uno per zero ho : %f" , unValoreNonNullo/unoZero);
             
	//-1/0 = -Inf     
   printf("\nSe divido meno uno per zero ho : %f" , (-unValoreNonNullo)/unoZero);
          
	//0/0 = NAN
    printf("\nSe divido zero per zero ho : %f", unoZero/unoZero);

	//-Inf/Inf=NAN
    printf("\nSe divido -Inf per -INf: %f", -INFINITY/-INFINITY);

      
	//0^0=1, 1^+Inf=1, 5^(-Inf)=0, 0^(-Inf)=Inf
    printf("\nSe innalzo zero a zero ho : %f", pow(unoZero,unoZero));
    printf("\ned anche 1 a piu' infinito : %f", pow(1.0, 1.6E308*1.6E308));
    printf("\n invece 5 elevato a meno infinito :%f ", pow(5.0, - 1.6E308*1.6E308));
    printf("\nInfine 0 elevato a meno infinito : %f", pow(0.0, - 1.6E308*1.6E308)); 

   printf("\nIl valore infinito negativo : %f %f %f ", -INFINITY,\
	-1.0/0.0, log(0)); 

   printf("\nIl valore \"Not A Number\" : %f ", sqrt(-1)); 
  
	//x/-Inf = -0
   printf("\nAncora un passaggio al limite : %f", \
	unValoreNonNullo/-INFINITY);
  
   float z=3.4E38;
   float w=3.4E38;
   float x=z*w;
   // int v=5/0;
    printf("\n %f * %f = %f",z,w, x); 

    //ricordiamo che per gli interi, invece, avremo overflow..
    
	int a=1000000000;
	int b=1000000000; 
	//Per gli interi, avremo overflow!
	printf("\n1 billion x 1 billion: %d", a*b);

    return 0;
} // end main()
