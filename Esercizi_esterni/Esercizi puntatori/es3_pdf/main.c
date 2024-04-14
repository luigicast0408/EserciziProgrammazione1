#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void scambia( int *p, int *q );
int main()
{
    int p=2,q=4;
    scambia(&p,&q);
}
void scambia( int *p, int *q ){
    int temp = *p;
    *p = *q;   // ora a = b
    *q = temp;


    printf("\n P:%d\n",*p);
    printf("\n Q:%d\n",*q);

    printf("\n Q:%d\n",*q);
    printf("\n P:%d\n",*p);
}