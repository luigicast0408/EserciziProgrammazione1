#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
   int V[10];
    for (int i = 0; i < 10; i++) {
        V[i]=i;
    }
    int *ptr=V;

    for (int i = 0; i < 10; i++) {
        printf("\n(ptr+%d)=%p\n  &v[%d]=%p,*(ptr+%d)=%d\n",i,ptr+i,i,&(V[i]),*(ptr+i),i,V[i]);
    }
    printf("\n(pre incremento) *pt=%d ptr=%pn",*ptr,ptr);
    ptr++;
    printf("\n(pre incremento) *pt=%d ptr=%pn",*ptr,ptr);

    int num=90;
    int *ptr1=&num;
    ptr1=NULL;
    if(ptr1)
        printf("\n%d\n",*ptr);

    //cost
    int num1=12;
    const int *ptr3;
    ptr=&num1;

    //1
    printf("\n *ptr=%d\n",*ptr);




}
