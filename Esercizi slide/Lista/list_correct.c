#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dato{
    int value;
}dato;

typedef struct nodo{
    struct dato data;
    struct nodo * next;
}nodo;

int compare_datas(const dato *d1, const dato *d2);
void printDato(const dato *ptr);
int isEmpty(const nodo *head);
void insert_nodo( dato* ptrDato, nodo **head);
void printList(const  nodo *head);
void deleteNodo(dato* ptrDato, nodo **head);

int main(){
    nodo * head = NULL;
    dato my_data;

    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i=0; i<5; i++){
        printf("\n Trying to add data: [%d]", inputData[i]);
        my_data.value = inputData[i];
        insert_nodo(&my_data, &head);
    }

    printList(head);

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i=0; i<3; i++){
        printf("\n Trying to delete data: [%d]", deleteData[i]);
        my_data.value = deleteData[i];
        deleteNodo(&my_data, &head);
    }

    printList(head);
}

int compare_datas(const dato *d1, const dato *d2){
    if((*d1).value > (*d2).value)
        return 1;
    else if(d1->value < d2->value)
        return -1;
    return 0;
}

int isEmpty(const nodo *head){
    return head == NULL;
}

void printList(const  nodo *head){
    const struct nodo *ptr = head;

    printf("\n ** LIST **");
    while(ptr!=NULL){
        printDato(&(ptr->data));
        ptr=ptr->next;
    }

    printf(" **END LIST** \n");
}

void insert_nodo( dato* ptrDato, nodo **head){
    nodo *nuovo_nodo = (struct nodo *) malloc(sizeof(struct nodo)); // nuovo nodo
    nuovo_nodo->next = NULL;
    //memcpy((void *) &(nuovo_nodo->data), (void *) ptrDato, sizeof(struct dato)); // copia i dati nel nodo
    nuovo_nodo->data=*ptrDato;

    if(isEmpty(*head)){
        *head = nuovo_nodo;
        return;
    }

    nodo *current = *head, *previous=NULL;  // per la ricerca
    while(current!=NULL && compare_datas(&(current->data), &(nuovo_nodo->data))<0){
        previous = current;
        current=current->next;
    }

    if(previous!=NULL)
        previous->next = nuovo_nodo;
    else
        *head = nuovo_nodo; // inserimento in testa

    // se current == NULL, l'elemento sara' aggiunto in coda alla lista
    if(current!=NULL)
        nuovo_nodo->next = current;

}

void deleteNodo(dato* ptrDato, nodo **head){
    if(isEmpty(*head))
        return;

   nodo *current = *head, *previous = NULL;
    while(current!=NULL && compare_datas( &(current->data), ptrDato)!=0){
        previous = current; // mantiene il riferimento al nodo appena visitato
        current=current->next; // aggiorna il riferimento al prossimo nodo da visitare
    }

    if(current!=NULL){ //elemento esiste nella lista
        if(previous) // e non e' la testa della lista
            previous->next = current->next; // aggiorna il link..
        else
            *head = current->next; // aggiorna il puntatore al primo elemento
        free(current );
    }
}

void printDato(const dato *ptr){
    printf(" [%d] ", ptr->value);
}
