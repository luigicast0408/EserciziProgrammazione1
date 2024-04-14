#include <stdio.h>
#include <stdlib.h>

int main(){

  printf( "\n ** strtol(const char *nptr, char **endptr) **"); 
  //strtol()
  char *end;
  const char *a = "0";
  const char *b = "aa";
    long n; 
  // strotol(cons)
    printf("\n Trying to convert string \"%s\"..", a); 
  if((n=strtol(a, &end, 10))==0 && (*end!='\0')) // error?
    printf( "\n Error while converting string %s", a); 
  else
    printf( "\n Converted: %ld", n); 

    printf("\n Trying to convert string \"%s\"..", b); 
  if((n=strtol(b, &end, 10))==0 && (*end!='\0')) // error?
    printf( "\n Error while converting string %s", b);
  else
    printf( "\n Converted: %ld", n);

  //you may use strtod()..
  const char *c = "k4.5";
    double x;
 
    printf("\n Trying to convert string \"%s\"..", c); 
  if((x=strtod(c, &end))==0 && (*end!='\0')) // error?
    printf("\n Error while converting string %s", c);
  else
    printf( "\n Converted: %f",  x);

  //you may use strtod()..
  const char *ch = "4.5k";
 
    printf("\n Trying to convert string \"%s\"..", ch); 
  if((x=strtod(ch, &end))==0 && (*end!='\0')) // error?
    printf("\n Error while converting string %s", ch);
  else
    printf( "\n Converted: %f",  x);
}
