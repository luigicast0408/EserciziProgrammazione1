#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char ***matrix3size(int *n, int *m, int *k);
void print_matrix3size(char ***matrix3size, int *n, int *m, int *k);
bool palidrome(int *v, int size);
bool check_palidrome_tot(char ***matrix3size, int *n, int *m, int *k);
bool check_palidrome_row(char ***matrix3size, int *n, int *m, int *k);
bool check_palidrome_col(char ***matrix3size, int *n, int *m, int *k);
void print_vector(int *vet, int size);

int main() {
    int n, m, k;
    printf("\nInserisci n\n");
    scanf("%d", &n);

    printf("\nInserisci m\n");
    scanf("%d", &m);

    printf("\nInserisci k\n");
    scanf("%d", &k);

    char ***matrix_3 = matrix3size(&n, &m, &k);
    print_matrix3size(matrix_3, &n, &m, &k);

    check_palidrome_tot(matrix_3,&n,&m,&k);

    // Deallocazione della memoria
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            free(matrix_3[i][j]);
        }
        free(matrix_3[i]);
    }
    free(matrix_3);

    return 0;
}

char ***matrix3size(int *n, int *m, int *k) {
    char ***matrix3size = malloc(sizeof(char **) * (*n));

    for (int i = 0; i < *n; ++i) {
        *(matrix3size + i) = malloc(sizeof(char *) * (*m));
        for (int j = 0; j < *m; ++j) {
            *(*(matrix3size + i) + j) = malloc(sizeof(char) * (*k));
        }
    }

    srand(time(NULL));
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            for (int l = 0; l < *k; ++l) {
                *(*(*(matrix3size + i) + j) + l) = (char)('a' + (rand() % 26));
            }
        }
    }

    return matrix3size;
}

void print_matrix3size(char ***matrix3size, int *n, int *m, int *k) {
    for (int i = 0; i < *n; ++i) {
        printf("\n");
        for (int j = 0; j < *m; ++j) {
            printf("\n");
            for (int l = 0; l < *k; ++l) {
                printf("%c\t", *(*(*(matrix3size + i) + j) + l));
            }
        }
    }
}

bool palidrome(int *v, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(v[i]!=v[j]){return false;}

        }
    }
    return true;
}

bool check_palidrome_tot(char ***matrix3size, int *n, int *m, int *k){
 if(check_palidrome_row(matrix3size,&n,&m,&k)==true){
     printf()
     return true;
 } else{
     printf("msmms");
 }
    return false;
}

bool check_palidrome_row(char ***matrix3size, int *n, int *m, int *k){
    char *temp_row= malloc(sizeof(char)*(*n));
    int count_a=0,c=0;
    bool *value= malloc(sizeof (bool)*count_a);

    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            *(*(*(matrix3size+i)+j))=temp_row[c];
            c++;
        }
        c=0;
        if(palidrome(temp_row,c)){
            *(value+count_a)=true;
            count_a++;
        }
    }

    c=0;
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            *(*(*(matrix3size+i)+j))=temp_row[c];
            c++;
        }
        c=0;
    }
    if (palidrome(temp_row,c)){
        *(value+count_a)=true;
        count_a++;
    }
    return  count_a>0 ? true : false;
}

void print_vector(int *vet, int size) {
    printf("\n_____________Vettore__________\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t", *(vet+i));
    }
    printf("\n_____________Vettore__________\n");
}