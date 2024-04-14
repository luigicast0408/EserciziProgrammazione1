#include "stdio.h"
int  main()
{
    const double  TARGET=1800;
    const double  TASSO_INTERESSE=0.1;
    const int N=10;
    int anno=0;
    double  capitale=1000.0;

    while (capitale>=TARGET && anno<N)
    {
        capitale+=capitale*TASSO_INTERESSE;
        anno++;
    }
    printf("Capitale %f dopo %d anni",capitale,anno);

}