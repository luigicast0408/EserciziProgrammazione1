#include "stdio.h"

int main()
{
    const int a = 10;
    const int b = 20;
    int N;
    printf("\n inserisci un numero: \n");
    scanf("%d", &N);

    if (N > a) {
        if (N < b) {
            printf("\n Messaggio.....\n");
        }
    }
    if (N > a && N < b) { //max a max b tutte e due verificate
        printf("\n Messaggio.....\n");
    }

    if(N==a || N==b) {
        printf("\n Messaggio.....\n");
    }

    if(!(N!=a)) // è come scrivere if(N==a)//
        // {
    if(p!=NULL)
        if(*p>10)
            //....

    if(p!=NULL && *p>10) //OK

    if( *p>10 && p!=NULL ) //NO perchè prima si controlla se e nullo e poi se è max 10


}