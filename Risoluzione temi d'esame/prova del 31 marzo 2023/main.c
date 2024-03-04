#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct input {
    const char *file_name;
    int k;
} input;

typedef struct data {
    char value[20];
} data;

typedef struct node {
    struct node *prev;
    struct node *next;
    data d;
} node;

bool check_input(int k);
bool readInput(input *in, int argc, char *argv[]);
bool is_empty(node *head);
void print_list(node *head);
void insert_node_d(data *ptr_data, node **head);
void delete_node_d(data *ptr_data, node **head);
void print_data(data *d);
FILE *open_file(const char *file_name, const char *mode);
void close_file(FILE *file_pointer);
void read_strings(input in, node **head);
void cont_strings(node *head, int k);

int main(int argc, char *argv[]) {
    input in;
    node *head = NULL;

    if (readInput(&in, argc, argv)) {
        read_strings(in, &head);
        print_list(head);
        cont_strings(head, in.k);
    } else {
        exit(EXIT_FAILURE);
    }

    return 0;
}

bool readInput(input *in, int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error in main function parameters\n");
        return false;
    }

    in->file_name = argv[1];
    in->k = strtol(argv[2], NULL, 10);

    return check_input(in->k);
}

FILE *open_file(const char *file_name, const char *mode) {
    FILE *file_pointer = fopen(file_name, mode);
    if (file_pointer != NULL) {
        printf("File opened successfully (file name->%s, mode->%s)\n", file_name, mode);
        return file_pointer;
    } else {
        fprintf(stderr, "Error opening file\n");
        perror("");
        exit(EXIT_FAILURE);
    }
}

void close_file(FILE *file_pointer) {
    if (fclose(file_pointer) == EOF) {
        perror("Error closing file");
        exit(-1);
    } else {
        printf("File closed with success\n");
    }
}

void cont_strings(node *head, int k) {
    int count_strings = 0;
    node *tmp = head;
    while (tmp != NULL) {
        printf("\nstring->%s    len: %lu\n",tmp->d.value, strlen(tmp->d.value));
        if (strlen(tmp->d.value) >= k) {
            printf("String with length at least %d: %s\n", k, tmp->d.value);
            count_strings++;
        }
        tmp = tmp->next;
    }
    printf("There are %d strings with length at least %d\n", count_strings, k);
}

bool is_empty(node *head) {
    return head == NULL ? true : false;
}

void print_list(node *head) {
    printf("\n________Print List_____\n");
    node *curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->d.value);
        curr = curr->next;
    }
    printf("________Print List_____\n");
}

void insert_node_d(data *ptr_data, node **head) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->d = *ptr_data;

    if (is_empty(*head)) {
        *head = new_node;
    } else {
        node *curr = *head;
        node *prev = NULL;

        while (curr != NULL && strcmp(curr->d.value, ptr_data->value) < 0) {
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL) {
            // Inserimento in testa
            *head = new_node; // il nuovo nodo diventa la testa
        } else {
            prev->next = new_node;
        }

        if (curr != NULL) {
            curr->prev = new_node; // Inserimento in mezzo
        }
    }
}

void delete_node_d(data *ptr_data, node **head) {
    if (is_empty(*head)) {
        printf("The list is empty\n");
        exit(EXIT_FAILURE);
    } else {
        node *curr = *head;
        node *prev = NULL;
        while (curr != NULL && (strcmp(curr->d.value, ptr_data->value) != 0)) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                *head = curr->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            }

            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }

            free(curr);
        }
    }
}

void read_strings(input in, node **head) {
    FILE *fp = open_file(in.file_name, "r");
    char string[100];
    data d;

    while (fscanf(fp, "%s", string) == 1) {
        strcpy(d.value, string);
        insert_node_d(&d, head);
    }

    close_file(fp);
}

bool check_input(int k) {
    return (k >= 7 && k <= 13);
}
