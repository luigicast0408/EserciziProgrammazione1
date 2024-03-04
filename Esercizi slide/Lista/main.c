#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct dato{
    int value;
}dato;

typedef struct nodo{
    struct dato data;
    struct nodo * next;
}nodo;

int compare_datas(const struct dato *d1, const struct dato *d2);
void printDato(const struct dato *d);
int isEmpty(const struct nodo *head);
void insertNodo_head(struct dato* ptrDato,  struct nodo **head);
void printList(const struct nodo *head);
void deleteNodo(struct dato* ptrDato, struct nodo **head);

int main()
{
    struct nodo *head=NULL;

    struct dato d1={2};
    insertNodo_head(&d1,&head);

    struct dato d2={3};
    insertNodo_head(&d2,&head);

    printList(head);
    //compare_datas(d1.value,d2.value);
    deleteNodo(&d1,&head);
    printList(head);
}
int compare_datas(const struct dato *d1, const struct dato *d2){
    if(d1->value==d2->value){
        return 0;
    } else if((*d1).value < (*d2).value){
        return -1;
    } else if((*d1).value > (*d2).value){
        return -1;
    }
    return 2;
}

void printDato(const struct dato *d) {
    printf("\ndato->%d\n",d->value);
}


int isEmpty(const struct nodo *head){
    if(head==NULL){
        return -1;
    } else{
        return 0;
    }
}

void insertNodo_head(struct dato* ptrDato,  struct nodo **head){
    nodo *new_node=malloc(sizeof(nodo));
    if(isEmpty(new_node)==0){
        new_node->data.value=ptrDato->value; //il dato ha il valore di *ptrDato
        new_node->next=*head; //fa puntare il  puntatore alla  valore della testa
        *head=new_node;  //la testa assume il valore del nuovo nodo;
        //ricapitolando prima si passa il valore new_node->data=*ptrDato;
        //poi si a settare il punatore nel nuovo nodo alla tsta perche il nuovo nodo deve essere il primo
        //poi si fa puntare la testa al nuovo nodo


    } else{
        fprintf(stderr,"Errore la lista e' vuota");
    }
}

void insertNodo_midle(struct dato* ptrDato,  struct nodo **head){
    nodo *new_node= malloc(sizeof(nodo));
    new_node->data.value=20;
    new_node->next=NULL;

    nodo *prev=NULL;
    nodo *curr=NULL;
    //2 puntatori che vanno messi a null
    while(curr!=NULL && ptrDato->value > curr->data.value ){

        prev=curr;   //faccio puntare prev a curr
        curr=curr->next; // curr punta al prossimo nodo
    }
    //in questo modo avrò prev nel nodo prima e curr nel nodo corrente
    prev->next=new_node;  //faccio puntare prev al nodo nodo
    new_node->next=curr; //il puntatore del nuovo nodo sarà curr
}

void printList(const struct nodo *head){
    while (head!=NULL){
        printDato(&head->data);
        head=head->next;
    }
}
void deleteNodo(struct dato* ptrDato, struct nodo **head){
    nodo *curr=NULL;
    nodo *tmp=*head;
    while (tmp!=NULL && tmp->data.value!=(ptrDato->value)){    //IERA FINCHE L'ELEMTO TMP E UGUALE A NULL E FINCHE NON HA TROVATO IL DATO
        curr= tmp;
        curr=curr->next;
        free(tmp);
    }
}

//OPPURE void deleteNodo(struct dato *ptrDato, struct nodo **head) {
//    nodo *curr = NULL;
//    nodo *tmp = *head;
//
//    while (tmp != NULL && compare_datas(&(tmp->data), ptrDato) != 0) {
//        curr = tmp;
//        tmp = tmp->next;
//    }
//
//    if (tmp != NULL) {
//        if (curr != NULL) {
//            curr->next = tmp->next;
//        } else {
//            *head = tmp->next;
//        }
//        free(tmp);
//    }
//}


