#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct input{
    int k;
    char *file_name;
}input;

bool readInput(input in, int argc, char *argv[]);
bool check_input(int k);

int main(int argc, char *argv[])
{
    input in;
    if (readInput(in,argc,argv)!=false){
        //retst of the code
        printf("\nOK!!\n");
    } else{
        exit(-1);
    }
}

bool readInput(input in, int argc, char *argv[]) {
    if (argc < 3) {    //the 0 parameter is the name of exe 1+2
        //argc contains the number of parameter exe ./main output.txt 2
        fprintf(stderr, "Error in main function parameters");
        return false;
    }

    in.file_name = argv[1]; //
    in.k = strtol(argv[2], NULL, 10);

    return check_input(in.k);
}

bool check_input(int k) {
    return (k >= 7 && k <= 13);
}