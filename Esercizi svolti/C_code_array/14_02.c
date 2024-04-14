#include <stdio.h>

int main(){
  
    int v[] = {10, 20, 30, 40};  
    int *p = v;

    int *p1, *p2; 
    p1 = v; 
    p2 = v+1; 
    
    printf("\n p1: %p, \n p2: %p", p1, p2);  // confrontare i due indirizzi..
 
    printf("\n(p2-p1): %lu", (p2-p1)); // ?? aritmetica dei puntatori

    printf("\n v=%p, p=%p, \n v[2]=%d, p[2]=%d, \n (v+2)=%p, (p+2)=%p", (void *)v, (void *)p, v[2], p[2],(void *) (v+2) , (void *) (p+2));

    printf("\n (v+sizeof(int))=%p \n (p+1)=%p \n", (int *) ((unsigned long int) v + sizeof(int)), (p+1));
  
}
