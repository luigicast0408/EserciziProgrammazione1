#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct data{
    int value;
}data;

typedef struct node{
    struct node *prev;
    struct node *next;
    data d;
}node;

bool is_empty(node *head);
void print_list(node *head);
void insert_node_d(data* ptr_data, node **head);
void delete_node_d(data* ptr_data, node **head);
void print_data(data *d);

int main() {
    node *head = NULL;
    data d;

    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i=0; i<5; i++){
        printf("\n Trying to add data: [%d]", inputData[i]);
        d.value = inputData[i];
        insert_node_d(&d, &head);
    }

    print_list(head);

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i=0; i<3; i++){
        printf("\n Trying to delete data: [%d]", deleteData[i]);
        d.value = deleteData[i];
        delete_node_d(&d, &head);
    }

    print_list(head);

}

bool is_empty( node *head){
    return head == NULL ? true:false;
}

void print_list(node *head){
    node *curr=head;
    while (curr!=NULL){
        printf("\n%d\n",curr->d.value);
        curr=curr->next;
    }
}

void insert_node_d(data* ptr_data, node **head){
    node *new_node = (node*) malloc(sizeof(node));
    new_node->next=NULL;
    (new_node)->prev=NULL;
    new_node->d=*ptr_data; //change this in case of strings with strcmpy
    if (is_empty(*head)==true){
        *head=new_node; //inserisco in testa
    } else{
        node *curr=*head;
        node *prev=NULL;
        while (curr!=NULL && (curr->d.value<ptr_data->value)){
            prev=curr;
            curr=curr->next;
        }
        if(prev == NULL){ //inserimento in testa
            *head = new_node; // il nuovo nodo diventa la testa

        } else{
            prev->next=new_node;
        }
        if (curr!=NULL){
            new_node->next=curr; //iserimento in mezzo
        }
    }
}

void delete_node_d(data* ptr_data, node **head){
    if(is_empty(*head)){
        printf("\nThe list is empty \n");
        exit(EXIT_FAILURE);
    } else{
        node *curr=*head;
        node *prev=NULL;
        while (curr!=NULL &&(curr->d.value!=ptr_data->value)){
            prev=curr;
            curr=curr->next;
        }
        if (curr != NULL) {
            if (prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                *head = curr->next;
            }
            free(curr);
        }

    }
}