#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char *maiuscolo(char *stringa);
int main()
{
    printf("\nLunghezza della stringa:\n");
    int len= scanf("%d",&len);

    char *stringa= malloc(sizeof (char )*len);

    printf("Insrisci la stringa che vuoi allocare");
    scanf("%s",stringa);

    char *stringa_toupper= maiuscolo(stringa);
    printf("la strinaga e':%s",stringa_toupper);



}
char *maiuscolo(char *stringa){
    char *string_toupper= malloc(sizeof (char )*strlen(stringa));
    for (int i = 0; i < strlen(stringa); ++i) {
        printf("\ntoupper((int)stringa[i])->%c\n",stringa[i]);
        *(string_toupper+i)= toupper((int)stringa[i]);
    }
    return string_toupper;
}