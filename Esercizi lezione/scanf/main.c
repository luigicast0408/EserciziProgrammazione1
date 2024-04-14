#include <stdio.h>

int main() {
    int x;
    double y;
    char stringa[6];
    char stringa1[6];
    char c;
    printf("\n inserisci un intero\n un double \ne una stringa\n");
    scanf("%d %lf %s",&x,&y,stringa1);
    printf("\nintero:%d\ndouble:%f\n una stringa:%s\n",x,y,stringa1);
    printf("inserisci un carttere:");
    fflush(stdin); //istruzione per pulire il buffer
    scanf("%c",&c);
    printf("carattere->%c",c);
    printf("insersci la 1° stringa");
    scanf("%s",stringa);
    printf("insersci la 2° stringa");
    scanf("%5s",stringa); //aquisre al piu 5 caratteri




}
