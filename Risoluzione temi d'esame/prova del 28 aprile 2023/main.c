#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct input{
    const char *file_name;
    char c_a;
    char c_b;
}input;

typedef struct data {
    char value[100];
}data;

typedef struct node{
    struct data d;
    struct node * next;
}node;

typedef struct queue{
    struct node *tail;
    struct node *head;
}queue;

void enqueue( queue *q,data *d);
bool  dequeue(queue *q, data *d);
void print_queue(queue *q);
bool is_empty(queue *q);
void close_file(FILE *file_pointer);
FILE *open_file(const char *file_name, const char *mode);
bool check_input(input *in,int argc, char *argv[]);
bool check_parameter(char c_a,char c_b);
void build_queue(queue *q, input in);
bool check_len_str(char *string);
char *elab(char *string, char a, char b);


int main(int argc, char *argv[]){
    input in;
    queue q;
    q.head=q.tail=NULL;
    check_input(&in,argc,argv);
    build_queue(&q,in);

}
bool is_empty(struct queue *q){
    return  q->head==NULL ? true: false;
}

void print_queue(struct queue *q){
    printf("\n____________queue________\n");
    node *curr=q->head;
    while (curr!=NULL){
        printf("\n[%s]\n",curr->d.value);
        curr=curr->next;
    }
    printf("\n____________queue________\n");
}

void enqueue(queue *q, data *d) {
    node *new_node = malloc(sizeof(*new_node));
    strcpy(new_node->d.value, d->value);
    new_node->next = NULL;

    if (is_empty(q)) {
        q->head = q->tail = new_node;
    } else {
        (q->tail)->next = new_node;
        q->tail = new_node;
    }
}
bool dequeue(queue *q, data *d) {
    if (is_empty(q)) {
        printf("\nThe list is empty\n");
        exit(EXIT_FAILURE);
    }

    node *tmp = q->head;
    strcpy(d->value, tmp->d.value);

    (q->head) = tmp->next;
    free(tmp);

    return true;
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

void build_queue(queue *q, input in) {
    FILE *fp = open_file(in.file_name, "r");
    char string[30];
    while (fscanf(fp, "%s", string) == 1) {
            data d;
            strcpy(d.value,string);
        //printf("\nsource->%s   destination->%s\n",string,d.value);
        if (check_len_str(d.value)!=false){
            char elab_string[30];
            strcpy(elab_string,elab(d.value,in.c_a,in.c_b));
            strcpy((d.value),(elab_string));
            //printf("\nstring->%s   stringel->%s\n",(elab(d.value,in.c_a,in.c_b)),(d.value));
            enqueue(q, &d);
        } else{
            printf("\nerror\n");
        }

    }
    print_queue(q);
    fclose(fp);
}

bool check_input(input *in,int argc, char *argv[]){
    if (argc<4){
        fprintf(stderr,"\nError on parameter of main() function\n");
        exit(-1);
    }
    in->file_name=argv[1];
    in->c_a=*argv[2];
    in->c_b=*argv[3];
    printf("\n file name->%s A->%c  B->%c\n",in->file_name,in->c_a,in->c_b);
    return check_parameter(in->c_a,in->c_b);
}

bool check_parameter(char c_a,char c_b){
    if (c_a<=c_b){
        printf("\nthe parameters respect the request\n");
        return true;
    } else{
        fprintf(stderr,"\nthe parameters respect the request\n");
        return false;
    }
}

bool check_len_str(char *string){
    return strlen(string)<=30 ? true : false;
}

char*elab(char *string, char a, char b) {
    char *result = malloc(strlen(string) + 1);
    strcpy(result, string);

    for (int i = 0; i < strlen(result); ++i) {
        for (char j = a; j < b; ++j) {
            if (result[i] >= a && result[i] <= b) {
                result[i] = '0';
            }
        }
    }
    return result;
}
