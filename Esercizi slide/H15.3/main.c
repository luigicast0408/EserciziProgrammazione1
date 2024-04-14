#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int str_len(char str[]);
int main()
{
    char str[20];
    printf("\nInserisci una stringa: \n");
    fflush(stdin);
    scanf("%s",str);
    printf("\nLa stringa %s ha %d caretteri\n",str, str_len(str));
}
int str_len(char str[]){
    int i=0;
    while(str[i]!='\0') {
        i++;
    }
    return i;
}