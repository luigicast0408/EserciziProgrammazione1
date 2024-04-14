#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define A 1
/*double *f(){
    double *y=rand()/(RAND_MAX*1.0);
    return y;
}*/

int main()
{
    //f();
 double vec[4]={1.0,2.4,3.4,4.5};
 double *ptr=vec;



   // int *V[10][20] = {};
    //int value = *(*(*(V+2)));
    //ptr[1];  // vec[1]
    //*(ptr+1);*(vec+1);
    //*ptr; *vec;
   //double *pointer=&vec[2];
    //printf("%d",*(++pointer));

    /*int a=INT_MAX*INT_MAX;

    double y;
    //const double *ptr1=&y; //
    //double* const ptr2=&y;
    double z=7.6;
     double const *ptr1=&y; //puntatore  a cost
     double *const ptr2=&y; //puntatore costante
    *ptr1=20;
    ptr1++;

    *ptr2=30.0;
    *ptr2= (&z)+0.1;
    ptr2++;*/
//  char s[]="Pippo123";
//
//    s[2]='x';
//    printf("%s",s);
    //int N=2;
    //int A[2]={};
    //for (int i = 1; i < N; ++i) {
        //printf("%d",A[--i]++);
    //}
    double alpha = 0.5678*123;
    int value=alpha+0.5;
    printf("value:%d",(alpha+0.5));
    printf("value:%d",(alpha+1));
    printf("value:%d",(int)alpha);

    unsigned x=1;
    while(x++<=A)
    {
        printf("%u",x);
    }
 srand(time(NULL));
    int a =rand();
    int a =rand();
}
