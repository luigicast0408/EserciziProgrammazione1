#ifndef DATA_H
    #define DATA_H
    struct dato {
	const struct dato *value;
    };

    //typedef struct dato Dato; 
    
    /* restituisce 0 se i dati sono uguali, 
    oppure -1 se ((*d1).value < (*d2).value )
    oppure 1 se ((*d1).value > (*d2).value )
    */  
    int confronta_dati(const struct dato *d1, const struct dato *d2);
    void printDato(const struct dato *d);     
#endif 
