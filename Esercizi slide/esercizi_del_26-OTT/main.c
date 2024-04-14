#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {
    // 1)
    float x = 1.0882e7;
    double y = x * 1.23456e100;

    // 2)
    printf("x in notazione scientifica con 6 cifre decimali: %.6e\n", x);
    printf("y in notazione scientifica con 6 cifre decimali: %.6e\n", y);

    // 3)
    float overflowNegativo = -x * FLT_MAX;

    printf("Overflow negativo: %e\n", overflowNegativo);

    // 4)
    double overflowPositivo = y * DBL_MAX;
    printf("Overflow positivo: %e\n", overflowPositivo);

    // 5)
    int a = INT_MAX;
    int b = INT_MAX - 1;
    int sum = a + b;
    long sumLong = (long) a + b;
    printf("Somma int: %d\n", sum);
    printf("Somma long: %ld\n", sumLong);

    // 6)
    printf("Valore minimo di long long: %lld\n", LLONG_MIN);
    printf("Valore massimo di long long: %lld\n", LLONG_MAX);

    // 7)
    printf("Dimensione di long: %ld bytes\n", sizeof(long));
    printf("Dimensione di long long: %ld bytes\n", sizeof(long long));

    //8)
    //a)sin^2(x) + cos^2(y), x e y variabili con valore a piacere
    float ris= pow(sin(1),2.0)+pow(cos(1),2.0);
    printf("\nRisultato %f\n",ris);
    //b)
    float cateto1=12.54,cateto2=12;
    float area=(sqrt(pow(cateto1,2)+pow(cateto2,2)));
    printf("\nArea del tringolo e: %f:\n",area);
    //c
    float raggio;
    float circonferenza=pow(raggio,2)*M_1_PI;
    printf("\nLa circoferenza è %f\n",circonferenza);
    //D
    float operazione=(int)(2*3)/2+(float)(7/4)+8.8;
    printf("\nrisultato operazione %f \n",operazione);

    //F
    float x1=3.2;
    printf("x/0-x/0=%f",(x/0-x/0));
    int e100=e100;
    printf("\ne^100=%e\n",e100);
    int e300=e300;
    printf("\ne^300=%e\n",e300);
    







    return 0;
}
