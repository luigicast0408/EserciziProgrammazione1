#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int convert_sigm(short a, short b);
int main()
{
    int a,b;
    printf("Inserisci un numero(a):\n");
    scanf("%d",&a);
    printf("Inserisci un numero(b):\n");
    scanf("%d",&b);
    printf("\n a=%d  b=%d convert_numer*=%d\n",a,b, convert_sigm(a,b));
}
int convert_sigm(short a, short b){
    return a*b;
}
