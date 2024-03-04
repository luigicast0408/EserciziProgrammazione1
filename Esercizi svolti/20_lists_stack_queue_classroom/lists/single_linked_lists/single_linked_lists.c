#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

int isEmpty(const struct nodo *head){
    if(head==NULL){
        return -1;
    }
    return 0;
}

void printList(const struct nodo *head){
    while (head!=NULL){
        printDato(&head->d);
        head->next;
    }
}

void insertNodo(struct dato* ptrDato, struct nodo **head){
    struct nodo *nuovo;
    nuovo= malloc(sizeof(struct nodo));
    nuovo->next=*head;
    *head=nuovo->next;
}

void deleteNodo(struct dato* ptrDato, struct nodo **head){

    while(head==NULL){
        confronta_dati(ptrDato->value,*head)
    }


}