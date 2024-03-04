#include <stdio.h>
#include <stdbool.h>

void swap(int *num1, int *num2);
void bubble_sort(int size, int *vector);
void print_vector(int *vector, int size);
void bubble_sort_for(int size, int *vector);

int main() {
    int vector[10] = {1, 3, 1, 5, 6, 9, 20};
    bubble_sort(7, vector);
    print_vector(vector, 7);
    return 0;
}

void swap(int *num1, int *num2) {
    printf("\nNum1->%d  num2:%d\n", *num1, *num2);
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    printf("\nNum1->%d  num2:%d\n", *num1, *num2);
}

void bubble_sort(int size, int *vector) {
    bool swap_bool = true;
    unsigned step=0; //numero di visite  n-1 iterazioni al caso peggiore
    while (swap_bool)
        swap_bool=false;
    for (int i = 0; i < size-1-step; ++i) { //size-1-step  -1 perche l'utimo scabio supererbbe la sze
        if(vector[i]>vector[i+1]){
            swap(&vector[i],&vector[i+1]);
            swap_bool=true;
        }
    }
    step++;

}
//oopure


void print_vector(int *vector, int size) {
    printf("\n_______Vector___\n");
    for (int i = 0; i < size; ++i) {
        printf("V[%d]->%d\n", i, vector[i]);
    }
    printf("\n_______Vector___\n");
}
void bubble_sort_for(int size, int *vector){
    bool swap_bool=true;
    for (int i = 0; i < size-i-1; ++i) {
        if(swap_bool){
            swap_bool=false;
            for (int j = 0; j < size-i-1; ++j) {
                if(vector[i]>vector[i+1]){
                    swap(&vector[i],&vector[i+1]);
                    swap_bool=true;
                }

            }
        }
    }
}
