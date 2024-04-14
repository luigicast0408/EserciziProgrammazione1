#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    int a,b;
    do {
        printf("\nInserisci il primo numero\n");
        scanf("%d",&a);
        fflush(stdin);
        printf("\nInserisci il primo numero\n");
        scanf("%d",&b);
    }while(a<0 && b<0);

    printf("\n La somma e' %.4d\n",a+b);
    float media=(a+b)/2;
    printf("\nLa media e' %.4e\n",media);

    int max=0;
    if(a>b){
        max=a;
        printf("\n Il max e';%d\n",a);
    }
    else{
        max=b;
        printf("\n Il max e';%d\n",b);
    }




}
