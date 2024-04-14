#include <stdio.h>

#define SCONTO_A 0.10

#define SCONTO_B1 0.20
#define SCONTO_B21 0.15
#define SCONTO_B22 0.18

#define SCONTO_C 0.30

#define SOGLIA_A 100
#define SOGLIA_B 1000

#define YES 'Y'
#define NO 'N'

#define FALSE 0
#define TRUE 1


/* Scrivere un programma che prenda i seguenti input da tastiera: 
  i) l'importo di un ordine, 
  ii) un ulteriore dato in input che indica se uno o piu' articoli hanno un prezzo promozionale, 
  iii)  un dato finale in input che indica se l'ordinante ha una tessera cliente.

  Il programma dovra stampare l'importo totale dell'ordine aggiornato in base 
  alle seguenti specifiche: 

  a) Se l'importo dell'ordine e' minore o uguale a 100 euro, applica uno sconto del 10%. 
  b) Se l'importo dell'ordine e' maggiore di 100 euro e comunque minore o uguale di 1000 euro, allora: 
    - se l'utente possiede la tessera applica uno sconto del 20%
    - nel caso in cui l'utente non possiede la tessera:
      - se ad uno o piu' articoli e' stato applicato un prezzo 	promozionale, applica uno sconto del 15 %;  
      - altrimenti applica uno sconto del 18%; 
  c) Se l'importo dell'ordine e' maggiore di 1000 euro, applica uno sconto del 30% alla differenza 
  tra l'importo totale dell'ordine e 1000 euro. Applica la scontistica prevista al punto b sui rimanenti 1000 euro. 
*/

void flush_stdin() {
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

int main() {

    double totale_ordine = 0;
    double eccesso_B = -1;
    unsigned short tessera = FALSE;
    unsigned short articoli_in_promozione = FALSE;
    char risposta;

    printf("\n Inserire totale ordine: ");
    scanf("%lf", &totale_ordine); // lf  == long double

    flush_stdin();

    printf("\nArticoli in promozione (Y/N)? ");
    scanf("%1c", &risposta); // 1c == 1 carattere

    flush_stdin();

    if (risposta != YES)
        articoli_in_promozione = FALSE;
    else articoli_in_promozione = TRUE;

    printf("\nSi possiede la tessera (Y/N)? ");
    scanf("%1c", &risposta);

    flush_stdin();

    if (risposta != YES)
        tessera = FALSE;
    else
        tessera = TRUE;

    printf("\nTotale ordine: %.2lf", totale_ordine);
    printf("\n%s articoli in promozione", (articoli_in_promozione ? "Ci sono" : "Non ci sono"));
    printf("\n Il cliente %s la tessera", (tessera ? " possiede " : " non possiede "));

    if (totale_ordine <= SOGLIA_A) {
        totale_ordine = totale_ordine * (1 - SCONTO_A);
    } else { //casi B e C
        eccesso_B = totale_ordine - SOGLIA_B;
        totale_ordine = (totale_ordine >= SOGLIA_B ? SOGLIA_B : totale_ordine);

        if (tessera)
            totale_ordine = totale_ordine * (1.0 - SCONTO_B1);
        else if (articoli_in_promozione)
            totale_ordine = totale_ordine * (1.0 - SCONTO_B21);
        else
            totale_ordine = totale_ordine * (1.0 - SCONTO_B22);

        if (eccesso_B > 0)
            totale_ordine += eccesso_B * (1 - SCONTO_C);

    }

    printf("\n \n Totale ordine aggiornato: %lf \n\n", totale_ordine);

}
