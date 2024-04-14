#ifndef DOUBLE_LIST_H
    #define DOUBLE_LIST_H    

    #include "../../common/double_ref_node.h" 
    
    int isEmptyDls(const struct double_ref_nodo *head);
    void printListDls(const struct double_ref_nodo *head);
    
    void insertNodoDls(struct dato* ptrDato, struct double_ref_nodo **head);
    void deleteNodoDls(struct dato* ptrDato, struct double_ref_nodo **head); 

#endif
