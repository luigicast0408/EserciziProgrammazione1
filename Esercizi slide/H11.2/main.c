#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

int main()
{
  float x,y;
    do {
        printf("\nInserisci un numero (x) minore di 1 \n");
        scanf("%f",&x);

        printf("\nInserisci un numero (y) minore di 1 \n");
        scanf("%f",&y);
  }while(x>1 && y>1);

    do {
        y=y/x;
        printf("\ny=%f\n",y);
    }while(y!=236u);
}
