#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
char **insert_string(int row, int col);
void conugazione(char **string, int row, int col);
void print_string(char **string, int row, int col);


int main()
{
char **string= insert_string(2,2);
print_string(string,2,2);
conugazione(string,2,2);
}
char **insert_string(int row, int col){
    char **string= malloc(sizeof(char *)*row);
    for (int i = 0; i < col; ++i) {
        string[i]= malloc(sizeof(char )*col);
    }
    for (int i = 0; i <row ; ++i) {

            printf("\nInserisci la stringa %d",i);
            scanf("%s",string[i]);

    }
    return string;
}
void conugazione(char **string, int row, int col){

    for (int i = 0; i <row ; ++i) {
    int len_str= strlen(string[i]);
        for (int j = len_str-3; j < len_str; ++j) {
            printf("\nstring->%s cognugazone:->%c\n",string[i],string[i][j]);
        }
    }
}

void print_string(char **string, int row, int col){
    for (int i = 0; i < row; ++i) {
        printf("string[%d]->%s\t",i,string[i]);
        }
    }

