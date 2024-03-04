#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct  record{
    float num;
    char *S;
    char *W;
    char car;
}record;
void inizilize_structure( struct  record *vett);
void print_results(struct record *vett);

int main()
{
    record  record[20];
    inizilize_structure(record);
    print_results(record);

}
void inizilize_structure( struct  record *vett){
    srand(time(NULL));

    char start_char='a', end_char='z';
    char start_num='0', end_num='9';

    vett->S= malloc(sizeof(char)*11);
    vett->W= malloc(sizeof(char)*11);

    for (int i = 0; i < rand()%10; ++i) {
        vett->W[i]=rand()/(char)((end_num-start_num+1)+start_num);
    }
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        vett->S[i]=rand()/(char)((end_char-start_char+1)+start_char);
    }
    vett->W[10] = '\0'; // Null-terminate the string
    vett->S[10] = '\0'; // Null-terminate the string

    vett->car=rand()/(char)((end_num-start_num+1)+start_num);
    vett->num=(float)rand()/(1.0*RAND_MAX);

}
void print_results(struct record *vett){
    printf("\nW->%s\n",vett->W);
    printf("\nS->%s\n",vett->S);
    printf("\nchar->%c\nc",vett->car);
    printf("\nnum-> %f\n",vett->num);
}
