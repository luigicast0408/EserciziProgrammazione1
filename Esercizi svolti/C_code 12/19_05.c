#include <stdio.h>

//Essi sono interi 
enum Mese{
  Gennaio, // 0
// Gennaio =20, // eventualmente quali saranno gli altri valori? 
  Febbraio,  //1
  Marzo, //2 
  Aprile, //..
  Maggio,
  Giugno, 
  Luglio, 
  Agosto, 
  Settembre, 
  Ottobre, 
  Novembre, 
  Dicembre  // 11
};

enum Settimana{
    lunedi,
    martedi, 
    //..
    domenica
}; 


/* NB: I nomi definiti  vengono ``esportati'' nello scope
della enum. 
*/ 

const char * traduci_mese(enum Mese m){
  switch(m){
    case Gennaio:
      return "Gennaio"; 
      break; 

    case Febbraio:
      return "Febbraio"; 
      break; 
    //case 3: 
      //...

    case Dicembre:
      return "Dicembre";
      break; 

    default: 
      return "undefined";
      break; 
  }
}

int main(){
  enum Mese m1 = Agosto; // OK 
  //anche 
  m1 = Agosto; 

    printf("\nGennaio=%d, Febbraio=%d", Gennaio, Febbraio); 

    printf("\nAprile=%d, Maggio=%d", Aprile, Maggio); 

  //int --> enum
  enum Mese m2 =  11; // Dicembre
  //m2 = 11; // Dicembre
  printf("\n m2=%s", traduci_mese(m2)); 
  //Ok, una enum e' un intero..MA non ci sara' alcuna corrispondenza
  // tra il 19 e i nomi definiti..
  enum Mese m3 = (enum Mese) 19; // Ok ma non corrrisponde ad alcun valore..
  printf("\n\n m3=%s", traduci_mese(m3)); // undefined! 

  m3 = 10; // ok 
  int x = m3;  // enum --> int OK 
  printf("\n x= %s",  traduci_mese(x)); 

  //char *Agosto ="Agosto"; // Attenzione! variabile Agosto ``oscura'' Agosto di Mese..

  //m3 = Agosto; // FM errore di compilazione! char * vs enum Mese ..
  printf("\n m3: %d, Agosto=", m3); 

  //stampa interi..
  printf("\n\n m1=%d m2=%d m3=%d",m1, m2, m3);
  //la dimensione di un intero
  printf("\n\n sizeof(enum Mese)=%zd, sizeof(int)=%zd", sizeof(m1), sizeof(int)); 

  enum Settimana giorno = Gennaio; // nessun warning, MA e' un errore! 

}
