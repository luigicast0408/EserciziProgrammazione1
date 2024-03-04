#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct input{
    char *file_name;
    int k;
}input;

typedef struct data{
    char *value;
}data;

typedef struct node{
   data d;
   struct node *next;
}node;

void push( node **top, data *d);
bool is_empty(node *top);
void pop(node **top, data *d);
void print_stack(node *top, input in);
bool check_input(input *in, int argc, char *argv[]);
bool check_parameter(int k);
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);
char *sort_word(char *word);
void build_queue(node **head, input in);


int main(int argc, char *argv[]){
    input in;
    node *head=NULL;
    if (check_input(&in,argc,argv)!=true){
        printf("\nError!\n");
        exit(EXIT_FAILURE);
    }
    build_queue(&head,in);
}

bool check_input(input *in, int argc, char *argv[]){
    if (argc<3){
        fprintf(stderr,"\nError in main() parameter \n");
        exit(-1);
    } else{
        printf("\nThe number of parameter is OK!!\n");
    }
    char *ptr;
    in->file_name=argv[1];
    in->k= strtol(argv[2],&ptr,10);
    return check_parameter(in->k);
}

bool check_parameter(int k){
    return k>=5 && k<=15 ? true : false;
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

char *sort_word(char *word){
    char *string= malloc(sizeof(strlen(string)));
    for (int i = 0; i < strlen(string)-1; ++i) {
        for (int j = 0; j < strlen(string)-1; ++j) {
            if (string[i]>string[j]){
                char temp=string[j];
                string[i]=string[j];
                string[j]=temp;
            }
        }
    }
    return string;
}

void build_queue(node **head, input in) {
    FILE *fp = open_file(in.file_name, "r");
    printf("\n I am here\n");
    char string[30];
    data d;

    while (fscanf(fp, "%s", string) == 1) {
        printf("\nEtro nel while\n");
        char *sortedString = sort_word(string);
        d.value = malloc(strlen(sortedString) + 1);
        strcpy(d.value, sortedString);

        printf("\nvalue->%s\n", d.value);
        push(head, &d);

    }

    print_stack(head, in);
    close_file(fp);
}

bool is_empty(node *top) {
    return top==NULL ? true:false;
}

void push(node **top, data *d) {
    node *new_node= malloc(sizeof(node));
    new_node->d=*d;
    if(!is_empty(*top))
        new_node->next = *top;
    *top = new_node;
}

void pop(node **top, data *d) {
    if (is_empty(*top)){
        fprintf(stderr,"\nThere isn't elements in the list\n");
        exit(EXIT_FAILURE);
    } else{
        node *tmp=*top;
        (*top)= (*top)->next; //sposto la testa al prossimo nodo
        free(tmp); // delete the old top
    }
}

void print_stack(node *top, input in){   //change % if the text ask float or char
    if(is_empty(top)){
        printf("\n The stack is empty \n");
        exit(EXIT_FAILURE);
    }

    node *curr = top;
    while(curr!=NULL){
        printf("%s\n",curr->d.value);
        curr=curr->next;
    }
}
