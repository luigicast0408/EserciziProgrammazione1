#include <stdio.h>

struct record{
    char *nome;
    char *cognome;
    int dato; 
}; 

/* Un esempio di definizione e inizializzazione. 
Mostra anche allineamento campi della struttura (dato) 
*/ 

int main(){
    //lista di inizializzatori 
    struct record mytest = {NULL, NULL, 100};
    //accesso ad un attributo 
    mytest.nome = "Mario"; 

    printf("\n sizeof(struct record)=%zd\n ", sizeof(struct record)); 
    printf("\n sizeof(nome)=%zd, address-of(nome)=%p\n ", sizeof(mytest.nome), &mytest.nome);     
    printf("\n sizeof(cognome)=%zd, address-of(cognome)=%p\n ", sizeof(mytest.cognome), &mytest.cognome); 
    printf("\n sizeof(dato)=%zd, address-of(dato)=%p\n ", sizeof(mytest.dato), &mytest.dato); 

    printf("nome: %s, cognome: %s, dato: %d", mytest.nome,  mytest.cognome, mytest.dato); 
    return 0; 
}
