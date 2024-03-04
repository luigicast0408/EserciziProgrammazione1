#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// TODO: da finire
typedef struct input{
    char *name_file;
    int row;
    int cols;
}input;

bool read_input(input in,int argc,char *argv[]);
bool check_input(int rows,int cols);
double ***allocate_matrix(input in);
void fill_matrix(input in,double ***matrix);
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);
void print_matrix(input in,double ***matrix);
void sort_column(double* column, int N);
void sort_matrixCols(double** matrix, int N, int M);
void extractColumn(double** matrix, double* column, int N, int col);
void normalize_matrix(double ***matrix,int rows, int cols);


int main(int argc, char *argv[]) {
    input in;

    // Leggi l'input e verifica che sia valido
    if (!read_input(in, argc, argv)) {
        fprintf(stderr, "Errore nella lettura dell'input.\n");
        return EXIT_FAILURE;
    }

    // Alloca la matrice
    double ***matrix = allocate_matrix(in);
    if (matrix == NULL) {
        fprintf(stderr, "Errore nell'allocazione della matrice.\n");
        return EXIT_FAILURE;
    }

    // Riempie la matrice con i dati dal file
    fill_matrix(in, matrix);

    // Stampa la matrice
    printf("Matrice Originale:\n");
    print_matrix(in, matrix);

    // Normalizza la matrice se necessario
    normalize_matrix(matrix, in.row, in.cols);

    // Stampa la matrice normalizzata
    printf("Matrice Normalizzata:\n");
    print_matrix(in, matrix);

    // Ordina le colonne della matrice
    sort_matrixCols(matrix, in.row, in.cols);

    // Stampa la matrice con le colonne ordinate
    printf("Matrice con Colonne Ordinate:\n");
    print_matrix(in, matrix);

}


bool read_input(input in,int argc,char *argv[]){
    if (argc<4){
        fprintf(stderr,"Il numero di parametri della funzione main() e' incoretto");
        return false;
    }
    in.name_file=argv[1];
    in.row=*argv[2];
    in.cols=*argv[3];
    return check_input(in.row,in.cols);
}

bool check_input(int rows,int cols){
    if (rows>=5 && rows<=10){
        printf("\nIl parametro (rows) rispetta le specifiche del progrmma  \n");
    }
    else{
        printf("\nIl parametro (rows)  non rispetta le specifiche del progrmma  \n");
        return false;
    }

    if (cols>=5 && cols<=10){
        printf("\nIl parametro (rows) rispetta le specifiche del progrmma  \n");
    }
    else{
        printf("\nIl parametro (rows)  non rispetta le specifiche del progrmma  \n");
        return false;
    }
    return true;

}

double ***allocate_matrix(input in){
    double ***matrix= malloc(sizeof(double ***));
    for (int i = 0; i <in.row ; ++i) {
        matrix[i]= malloc(sizeof(double **)*in.row);
        for (int j = 0; j < in.cols; ++j) {
            matrix[i][j]= malloc(sizeof(double)*in.cols);
        }
    }
    return matrix;
}

FILE *open_file(const char *file_name, const char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("\nFile opened successfully (file name->%s, mode->%s)\n", file_name, mode);
        return file_pointer;
    } else {
        perror("Error opening file");
        exit(-1);
    }
}

void close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("\nError closing file ..");
        exit(-1);
    } else {
        printf("\nFile closed with success\n");
    }
}

void fill_matrix(input in,double ***matrix){
    FILE *fp= open_file(in.name_file,"r");
    for (int i = 0; i < in.row; ++i) {
        fscanf(fp,"\n");
        for (int j = 0; j < in.cols; ++j) {
            fscanf(fp,"%lf",&*(matrix[i][j]));
        }
    }
}

void print_matrix(input in, double ***matrix){
    for (int i = 0; i < in.row; ++i) {
        for (int j = 0; j < in.cols; ++j) {
            printf("%f",*matrix[i][j]);
        }
    }
}

void normalize_matrix(double ***matrix,int rows, int cols){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            
        }
    }
}

void extractColumn(double** matrix, double* column, int N, int col) {
    for (int i = 0; i < N; i++) {
        column[i] = matrix[i][col];
    }
}

void sort_column(double* column, int N) {
    double tmp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (column[i] < column[j]) {
               tmp=column[j];
               column[i]=column[j];
               column[j]=tmp;
            }
        }
    }
}

void sort_matrixCols(double** matrix, int N, int M) {
    for (int j = 0; j < M; j++) {
        double* column = malloc(N * sizeof(double));
        if (!column) {
            fprintf(stderr, "Errore nell'allocazione di memoria per la colonna.\n");
            exit(EXIT_FAILURE);
        }

        extractColumn(matrix, column, N, j);
        sort_column(column, N);

        for (int i = 0; i < N; i++) {
            matrix[i][j] = column[i];
        }

        free(column);
    }
}

void max_col(double *column, int size){
    double max=column[0];
    for (int i = 0; i < size; ++i) {
        if (column[i]>max){
            max=column[i];
        }
    }
}