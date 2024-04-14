#include <stdio.h>
#include <stdlib.h>

// NB: attenzione all'ordine dei parametri formali 
// (m deve comparire prima)
void stampa(size_t m, int A[][m], size_t n){
    for(size_t i=0; i<n; i++){
	for(size_t j=0; j<m; j++)
	    printf("\n A[%zd][%zd] = %d", i, j,   A[i][j]);
	printf("\n");
    }
}

int main(){

    size_t n = 10;
    size_t m = 15;

    int A[n][m]; // VLA (Variable Length Array)

    for(size_t i=0; i<n; i++){
	for(size_t j=0; j<m; j++)
	    A[i][j] = rand()%(51) + 10; 
    }

    stampa(m, A, n); 

}
