#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define A 10
//#define b 20
void bar(double  *vec[20],unsigned n,unsigned m);

int main() {
    //int x = 10 * INT_MAX;  //1°
    //printf("%d", x);

    //double y=1/0;  //2°
    //printf("%f",y);

    //float y=5.45;
    //int x=(int)y+0.5;
    //printf("x:%d",x);

    unsigned int x = 1;
    while (x++ <= A) {
        printf("%u\n", x);
    }

    srand(time(NULL));
    /*for (unsigned x = 0; x < 10; ++x) {
        printf("%d\n",rand()%(b-a+1)+a);
    }*/
//    int a=rand();
//    int b=rand();
//    printf("a:%d\n",a);
//    printf("b:%d\n",b);
//    printf("%f",1.0*(a/b));
    /*double matrix[2][3] = {
            {1.1, 2.2, 3.3},
            {4.4, 5.5, 6.6}
    };
    bar(matrix,2,3);*/

    //char *s1[]="Msnnsj";
    //char *s2[]={'m'};
    /*char s3[]="MMM";
    printf("s3  %s\n",s3);
    char s4[]={'m'};
    printf(" s4 %s\n",s4);*/

    int *V= malloc(sizeof(int)*10);
    free(V);
    free(V);

}
//void bar(double  *vec[],unsigned n,unsigned m){
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            printf("%f",(*(vec+i)+j));
//        }
//    }
//}


