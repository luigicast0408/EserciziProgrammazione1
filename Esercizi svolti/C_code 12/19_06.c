#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

/* 
  Le union permettono di definire una struttura
  dati i cui membri sono allocati a partire dallo 
  stesso indirizzo di memoria. 

  Lo spazio occupato in memoria dalla union equivale allo spazio 
  necessario a mantenere in memoria il tipo piu' 
  grande. 
*/ 

typedef enum Type { 
  number, character
} Type;

typedef union Value{
  int num;
  char c; 
} Value;

/* 
  Il record: tipo e valore.
*/ 
typedef struct Record {
  Type t;
  Value v;
} Record;

void print_all_records(struct Record arr[], int l){
  for(int i=0; i<l; i++)
    switch(arr[i].t){ //switch sulla enumerazione
      case number: 
	printf("\n Number: %d", arr[i].v.num); 
	break; 
      case character: 
	printf("\n Character: %d", arr[i].v.c); 
	break; 
      default:
	printf("\n Undefined"); 
    }
}


int main(){

  srand(time(0));

  const int DIM = 10;

  Record *array = (Record *) malloc(sizeof(Record)* DIM); 

  //Quanto occupa una struttura di tipo union? 
  printf("\n sizeof(Value): %zd, sizeof(int): %zd, sizeof(char): %zd", sizeof(Value), 
	sizeof(int), sizeof(char));

  for(int j=0; j<DIM; j++){
    if(rand() % 2 == 0){ // record di tipo char 
      array[j].t = character;
      (array[j].v).c = (char) (rand()%26 + 'a');
    }
    else{ // record di tipo int 
      array[j].t = number;
      (array[j].v).num = (short) (rand()% 100);
    }
  }

  print_all_records(array, DIM);
}
