#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void inserction_sort(int *vector, int size);

int main() {

}
void inserction_sort(int *vector, int size){
    for (int i = 1; i < size; ++i) {
        //inserimento dell'elemento vector[i]
        //nell' sotto-array ordinato
        int key=vector[i];
        int j=i-1;
        while (j>=0 && key<vector[j]){
            vector[j+1]=vector[j];
            j--;
        }
        vector[j+1]=key;
    }

}

void print_vector(int *vector, int size) {
    printf("\n_______Vector___\n");
    for (int i = 0; i < size; ++i) {
        printf("V[%d]->%d\n", i, vector[i]);
    }
    printf("\n_______Vector___\n");
}
