#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    int v[10]={};
    int v1[10];
    int N=2;
    int v2[N];

    for (int i = 0; i < 3; ++i) {
        printf("\nInserisci il %d numero\n",i+1);
        scanf("%d",&v1[i]);
    }
    for (int i = 0; i < 3; ++i) {
        printf("\n%d\t",v1[i]);
    }




}
