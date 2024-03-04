#include <stdio.h>
typedef struct dato{
    const struct dato *value;
}dato;

typedef struct nodo{
    struct dato data;
    struct nodo * next;
}nodo;

void push(struct nodo **top, const struct dato *d);

int main(){

}
void push(struct nodo **top, const struct dato *d){

}