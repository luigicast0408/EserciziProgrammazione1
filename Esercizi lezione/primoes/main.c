#include <stdio.h>


int main() {
    //vettore
    int v[] = {1, 2, 3, 4,5,6,7,8,9};


    int t = 10;
    int k = 2;
    int w = 4;
    int z = v[k];
    int i = k+1;
    int len=0;


    while (i <= k+w){
        if(z <= t) {
            z += v[i];
            len++;
        }
        i++;

    }

    if(z<k+w) { printf("-1");}
    else{ printf("%d",z);}



    //stampo il valore di z
    printf("\n");
    printf("%d", z);

    return 0;
}