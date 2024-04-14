#include <stdio.h>

#define COLUMNS 4
#define ROWS 3

//const int R = 3; 

/* Per un array bidimensionale con allocazione 
  automatica o statica  valgono 
  considerazioni simili: 
  Le celle dello array costituiscono un unico 
  blocco di memoria di dimensioni 
  ROWSxCOLUMNSxsizeof(TIPO). 
*/ 
void showAddr2(int  v[][COLUMNS], int n){
//void showAddr2(int (*v)[COLUMNS], int n ) 
//voi showAddr2(int *v[COLUMNS], int n) // NO!!

  printf("\n showAddr2(v), ovvero verificare che le celle sono contigue..");
  int *prev = NULL; 
   for(int i=0; i<n; i++) //righe
    for(int j=0; j<COLUMNS; j++){ //colonne
      //indirizzo del singolo elemento 
      printf("\n Address-of(v[%d][%d])=%p", i, j, &(v[i][j]));
      //aritmetica dei puntatori 
      if(&v[i][j] == prev+1)
	printf("\n == Address-of(v[%d][%d])+1 (pointer arithmetic)", (j-1 < 0 ? i-1 : i),  (j-1 < 0 ? COLUMNS -1 : j-1)); 
      else 
	printf("\n"); 
      prev = (int *) &(v[i][j]);
    }
}

void g(int v[][COLUMNS], int n){
   printf("\n"); 
  //v e'  un puntatore ad un vettore di COLUMNS element
  printf("\n** Attenzione: v e *v..! ");
  printf("\n v: %p, *v: %p, ovvero &v[0][0]: %p",v, *v, &v[0][0]);

  int *ptr = &v[0][0];
  printf("\n \n Poniamo ptr = &v[0][0] --> ptr=%p", ptr);

  /* L'espressione (v+i) rappresenta il puntatore 
  * all'elemento di indice (i*COLUMNS, 0), in altre parole v[i][0]
  */
  printf("\n (ptr+2*COLUMNS) == (v+2) ? %s", (((ptr + 2*COLUMNS) == (int*) (v+2)) ? "true" : "false")); 

  /* L'espressione (*(v+i) + j) rappresenta il puntatore 
  * all'elemento di indice (i,k), in altre parole v[i][k]
  */
  int i=1, j=2;
  printf("(*(v+%d) + %d): %p", i, j, (*(v+i)+j));
  printf("\n oppure:");
  printf("\n(v[%d] + %d): %p", i, j, (v[i]+j));
  printf("\n ovvero: ");
  printf("\n &v[%d][%d]: %p", i, j, &v[i][j]);

  printf("\n\n Ricordando che ptr = &v[0][0]..");
  printf("\n (ptr+2*COLUMNS + 1) == (*(v+2) + 1) ? %s", ( ( (ptr + 2*COLUMNS + 1) == (int*) (*(v+2) + 1)) ? "true" : "false"));

  //dereferenziando il puntatore si ha accesso al valore 
  printf("\n \n Dereferenziando (accesso all'elemento v[1][2]): "); 
  printf("\n *(*(v+%d) + %d): %d", i, j,*(*(v+i)+j));
  printf("\n oppure: ");
  printf("\n *(v[%d] + %d): %d", i, j, *(v[i]+j));
  printf("\n ovvero: ");
  printf("\n v[%d][%d]=%d \n", i, j, v[i][j]);
}

int main(){

   printf("\n main(): Array di %dx%d elementi", ROWS, COLUMNS);

  int v[ROWS][COLUMNS] = {/* 1st row */ {1,2,3,4}, /*2nd row*/ {5,6,7,8}, /*3th row*/{9,10,11,12}};  // 3 x 4

  showAddr2(v, ROWS);

  g(v, ROWS);
}
