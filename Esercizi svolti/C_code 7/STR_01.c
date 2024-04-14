#include <stdio.h>
#include <string.h> 

int main(){
  
  //p "punta" all'area di memoria (read-only) in cui viene memorizzato 
  //un array di caratteri di lunghezza 5 ('test' + '\0') 
  const char *p = "test"; //OK. String literal

  //un letterale e' un array di caratteri
  //infatti sizeof() ne stampa la dimenzione in bytes 7 + 1 
  //ultimo carattere e' carattere 'null' ('\0')
  printf("sizeof(\"Hi all!\"): %zd", sizeof("Hi all!"));

  // stampa la dimensione, in bytes, del puntatore
  printf("sizeof(p): %zd", sizeof(p)); 

  // stampa la dimensione, in byte, occupata da un char, ovvero p[0].
  printf("sizeof(*p): %zd", sizeof(*p)); 
  printf("p[3]: %c", p[3]);

  //Deprecated. Not safe. Indeed, memory of literal "test1" is read-only. 
  //p1[2] = 'c' will result in ``undefined behaviour''. 
  char *p1 = "test1"; 
  
  //OK. array di caratteri per una stringa di 19 caratteri
  char p2[20]; 
  p2[4] = 'k';// OK ma...
  printf("p2: %s ",  p2); 
  
  //allocazione (dichiarazione array) + inizializzazione
  char p3[20] = "Hello all!"; //OK, verra' inizializzato con un '\0' alla fine
  printf("p3: %s", p3); 
  //oppure..
  char p33[] = "Hello all!"; // avra' lunghezza appropriata (11)

  //questo non va molto bene
  char name[] = {'p', 'i', 'p', 'p', 'o'}; //manca lo 0, alcune funzioni potrebbero non funz. corr. 
  printf("name: %s, strlen(name): %zd", name, strlen(name));

  //questo e' OK
  char name1[] = {'p', 'i', 'p', 'p', 'o', '\0'};
  printf("name1: %s", name1);
  
}
