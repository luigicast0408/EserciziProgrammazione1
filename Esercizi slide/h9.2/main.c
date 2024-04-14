#include <stdio.h>

int main() {
    int a, b, c, k;
    printf("\ninserisci il numero a:\n");
    scanf("%d", &a);
    printf("\ninserisci il numero b:\n");
    scanf("%d", &b);
    printf("\ninserisci il numero c:\n");
    scanf("%d", &c);
    printf("\ninserisci il numero k:\n");
    scanf("%d", &k);

    if (a != c) {
        if (k > 8) {
            b = a + c;
        }
    } else if (a == c) {
        if (k < 8) {
            a = c - b;
        }
    } else{
        printf("media:%d",(a+b+c)/3);
        a=0,b=0,c=0;

    }
}
