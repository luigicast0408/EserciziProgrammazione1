#ifndef STACK_H
    #define STACK_H

    #include "../common/data.h"
    #include "../common/single_ref_node.h"
    
    /* Copia il dato puntato da d sul top dello stack*/ 
    void push(struct nodo **top, struct dato *d); 
    /* restituisce un numero > 0 se e' presente almeno un dato, 
    il quale viene copiato nell'area di memoria puntata da d;	
    altrimenti restituisce -1
    */ 
    int pop(struct nodo **top, struct dato *d);

    int isEmpty(struct nodo *top); 

    void printStack(struct nodo *top); 

#endif 
