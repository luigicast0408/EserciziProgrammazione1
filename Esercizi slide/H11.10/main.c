#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DIM_TUBI_SCELTI 5
#define DIM_TUBI_MAX 15
#define PORTATA_DISPARI 60
#define PORTATA_PARI 120

void inserimentodati(int *portata_tubi, int *tubi_scelti);
int check_tubiscelti(int *tubi_scelti);
int check_minuti();
void stampa_vettore(int *vett, int dim);
void inizializazzione_portatatubi(int *portata_tubi);
int check_input(int dim);
void calcolo_acqua(int *portata_tubi, int *tubiscelti,int minuti_tot,int *q_vascaA,int *q_vascaB,int *q_vascaC);
void stampaQuantitaAcqua(int acqua_A, int acqua_B, int acqua_C);


int main() {
    int portata_tubi[15];
    int tubisclelti[5];
    int minuti_totali;
    int q_vascaA = 0, q_vascaB = 0, q_vascaC = 0;

    inserimentodati(portata_tubi, tubisclelti);
    minuti_totali = check_minuti();
    inizializazzione_portatatubi(portata_tubi);
    calcolo_acqua(portata_tubi, tubisclelti, minuti_totali, &q_vascaA, &q_vascaB, &q_vascaC);
    stampaQuantitaAcqua(q_vascaA, q_vascaB, q_vascaC);


    return 0;
}

void inserimentodati(int *portata_tubi, int *tubi_scelti) {
    int result;
    do {
        for (int i = 0; i < DIM_TUBI_SCELTI; ++i)
        {
            tubi_scelti[i]= check_input(i);
        }
        result = check_tubiscelti(tubi_scelti);
    } while (result !=0);
}

int check_tubiscelti(int *tubi_scelti) {
    for (int i = 0; i < DIM_TUBI_SCELTI; ++i) {
        for (int j = i + 1; j < DIM_TUBI_SCELTI; ++j) {
            if (tubi_scelti[i] == tubi_scelti[j])
                return -1;
        }
    }
    return 0;
}

int check_minuti() {
    int minuti_totali;
    do {
        printf("\nInserisci il numero tatale di minuti: \n");
        scanf("%d", &minuti_totali);
    } while (minuti_totali <= 0);
    return minuti_totali;
}

void inizializazzione_portatatubi(int *portata_tubi) {
    for (int i = 0; i < 15; ++i) {
        portata_tubi[i]= i%2==0 ? PORTATA_PARI : PORTATA_DISPARI; //if(portata_tubi[i]==0 else)
    }
}

void stampa_vettore(int *vett, int dim) {
    printf("\n--------------------------------------------------\n");
    for (int i = 0; i < dim; ++i) {
        printf("\n%d\t", vett[i]);
    }
    printf("\n--------------------------------------------------\n");
}

void calcolo_acqua(int portata_tubi[], int *tubiscelti,int minuti_tot,int *q_vascaA,int *q_vascaB,int *q_vascaC){
    int tubi_A[] = {1, 5, 6, 10};
    int tubi_B[] = {2, 3, 4, 7, 8, 9};
    int tubi_C[] = {11, 12, 13, 14, 15};

    for (int i = 0; i < DIM_TUBI_SCELTI; i++) {
        int tubo_corrente=tubiscelti[i];
        for (int j = 0; j < DIM_TUBI_SCELTI-1; j++) {
            if (tubo_corrente == tubi_A[j])
                *q_vascaA += portata_tubi[tubo_corrente - 1] * minuti_tot;
            else if (tubo_corrente == tubi_B[j])
                *q_vascaB += portata_tubi[tubo_corrente - 1] * minuti_tot;
        }
        for (int j = 0; j < 5; j++) {
            if (tubo_corrente == tubi_C[j])
                *q_vascaC += portata_tubi[tubo_corrente - 1] * minuti_tot;
        }

    }
}

int check_input(int dim) {
    int N;
    do {
        printf("inserisci il %d tubo scelto:", dim+1);
        scanf("%d", &N);
    }while(N<=1 || N>=15);
    return N;
}

void stampaQuantitaAcqua(int acqua_A, int acqua_B, int acqua_C) {
    printf("Quantità d'acqua raccolta:\n");
    printf("Vasca A: %d litri\n", acqua_A);
    printf("Vasca B: %d litri\n", acqua_B);
    printf("Vasca C: %d litri\n", acqua_C);
}
