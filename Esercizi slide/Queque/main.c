#include <stdio.h>
#include <stdlib.h>
typedef struct dato{
    int value;
}dato;

typedef struct nodo{
    struct dato data;
    struct nodo * next;
}nodo;

typedef struct queue{
    nodo *tail;
    nodo *head;
}queue;

void enqueue(struct queue *q, struct dato *d);
int dequeue(struct queue *q, struct dato *d);
void printQueue(struct queue *q);
int isEmpty(struct queue *q);

int main(){

    queue *q = malloc(sizeof(queue));
    if (q == NULL) {
        fprintf(stderr, "Errore: impossibile allocare la memoria per la coda.\n");
        return EXIT_FAILURE;
    }
    q->head = NULL;
    q->tail = NULL;

    // Creazione e inserimento del primo dato
    dato dato1;
    dato1.value = 20;
    enqueue(q, &dato1);

    // Creazione e inserimento del secondo dato
    dato dato2;
    dato2.value = 30;
    enqueue(q, &dato2);

    // Stampa della coda
    printQueue(q);

    // Deallocazione della coda
    free(q);

}
int isEmpty(struct queue *q){
    if(q->tail==NULL){
        return -1;
    } else{
        return 1;
    }
}

void enqueue(struct queue *q, struct dato *d) {
    nodo *new_node= malloc(sizeof(nodo));
    new_node->data=*d;
    if (isEmpty(q)==-1){
        //lista vuota eseguo un inserimento in testa
        q->head=new_node;
        q->tail=new_node;
    } else{
        //lista con almeno 1 nodo eseguo un inserimento in coda(tail)
        new_node->data=*d;
        q->tail->next=new_node;
        q->tail=new_node;
    }
}

void printQueue(struct queue *q){
    nodo *tmp=q->head;
    while(tmp!=NULL){
        printf("\n%d\n",q->head->data.value);
        tmp=tmp->next;
    }
}