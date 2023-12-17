#include <stdio.h>
#include <stdlib.h>

struct record{
    char *nome;
    char *cognome;
    int dato; 
    struct record *next; 
    void (*print_record) (struct record *ptr);
}; 


void print_function (struct record *ptr){
    printf("\n Noinativo: %s %s, dato: %d", ptr->nome, ptr->cognome, ptr->dato);
}

/* Un esempio di definizione e inizializzazione. 
Mostra anche allineamento campi della struttura: vedi dato e next
*/ 

int main(){
    //lista di inizializzatori 
    struct record mytest = {NULL, NULL, 100, NULL};
    //accesso ad un attributo 
    mytest.nome = "Mario"; 
    mytest.cognome= "Rossi";

    mytest.dato= rand()%101;

    mytest.next = (struct record *) malloc(sizeof(struct record)); 

    mytest.next->nome = "Aldo";
    mytest.next->cognome = "Rossi";
    mytest.next->dato = rand()%101;

    mytest.print_record = print_function; 
    
    printf("\n nome: %s, cognome: %s, dato: %d", mytest.nome,  mytest.cognome, mytest.dato); 
    printf("\n (next) nome: %s, cognome: %s, dato: %d", mytest.next->nome,  mytest.next->cognome, mytest.next->dato); 

    printf("\nInvocazione della funzione puntata all'interno della struttura..");
    mytest.print_record(& mytest); 
    
    return 0; 
}
