#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void convert_sigm(short a, short b,int *ptr_ris);
int main()
{
    int a,b;
    int *w;
    printf("Inserisci un numero(a):\n");
    scanf("%d",&a);
    printf("Inserisci un numero(b):\n");
    scanf("%d",&b);
    printf("\n a=%d  b=%d ",a,b);
    convert_sigm(a,b,w);
}
void convert_sigm(short a, short b,int *ptr_ris){
    int ris=a*b;
    ptr_ris=&ris;
    printf("\nValore: %d   puntatore:%p\n",*ptr_ris,ptr_ris);

}
