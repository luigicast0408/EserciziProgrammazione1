#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){

  int a=30;
  
  switch(a){
    case 30: //if a==30 ...
      printf("\na is 30");
      break;
    case 40://else if(a==40) ... 
      printf("\na is 40");
      break;
    case 50:
      printf("\na is 50!");
      break;
    case 34:
      printf("\na is 34!");
      break;
    case 10:
      printf("\na is 10!");
      break; //without break? 
    case 44:
      printf("\na is 44!");
      break;
    case 90:
      printf("\na is 90!");
    default: //executed if other cases do not hold
      printf("\n a is %d", a); 
  }
  
  int b = 7;
    unsigned short odd = FALSE; 

  switch(b){
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
      odd=TRUE;
      break;
    default: 
      odd=FALSE;
  }

  printf("\nNumber %d is %s\n",b, (odd ? "odd" : "even")); 

  return 0;  
}
