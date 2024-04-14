#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main() {
    char nome[20], cognome[20];
    bool trovato=false;
    do {
        printf("\nInserisci il nome: \n");
        scanf("%s", nome);
        printf("\nInserisci il cognome: \n");
        scanf("%s", cognome);
    } while(strlen(nome) < 0 && strlen(cognome) < 0);

    int i=0;
    while(nome[i]!='\0')
    {
        i++;
    }

    //richiesta 1
    printf("1° carettere %c\n", nome[0]);
    printf("ultimo carettere %c\n", nome[strlen(nome)-1]);

    printf("2° carettere %c\n", nome[1]);
    printf("3° carattere %c\n", nome[strlen(nome)-1]);

    int i;
    char nomeecognome[100];
    for (i = 0; i < strlen(nome); i++) {
        nomeecognome[i] = nome[i];
    }
    int x = 0,j;
    for (j = i; j < strlen(cognome) + i; j++) {
        nomeecognome[j] = cognome[x++];
    }
    nomeecognome[j] = '\0'; // Aggiungi il terminatore di stringa
    printf("\nil nome e' %s, il cognome e' %s la concatenazione e' %s\n", nome, cognome, nomeecognome);

    i=0;
    char caratteri_comuni[10];
    for (int k = 0; k < strlen(nome); k++) {
        for (int l = 0; l < strlen(cognome) ; l++) {
            if(nome[k]==cognome[l]){
                caratteri_comuni[i]=nome[k];
                i++;
            }
        }
    }
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < i; l++) {
            if ( (k!=l) && (caratteri_comuni[k] == caratteri_comuni[l])) {
                caratteri_comuni[k] = '0';
            }
        }
    }

    for (int k = 0; k < strlen(caratteri_comuni); k++) {
        if(caratteri_comuni[k]!='0'){
            printf("\t%c",caratteri_comuni[k]);
        }
    }



    for (i = 0; cognome[i] != '\0'; i++) {
        cognome[i] = tolower(cognome[i]);
    }
    if(nome[0]==cognome[strlen(cognome)-1])
        printf("\nla prima lettera del nome `e uguale all’ultima lettera del cognome.\n");

    if(strlen(nome)!= strlen(cognome))
        printf("\nil numero di caratteri del nome `e uguale al numero di caratteri del cognome\n");


    char  vocali[]={'a','e','i','o','u'};
    int cont=0;
        for (int k = 0; k < strlen(nome); ++k) {
            for (int l = k+1; l < 5; ++l) {
                if(nome[k]==vocali[j]){
                    cont++;
                }
            }
        }
    printf("\n Le consonati nel nome %s sono %d\n",nome,(strlen(nome))-cont);

        cont=0;
        for (int k = 0; k < strlen(cognome); ++k) {
            for (int l = 0; l < 5; ++l) {
                if(cognome[k]==vocali[j]){
                    cont++;
                }
            }
        }
    printf("\n Le consonati nel cognome %s sono %d\n",cognome,(strlen(cognome))-cont);


}
