#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct input{
    const char *file_name;
}input;

typedef struct data {
    char *value;
}data;

typedef struct node{
    struct data d;
    struct node * next;
}node;

typedef struct queue{
    struct node *tail;
    struct node *head;
}queue;

int isEmpty(queue *q);
void printDato(const data *ptr);
void printQueue(queue *q);
int dequeue(queue *q,  data *d);
void enqueue(queue *q, data *d);
void close_file(FILE *file_pointer);
FILE *open_file(const char *file_name, const char *mode);
bool check_input(input *in,int argc, char *argv[]);
bool check_parameter(char c_a,char c_b);
void  build_queue(queue *q, input in);
bool check_len_str(char *string);
void array_of_strings(queue *q);
void print_vector(char **vector,int size);
void sort_array(char **vector, int size);

int main(int argc, char *argv[]){
    input in;
    queue q;
    q.head=q.tail=NULL;
    check_input(&in,argc,argv);
    build_queue(&q,in);
    printQueue(&q);
}

int isEmpty(queue *q){
    return (q->head == NULL);
}

void printDato(const data *ptr){
    printf(" [%s]\n", ptr->value);
}

void printQueue(queue *q){
    if(isEmpty(q)){
        printf(" ** EMPTY QUEUE ** ");
        return;
    }
    node *current =  q->head;

    printf("\n ** QUEUE ** \n ");
    printf(" (head) ");
    while(current!=NULL){
        printDato(&(current->d));
        current=current->next;
    }

    printf(" (tail) ");
}

int dequeue(queue *q,  data *d){
    if(isEmpty(q))
        return -1;

    // copia il dato nell'area di memoria predisposta dallo user code
    memcpy(d, &((q->head)->d), sizeof(data));

    node *tmp = q->head;
    (q->head) = tmp->next;

    free(tmp); // libera lo spazio occupato dal nodo

    return 1;
}

void enqueue(queue *q, data *d){

    node *new_node = (struct node *) malloc(sizeof(node));
    memcpy(&(new_node->d), d, sizeof(data));

    new_node->next = NULL;

    if(isEmpty(q))
        q->head = q->tail = new_node;

    else{
        (q->tail)->next = new_node;
        q->tail = new_node;
    }
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

void  build_queue(queue *q, input in) {
    FILE *fp = open_file(in.file_name, "r");
    char string[30];
    while (fscanf(fp, "%s", string) == 1) {
        data d;
        d.value = strdup(string);
        if (check_len_str(d.value)!=false){
            enqueue(q, &d);
        } else{
            printf("\nerror\n");
        }
    }
    array_of_strings(q);


    fclose(fp);
}

bool check_input(input *in,int argc, char *argv[]){
    if (argc<2){
        fprintf(stderr,"\nError on parameter of main() function\n");
        exit(-1);
    }
    in->file_name=argv[1];
    return true;
}

bool check_len_str(char *string){
    return strlen(string)<=30 ? true : false;
}

void array_of_strings(queue *q){
    int count=0;
    char **array_of_strings= malloc(sizeof(char **)*100);
    for (int i = 0; i < 100; ++i) {
        array_of_strings[i]= malloc(sizeof(char )*100);
    }
    node *tmp=q->head;
    while (tmp!=NULL){
        array_of_strings[count]=tmp->d.value;
        //printf("\narray->%s\n",array_of_strings[count]);
        tmp=tmp->next;
        count++;
    }
    sort_array(array_of_strings,count);
    print_vector(array_of_strings,count);
}

void print_vector(char **vector,int size){
    for (int i = 0; i < size; ++i) {
        printf("%s\n",vector[i]);
    }
}

void sort_array(char **vector, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(vector[j], vector[j + 1]) > 0) {
                char *temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}