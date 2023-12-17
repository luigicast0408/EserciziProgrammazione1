#include <stdio.h> 

typedef struct Record {
    char *nome;
    char *cognome; 
    int dato; 
} Record;  // Record e' alias del tipo struct Record


int main(){

    // le seguenti definizioni sono equivalenti..
    Record record1; 
    struct Record record2; 

    //... 
    
}
