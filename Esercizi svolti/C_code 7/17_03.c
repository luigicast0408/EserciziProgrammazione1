#include <stdio.h>

int main(){

  int x;
  double y; 
  float f; 

  const char *integer1 = "22aa1234";
  const char *integer2 = "1234";

  const char *floating_point_number = "1234.199456789"; 

  //converte il numero intero, solo la prima cifra!
  printf("\n The integer1 string is %s", integer1); 
  if(sscanf(integer1, "%1d", &x)<1)
    fprintf(stderr, "\n Error parsing integer1 number!"); 
  else 
    printf("\n The integer number is %d", x);

  //converte il numero intero, le prime due cifre
  printf("\n\n The integer1 string is %s", integer1);
  if(sscanf(integer1, "%d", &x)<1)
    fprintf(stderr, "\n Error parsing integer1 number");
  else 
    printf("\n The integer number is %d",  x);

  //le prime tre cifre di integer3
  printf("\n\n The integer2 string is %s", integer2); 
  if(sscanf(integer2, "%3d", &x)<1)
    fprintf(stderr, "\n Error parsing integer2 number"); 
  else 
    printf("\n\n The integer number is %d", x); 

  //float: lettura di 4 cifre (incluse le cifre a sinistra della virgola e la virgola!)
  printf("\n\n The floating point number string is  %s", floating_point_number);
  if(sscanf(floating_point_number, "%4f", &f)<1) // f is ``floating point number'', i.e. float
    fprintf(stderr,"\n Error parsing floating point number");
  else
    printf("\n Read number %f", f);

  //float: lettura di 10 cifre (incluse le cifre a sinistra della virgola!)
  printf("\n\n The floating point number string is %s ", floating_point_number);
  if(sscanf(floating_point_number, "%10f", &f)<1) // lf is ``long floating point number'', i.e. double
    fprintf(stderr, "\n Error parsing floating point number");
  else
    printf("\n Read number %10f \n", f);
}
