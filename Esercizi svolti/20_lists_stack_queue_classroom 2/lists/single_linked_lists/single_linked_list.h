#ifndef SINGLE_LIST_H
    #define SINGLE_LIST_H
    #include "../../common/single_ref_node.h" 
    
    int isEmpty(const struct nodo *head);
    void printList(const struct nodo *head);
    
    void insertNodo(struct dato* ptrDato, struct nodo **head);
    void deleteNodo(struct dato* ptrDato, struct nodo **head);   

#endif 
