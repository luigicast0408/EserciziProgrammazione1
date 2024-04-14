#include <stdio.h>

//prototipo della funzione, 
//di norma si scrive in un file header
void swap(int*, int*);

int main()
{
 int x=5, y=10;
 printf("\n Before swap: x=%d, y=%d", x, y);

 swap(&x,&y); // &x and &y are the addresses of variables x and y

 printf("\n After swap: x=%d, y=%d", x, y);
   printf("\n");
 return 0;
}

void swap(int* x, int* y)
{  
  int temp;	
  temp = *x;
  *x = *y;
  *y = temp;
}
