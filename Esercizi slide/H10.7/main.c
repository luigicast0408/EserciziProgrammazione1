#include "stdio.h"
#include "string.h"

int main()
{
    char  caratteri[25];
    int j=0;
    for (char i = 'a'; i <='z' ; ++i) {
        if(i!='a' && i!='e' && i!='i' && i!='o' && i!='u')
            caratteri[j++]=i;
    }
    int len_carrattei= strlen(caratteri);
    printf("la lunghezza del vettore di caretteri e' %d",len_carrattei);

}
