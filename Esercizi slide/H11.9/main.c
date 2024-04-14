// kiss my arancia nigga!
// buhbuh milano
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main()
{
    int n_persone;
    char diabetici;
    float farina=0.3,zucchero=0.1;
    int uova=4;


    do {
        printf("\n Quante persone mangeranno il dolce?\n");
        scanf("%d",&n_persone);

        printf("Ci sono diabetici?");
        scanf("%c",&diabetici);
    }while((n_persone<2 && n_persone>16) && (diabetici!='d' && diabetici !='n'));

    if (n_persone>=5 && n_persone<=8) {

        farina *= 2.5;
        zucchero = 1.5;
        uova *= 2.5;

    } else if (n_persone>=9 && n_persone<=16) {
        farina += farina*2.5;
        zucchero += zucchero*1.5;
        uova += uova;
    }

    if (diabetici == 'd') {
        zucchero *= 2/3;
    }

    printf("\nLe dosi per %d persone %s diabetici sono:\n Farina=%f\n Uova=%d\n Zucchero=%f\n",n_persone, diabetici == 'd' : "con" ? "senza",farina,zucchero,uova

}
