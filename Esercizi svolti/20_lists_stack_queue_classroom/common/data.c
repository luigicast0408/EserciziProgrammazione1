#include "data.h"
#include <stdio.h>

int confronta_dati(const struct dato *d1, const struct dato *d2){
    if(d1->value==d2->value){
        return 0;
    } else if((*d1).value < (*d2).value){
        return -1;
    } else if((*d1).value > (*d2).value){
        return -1;
    }
}

void printDato(const struct dato *d){
    printf("dat->%d",d->value);
}
