#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    double num1=2.21;
    unsigned short num2=1;
    char carattere='c';
    double *num1_p=&num1;
    unsigned short *num2_p=&num2;
    char *carattere_p=&carattere;
    printf("\nnumero1=%f(double)\n",num1);
    printf("\nnumero1=%p(puntatore)\n",num1_p);
    printf("\nnumero2=%d(unsigned short)\n",num2);
    printf("\nnumero2=%p(puntatore)\n",num2_p);
    printf("\ncarattere=%c (carettere)\n",carattere);
    printf("\ncarattere=%p (puntatore)\n",carattere_p);


}
