#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef struct data{
    int value;
}data;
typedef struct node{
    struct node *next;
    data d;
}node;
typedef struct queue{
    node *head;
    node *tail;
}queue;

void enqueue( queue *q,data *d);
bool  dequeue(queue *q, data *d);
void print_queue(queue *q);
bool is_empty(queue *q);
int main(){
    queue q;
    q.head = q.tail = NULL;

    int array[] = {1,2,3,4,5,6};

     data d;

    for(int i=0; i<6; i++){
        d.value  = array[i];
        printf("\n ADD element %d ** \n", d.value);
        enqueue(&q,&d);
    }
    print_queue(&q);


    for(int i=0; i<6; i++){
        printf("\n\n ** Removed element %d ** \n", d.value);
        d.value=i;
        dequeue(&q,&d);
    }
    print_queue(&q);
}

bool is_empty(struct queue *q){
    return  q->head==NULL ? true: false;
}

void print_queue(struct queue *q){
    node *curr=q->head;
    while (curr!=NULL){
        printf("\n[%d]\n",curr->d.value);
        curr=curr->next;
    }
}

void enqueue(queue *q, data *d){
    node *new_node= malloc(sizeof(*q));
    new_node->d.value=d->value;
    if (is_empty(q)==true){
        new_node=q->head=q->tail;
    } else{
        (q->tail)->next=new_node;
        q->tail=new_node;
    }
}

bool  dequeue(queue *q, data *d){
    if (is_empty(q)){
        printf("\nThe list is empty\n");
        exit(EXIT_FAILURE);
    }
    node *tmp = q->head;
    (q->head) = tmp->next;
    free(tmp);
    return false;
}
