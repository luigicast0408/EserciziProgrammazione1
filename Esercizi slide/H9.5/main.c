#include "stdio.h"
#define  B_CASTAgno 0.018
#define  B_PINO 0.022
#define  P_CASTANO 0.02
#define  P_PINO 0.022


int main()
{
    char ambiente;
    float carico_massivo,lunghezza_ripiano,Q;
    double spessore;
    printf("\n -----------Falegnameria Castano-------------------------\n");
    printf("\nDove vuoi sistemare lo scaffale? \n");
        scanf("%c",&ambiente);

    printf("\n inserisci la lunghezza del ripiano\n");
        scanf("%f",&lunghezza_ripiano);

    printf("\n inserisci il carico massivo\n");
        scanf("%f",&carico_massivo);


    if(ambiente=='e') {
        printf("\n Per questo scaffale sto utilindo legno di castano\n");
        if(carico_massivo>100)
            Q=1.1;
        else Q=1.0;
        spessore= ((B_CASTAgno + lunghezza_ripiano - 1) * P_CASTANO) * Q;
        printf("La tavola di castagno di Lunghezza %f  che deve supportare al massimo %f KG deve essere di spessore %f",lunghezza_ripiano,carico_massivo,spessore);

    }
    else {
        printf("\n Per questo scaffale sto utilindo legno di pino\n");printf("\n Per questo scaffale sto utilindo legno di castano\n");
        if(carico_massivo>80)
            Q=1.2;
        else Q=1.0;
       spessore=((B_PINO+lunghezza_ripiano-1)*P_PINO)*Q;
        printf("La tavola di  pino  di Lunghezza %f  che deve supportare al massimo %f KG deve essere di spessore %f",lunghezza_ripiano,carico_massivo,spessore);
    }




}