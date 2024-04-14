#include <stdio.h>

int main(){
  
  int a, b;

  int *p1=&a, *p2=&b;

  printf("\n p1 is %s from p2", (p1==p2 ? " not different " : " different "));

  p1 = &b;

  printf("\n p1 is %s ", (p1==p2 ? " not different " : " different "));
}
