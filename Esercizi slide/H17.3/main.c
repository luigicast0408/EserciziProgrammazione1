#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    char nome[20], cognome[20];
    printf("\nInserisci il tuo nome: \n");
    scanf("%19s", nome);  // Limit input length to avoid buffer overflow

    printf("\nInserisci il tuo cognome: \n");
    scanf("%19s", cognome);  // Limit input length to avoid buffer overflow

    char nome_cognome[40];
    strcpy(nome_cognome, nome);  // Copy the content of nome to nome_cognome

    // Concatenate semicolon and cognome to nome_cognome
    strcat(nome_cognome, ";");
    strcat(nome_cognome, cognome);

    printf("\nNome: %s  Cognome: %s  Nome e cognome: %s\n", nome, cognome, nome_cognome);

    return 0;
}
