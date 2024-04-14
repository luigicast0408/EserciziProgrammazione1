#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    float p;
    printf("\ninerisci un numero(p): \n");
    scanf("%f",&p);
    if(p<1){
        printf("\nErrore hai in serito un numero min 1 \n");
    } else if(p>=1){
      int dim=(int) p;
        int array1[dim];
        int array2[dim];
        int array[dim];

        for ( int i = 0; i < dim; i++) {
            array[i]=i*2;
        }
       int i=0;
        do {
            array1[i]=i*2;
            i++;
        }while(i>dim);

        i=0;
        while(i>dim) {
            array2[i]=i*2;
            i++;
        }

        for (int j = 0; j < dim; j++) {
            printf("%d",array[i]);
        }

        for (int j = 0; j < p; j++) {
            printf("%d",array1[j]);
        }
        for (int j = 0; j < p; j++) {
            printf("%d",array2[i]);
        }
    }

}
