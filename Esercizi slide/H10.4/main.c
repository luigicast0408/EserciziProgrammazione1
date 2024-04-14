#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define  MAX_N 99

int main()
{
    unsigned int somma=0;
    printf("\n___________________Numeri  dispari_______________\n");
    for (short i = 1; i <= MAX_N; i++) {
        if(i%2 !=0 && i%3!=0){
            printf("\n  %d\t",i);
            somma+=i;
        }
    }
    printf("\nla somma e' %d\n ",somma);
}
