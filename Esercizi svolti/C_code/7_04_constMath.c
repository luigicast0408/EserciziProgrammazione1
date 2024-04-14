#include <stdio.h>

#include <math.h> // costanti e funzioni matematiche

int main()
{

   int k=2000000000;
   int j=2000000000;
   int z=k+j;
        
   const short a = 32000;
   const short b = 32000;
   short c;
   c = a+b;  
          
   printf("\nz=%d, c= %d", z, c) ; 
          
   const int COSTANTE_SFORTUNATA = 17; 
   printf("\nUn numero davvero sfortunato : %d", COSTANTE_SFORTUNATA); 

    //COSTANTE_SFORTUNATA = 20; // errore di compilazione! 	
		
   double x = 4.0;
   double y = sqrt(x);
   printf("\nLa radice quadrata di %f e' %f", x, y);			

  double pi = acos(-1);
  printf("\ncos(pi/2) = %f, cos(pi)=%f", cos(pi/2), cos(pi));
                                                 
   double risultato = pow(sin(x),2) + pow(cos(x),2); // elevamento a potenza
   printf("\nVerifichiamo la relazione fondamentale della trigonometria :\n \t\t sin(4)^2+cos(4)^2 = %f", risultato); 

   printf("'\nSQRT(9)= %f \n",  sqrt(9.0));

    return 1;
} // End main()
