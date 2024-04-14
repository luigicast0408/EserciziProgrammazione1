#include <stdio.h>

int main(){
  
  int num = 10; 
  int *p = &num;
  
  int *v = NULL;

//  *v = 1000;

  printf("\nsizeof(int *): %lu", sizeof(int*));

  printf("\np=%p, &num=%p, *p=%d", (void *) p, &num, *p);

  *p = 35;

  printf("\n *p=35 --> p=%p, &num=%p, *p=%d", (void *) p, &num, *p);
  v=p;
  *v = 20;

  printf("\nv=p, *v=20 --> v=%p, p=%p, *p=%d, *v=%d\n", (void *)  v, (void *)p, *v, *p);  
}
