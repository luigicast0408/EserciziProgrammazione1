#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define  DIM 15
char *insert_elemets();
void print_vector(char *vector);
void print_string_char();
void print_string();
void print_pointer_char();


int main()
{
  char *vector=insert_elemets();
    print_vector(vector);
    print_string();
    print_string_char();
    print_pointer_char();
    free(vector);
}
char *insert_elemets(){
    char start='a';
    char end='z';
    srand(time(0));
    char * vector= malloc(sizeof(char)*DIM);
    for (int i = 0; i < DIM; ++i) {
        vector[i]= (char)(rand()/(end-start+1)+start);
    }
    return vector;
}

void print_vector(char *vector){
    printf("\n_______VECTOR_____________\n");
    for (int i = 0; i < DIM; ++i) {
        printf("%c\t",vector[i]);
    }
    printf("\n_______VECTOR_____________\n");
}

void print_string_char(){
    char string[20]={'a','b','c','d','e'};
    printf("\nstringa:%s   lunghezza:%d\n",string, (strlen(string)));
}

void print_string(){
    char string[20]="My string";
    printf("\nstringa:%s   lunghezza:%d\n",string, (strlen(string)));
}

void print_pointer_char(){
    const  char* string="mmm";
    printf("\nstringa:%s   lunghezza:%d\n",string, (strlen(string)));
}


