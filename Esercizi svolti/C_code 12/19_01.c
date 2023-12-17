#include <stdio.h>
#include <stdlib.h>

struct record{
    char *nome;
    char *cognome;
    int dato; 
    char k; 
};

struct data{
    int dato; 
    char carattere; 
}; 

/* Un esempio di definizione e inizializzazione. 
Mostra anche allineamento campi della struttura: vedi dato e next
*/ 

int main(){
    //lista di inizializzatori 
    struct record r1 = {NULL, NULL, 100, 'x'};
    //accesso ad un attributo 
    r1.nome = "Mario"; 
    r1.cognome= "Rossi";
    r1.dato= rand()%101;    
    printf("nome: %s, cognome: %s, dato: %d", r1.nome,  r1.cognome, r1.dato); 


    struct record r2 = {NULL, NULL, 100, 'x'};

    r2.nome = "Tizio"; 
    r2.cognome= "Bianchi";
    r2.dato= rand()%101;    
    printf("nome: %s, cognome: %s, dato: %d, k: %c", r2.nome,  r2.cognome, r2.dato, r2.k); 
  
    struct data d1 = {10, 'x'};
  
    struct data d2 = {10, 'x'};  
    
//    printf("d1==d2 ?? %d", d1==d2); // Errore del compilatore!!  

    return 0; 
}
