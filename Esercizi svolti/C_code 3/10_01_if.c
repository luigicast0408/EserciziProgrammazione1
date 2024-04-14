#include <stdio.h>



int main(){

  int a, b;
  a=10;
  b=20;

  if(a<b)
    printf("\na < b"); 

  else 
    printf("\na >= b");

  //boolean expression ?? 
  int c=5;
  if(c) //it means c!=0
    printf("\nc is not zero!");

  if(!c) //it means c==0
    printf("\nc is zero!");

  //OR
  if(c==0 || a<b) //L1
    printf("\nc is zero, OR a less than b"); 

  else//???
    printf("c not zero, OR a greater than b");

  //AND 
  if(c==0 && a<b) //both the conditions must be verified
    printf("c is zero AND a is less than b!!");

  //NOT 
  if(!(c==0))
    printf("c is not zero"); 

  //another way to write the logical expression L1
  if(!(c!=0 && a>=b))
    printf("c is zero, OR a less than b");


  return 0;
}
