#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
 int v[20];
 int a=10,b=20;
    srand(time(NULL));
    for (int i = 0; i < 20; ++i) {
        v[i]=rand()%(b-a+1)+a;
    }

    for (int i = 0; i < 20; ++i) {
        printf("%d\t",v[i]);
    }
}
