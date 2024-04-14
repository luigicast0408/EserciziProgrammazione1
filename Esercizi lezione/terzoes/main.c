#include <stdio.h>

int main() {
   int colonne=2,righe=2,somma=0,M[100][100],k,request=0;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            printf("ins n alla posizione M(%d,%d)",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    }
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            somma=0;
            if(j%2==1)
            {
                somma+=M[i][j];
            }
            if(somma<k) {request++;}
        }
    }

}
