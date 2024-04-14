#include <stdio.h>

#include <time.h>
#include <stdlib.h>


struct my_struct{
  int a; int b;
  float *ptr;
};

int main()
{
  struct my_struct s1;
  struct my_struct *s2 = &s1;
  
  s1.a = 20;
  s2->b= 10;

  //* e' operatore di "indirezione"
  //-> e' operatore di accesso mediante puntatore

  s1.ptr = (float *) malloc(sizeof(float));
  
  *s1.ptr= 20.2; // 
  printf("\n*s1.ptr: %f ", *s1.ptr);
  
  *(s2->ptr)=10.5;  //A s2->ptr e' come (*s2).ptr ma piu' semplice da leggere
  printf("\n*s2.ptr: %f", *s1.ptr);

  *(*s2).ptr=10.5;   // equivalente ad A
  printf("\n*(*s2).ptr: %f \n", *(*s2).ptr);

}

