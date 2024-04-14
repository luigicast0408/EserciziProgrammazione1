#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data {
    int value; 
} data;

typedef struct node {
    struct node *next;
    data d;
} node;

bool isEmpty(const node *head);

void insert_node(data *ptr_data, node **head);

void print_list(node *head);

void delete_node(data value_del, node **head);



int main(int argc, char *argv[]) {

    data my_data;
    node *head=NULL;
    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i=0; i<5; i++){
        printf("\nTrying to add data: [%d]\n", inputData[i]);
        my_data.value = inputData[i];
        insert_node(&my_data, &head);
    }

    print_list(head);

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i=0; i<3; i++){
        printf("\nTrying to delete data: [%d]\n", deleteData[i]);
        my_data.value = deleteData[i];
        delete_node(my_data, &head);
    }

    print_list(head);

}

bool isEmpty(const node *head) {
    return (head == NULL) ? true : false;
}

void print_list(node *head) {
    node *curr = head;
    while (curr != NULL) {
        printf("\n%d\n",(curr->d.value));
        curr = curr->next;
    }
}

void insert_node(data *ptr_data, node **head) {
    node *new_node = malloc(sizeof(node*));
    new_node->d=*ptr_data;

    if (isEmpty(*head) == true) {
        *head = new_node;
    } else {
        node *prev = NULL;
        node *curr = *head;

        while (curr != NULL && (curr->d.value > ptr_data->value)) {
            prev = curr;
            curr = curr->next;
        }

        if (prev != NULL) {
            prev->next=new_node;
        } else {
            *head = new_node; //aggiungo alla testa
        }

        if (curr!=NULL){  //aggiaungo alla coda
            new_node->next = curr;
        }
    }
}

void delete_node(data value_del, node **head) {
    if (isEmpty(*head) == true) {
        printf("\nThe list is empty\n");
        exit(EXIT_FAILURE);
    }

    node *prev = NULL;
    node *curr = *head;

    while (curr != NULL && (curr->d.value != value_del.value) ) {  //(curr->d.value != value_del.value in caso di interi altro strcmp()
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev) {  // im mezzo
            prev->next = curr->next;
        } else {
            *head=curr->next;
        }
        free(curr);
    }
}
