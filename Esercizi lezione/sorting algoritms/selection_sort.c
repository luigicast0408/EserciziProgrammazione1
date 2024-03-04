#include <stdio.h>
int min(int *vector, int size, int index);
void selection_sort(int *vector, int size);
void print_vector(int *vector, int size);

int main(){
int vector[8]={1,2,7,1,8,0,23,11};
int size=8;
    print_vector(vector,size);
    selection_sort(vector,size);
    print_vector(vector,size);

}
int min(int *vector, int size, int index){
    int min=vector[0];
    for (int i = index; i < size; ++i) {
        if(vector[i]>min){
            min=vector[i];
            printf("\nmin->%d\n",min);
        }
    }
    return min;
}

void selection_sort(int *vector, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            int min_m=min(vector,size,i);
            if(vector[j]<min_m){
                int number=vector[i];
                vector[i]=min_m;
                vector[j]=number;
            }
        }
    }
}
void print_vector(int *vector, int size) {
    printf("\n_______Vector___\n");
    for (int i = 0; i < size; ++i) {
        printf("V[%d]->%d\n", i, vector[i]);
    }
    printf("\n_______Vector___\n");
}
