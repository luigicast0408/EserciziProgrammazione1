#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct input{
    char file_name[20];
    float f;
}input;

 typedef struct record {
    float value;
    char word[31]; // 30 caratteri per la parola + 1 per il terminatore nullo
    struct Record* next;
    struct Record* prev;
}record;


 input *read_input(int argc, char *argv[]);
bool check_input(double f);
FILE *open_file(const char *file_name,  const char *mode);
void close_file(FILE *file_pointer);
bool check_number_in_range(double f);
bool isEmptyDls(const struct record *head);
void printListDls(record *head);
void insertRecord( char word[],float value,record **head);
//void deleteNodoDls(data* ptrDato, record **head);
void build_list_d(const char *file_name,record **head);
void elab(float f, record **head);

int main(int argc, char *argv[]) {
    record *head = NULL;
    input *in = read_input(argc, argv);
    if (in!=NULL){
        printf("\nOK\n");
    } else{
        printf("error");
        exit(EXIT_FAILURE);
    }


    build_list_d(in->file_name, &head);
    printListDls(head);

    elab(in->f, &head);
    free(head);
    free(in);

}


input *read_input(int argc, char *argv[]){
    char *ptr;
    input *in= malloc(sizeof(in));
    if (argc<3){
        fprintf(stderr,"\nThe number of parameter on main function is incorrect\n");
        exit(EXIT_FAILURE);
    }
    strcpy(in->file_name,argv[1]);
    in->f=strtof(argv[2],&ptr);
    printf("\nfile-name->%s, parameter->%f\n", in->file_name,in->f);

    if (check_number_in_range(in->f)==false){

        return NULL;
    }
    return in;
}

bool check_number_in_range(double f){
    return f>=1.0 && f<=20.0 ? true : false;
}

bool check_len_str(char string[]){
    return strlen(string)>=30 ? true: false;
}

FILE *open_file(const char *file_name, const char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("\nFile opened successfully (file name->%s, mode->%s)\n", file_name, mode);
        return file_pointer;
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
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

bool isEmptyDls(const struct record *head){
    return head==NULL ? true:false;
}

void printListDls(record *head){
    record *curr=head;
    while (curr!=NULL){
        printf("\nstring->%s value->%f\n",curr->word,curr->value);
        curr=curr->next;
    }
}

void insertRecord( char word[],float value,record **head){
    record *node_new=(struct record *) malloc(sizeof(record)); // insert the data in the record
    node_new->next=NULL;
    node_new->prev=NULL;


    if (isEmptyDls(*head)){
       *head=node_new;
        return;
    }
    record *prev=NULL;
    record *curr=*head;
    while (curr != NULL && strcmp(curr->word, (word)) <0){
        prev=curr;
        curr=curr->next;

    }
    node_new->prev=prev; // il nuovo prev è il precedente al curr
    node_new->next=curr; // il next diventa il curr
    if(prev == NULL){ //inserimento in testa
        *head = node_new; // il nuovo nodo diventa la testa

    } else{
            prev->next=node_new;
    }
    if (curr!=NULL){
        curr->prev=node_new;
    }
}

void build_list_d(const char *file_name,record **head){
   FILE  *fp= open_file(file_name,"r");
   char buffer[30];
   float  number;
   while (!(fscanf(fp, "%f",&number))){
       ;// sequence (numer-string)
        //fscanf(fp,"\n");
        if(fscanf(fp,"%s",buffer)!=1){
            printf("\n Error on fscanf()\n");
            exit(EXIT_FAILURE);
        }
        insertRecord(buffer,number,head);
    }
    close_file(fp);
}

void elab(float f, record **head){
    record *curr= (record *) head;
    int count=0;
    while (curr!=NULL){
        if (curr->value>=f){
            count++;
        }
        curr=curr->next;
    }
    printf("\n There are %d record with (curr->value>=f)\n",count);
}