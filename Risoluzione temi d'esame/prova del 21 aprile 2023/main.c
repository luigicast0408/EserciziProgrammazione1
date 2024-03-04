#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct input {
    char *file_name;
    int k;
} input;

typedef struct data {
    char *value;
} data;

typedef struct node {
    data d;
    struct node *next;
} node;

bool check_input(int k);
bool read_input(input *in, int argc, char *argv[]);
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);
bool check_len_strings(char *string);
void build_stack(node **top, input in);
void push(node **top, data *d);
bool is_empty(node **top);
void pop(node **top);
void print_stack(node **top);
void print_data(data *ptr);
void check_string(node **top,input in);
char *sort_word(char string[]);

int main(int argc, char *argv[]) {
    input in;
    node *top = NULL;
    if (read_input(&in, argc, argv) == true) {
        build_stack(&top, in);
         check_string(&top,in);
         print_stack(&top);
    }
    return 0;
}

bool read_input(input *in, int argc, char *argv[]) {
    if (argc < 3) {
        printf("error\n");
        return false;
    }
    char *ptr;
    in->file_name = argv[1];
    in->k = strtol(argv[2], &ptr, 10);
    printf("\nFile name-> %s, k->%d\n", in->file_name, in->k);
    return check_input(in->k);
}

bool check_input(int k) {
    if (k >= 5 && k <= 15) {
        printf("\nIl parametro (k) rispetta le specifiche\n");
        return true;
    } else {
        printf("\nIl parametro (k) non rispetta le specifiche\n");
        return false;
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

void build_stack(node **top, input in) {
    char string[100];
    FILE *fp = open_file(in.file_name, "r");
    while (fscanf(fp, "%s", string) == 1) {
        //printf("strings->%s\t", string);
        if (check_len_strings(string)) {
            fprintf(stderr, "\nlunghezza maggiore 30 caratteri\n");
            exit(-1);
        } else {
            data *d = malloc(sizeof(data));
            d->value = strdup(string);
            push(top, d);
        }
    }
    fclose(fp);
}

bool check_len_strings(char *string) {
    return strlen(string) >= 30 ? true : false;
}

bool is_empty(node **top) {
    return *top == NULL ? true : false;
}

void push(node **top, data *d) {
    node *new_node = malloc(sizeof(node));
    new_node->d = (*d);
    if (!is_empty(top))
        new_node->next = *top;
    *top = new_node;
}

void pop(node **top) {
    if (is_empty(top)) {
        fprintf(stderr, "\nThere aren't elements in the list\n");
        return;
    } else {
        node *tmp = *top;
        (*top) = (*top)->next;
        free(tmp->d.value); // free the memory allocated for the string
        free(tmp);
    }
}

void print_stack(node **top) {
    if (is_empty(top)) {
        printf("\n ** STACK is EMPTY ** \n");
        return;
    }

    node *current = *top;
    printf("\n **STACK ** \n");
    while (current != NULL) {
        print_data(&(current->d));
        if (current->next != NULL)
            printf("\n  | \n");
        current = current->next;
    }

    printf("\n");
}

void print_data(data *ptr) {
    printf(" [%s]\n", ptr->value);
}

char *sort_word(char string[]) {
    for (int i = 0; i < strlen(string); ++i) {
        for (int j = i + 1; j < strlen(string); ++j) {
            if (string[i] > string[j]) {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    printf("strings_sorted->%s\n",string);
    return string;
}

void check_string(node **top,input in){
    node *tmp=*top;
    while (tmp!=NULL){
        if(strlen(tmp->d.value)>=in.k){
            tmp->d.value=sort_word(tmp->d.value);
            print_data(&(tmp->d));

        }
        tmp=tmp->next;

    }
}