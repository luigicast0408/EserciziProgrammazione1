#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main()
{
    printf("\n______________________CLICLO FOR________________________\n ");
    for (char i = 'a'; i <='z' ; ++i) {
        if(i!='a' && i!='e' && i!='i' && i!='o' && i!='u')
            printf("%c\t",i);
    }
    printf("\n______________________CLICLO WHILE_______________________\n ");
    char i='a';
    while(i<='z') {
        if(i!='a' && i!='e' && i!='i' && i!='o' && i!='u')
            printf("%c\t",i);
        i++;
    }
}
