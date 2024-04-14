#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct data{
    int  value;  //change this type if the text ask a float or *char
}data;

typedef struct  node{
    data d;
    struct node * next;
}node;


void push( node **top, data *d);
bool is_empty(node *top);
void pop(node **top, data *d);
void print_stack(node *top);

int main() {
    int v[20]={1,2,4,5,6,7,8,9,0,21,2,};
    data d;
    node *top=NULL;
    for (int i = 0; i <11 ; ++i) {
        d.value=i;
        printf("\nAdd list[%d]->%d\n",i,d.value);
        push(&top,&d);

    }
    print_stack(&top);
    for (int i = 0; i < 11; ++i) {
        d.value=i;
        printf("\n Delete list[%d]->%d\n",i,d.value);
        pop(&top,&d);
    }
}


bool is_empty(node *top) {
    return top==NULL ? true:false;
}

void push(node **top, data *d) {
    node *new_node= malloc(sizeof(node));
    new_node->d=*d;
    if(!is_empty(*top))
        new_node->next = *top;
    *top = new_node;
}

void pop(node **top, data *d) {
    if (is_empty(*top)){
        fprintf(stderr,"\nThere isn't elements in the list\n");
        exit(EXIT_FAILURE);
    } else{
        node *tmp=*top;
        (*top)= (*top)->next; //sposto la testa al prossimo nodo
        free(tmp); // delete the old top
    }
}

void print_stack(node *top){   //change % if the text ask float or char
    if(is_empty(top)){
        printf("\n The stack is empty \n");
        exit(EXIT_FAILURE);
    }
    node *current =top;
    while(current!=NULL){
        printf("%d\n",current->d.value);
        current=current->next;
    }
}