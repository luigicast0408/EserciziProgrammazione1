#ifndef QUEUE_H
    #define QUEUE_H

    #include "../../common/single_ref_node.h"
    #include "../../common/data.h"
    
    struct queue{
	struct nodo *tail;
	struct nodo *head;
    }; 

    
    void enqueue(struct queue *q, struct dato *d);
    int dequeue(struct queue *q, struct dato *d);
    void printQueue(struct queue *q);
    int isEmpty(struct queue *q); 

#endif     
