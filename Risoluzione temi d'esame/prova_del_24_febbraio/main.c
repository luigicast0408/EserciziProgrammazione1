#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct input {
    int N;
    char a;
    char b;
} input;

typedef struct data {
    char value;
} data;

typedef struct node {
    data d;
    struct node *next;
} node;

bool check_input(char a, char b, int N);
bool readInput(input *check, int argc, char *argv[]);
void push(node **top, data *d);
bool is_empty(node **top);
void pop(node **top);
void print_stack(node **top);
char gen_vowel();
void fill_stack(input in, node **top);
void check_variable_x(char x, node **top, input in);
char gen_consonant();
void print_data(data *ptr);

unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16); m_w = 18000 * (m_w & 65535) + (m_w >> 16); return (m_z << 16) + m_w;
}

int main(int argc, char *argv[]) {
    input in;
    if (readInput(&in, argc, argv)) {
        node *top = NULL;
        fill_stack(in, &top);
        print_stack(&top);
    }
}

bool readInput(input *check, int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Errore nei parametri della funzione main()");
        return false;
    }

    char *ptr1;
    check->N = strtol(argv[1], &ptr1, 10);
    check->a = *argv[2];
    check->b = *argv[3];
    printf("%d %c %c", check->N, check->a, check->b);
    return check_input(check->a, check->b, check->N);
}

bool check_input(char a, char b, int N) {
    if (N >= 5 && N <= 10) {
        printf("\n il parametro (N) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (N) non rispetta le specifiche\n");
        return false;
    }

    if (a >= 'a' && a <= 'z') {
        printf("\n il parametro (a) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (a) non rispetta le specifiche\n");
        return false;
    }

    if (b >= 'a' && b <= 'z') {
        printf("\n il parametro (b) rispetta le specifiche\n");
    } else {
        fprintf(stderr, "\n il parametro (b) non rispetta le specifiche\n");
        return false;
    }
    return true;
}

bool is_empty(node **top) {
    return top == NULL ? true : false;
}

void push(node **top, data *d) {
    node *new_node = malloc(sizeof(node));
    new_node->d = (*d); //insert the data in the node
    if (!is_empty(top)) {
        new_node->next = *top; //
    }
    *top = new_node;
}

void pop(node **top) {
    if (!is_empty(top)) {
        node *tmp = *top;  //punatotore tmp che punta a top
        (*top) = (*top)->next; //sposto la testa al prossimo nodo
        free(tmp); // delete the old top
    } else {
        fprintf(stderr, "\nThere isn't elements in the list\n");
        return;
    }
}

void print_stack(node **top) {
    if (!is_empty(top)) {
        node *curr = *top;
        while (curr != NULL) {
            printf("\nstack->%c\n", curr->d.value);
            curr = curr->next;
        }
    } else {
        fprintf(stderr, "\n the stack is empty\n");
    }
}

char gen_vowel() {
    srand(time(0));
    char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    int num_vowels = sizeof(vowels) / sizeof(vowels[0]);
    int random_index = rand() % num_vowels;
    return vowels[random_index];
}

char gen_consonant() {
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'c', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w','y', 'z', '\0'};
    int num_consonant= sizeof(consonants) / sizeof(consonants[0]);
    printf("\n sizeof(consonants)->%lu  sizeof(consonants[0])->%lu \n",(sizeof(consonants[0])),(sizeof(consonants[0])));
    int random_index = get_random() % num_consonant;
    return consonants[random_index];
}

void fill_stack(input in, node **top) {
    srand(time(0));
    char start = '1', end = '9';
    char x;
    for (int i = 0; i < in.N; ++i) {
        x = rand() / ((end - start) + 1 + start);
        printf("\n x->%c\n",x);
        check_variable_x(x, top, in);
    }
    //data d;
    //d.value = x;
    //push(top, &d);
}

void check_variable_x(char x, node **top, input in) {
    if (x >= '1' && x <= '4') {
        data d;
        int N = (char) x;
        printf("x->%d    %c",N,N);
        for (int i = 0; i < N; ++i) {
            d.value = gen_vowel();
            if (d.value == in.a) {
                d.value = '*';
            }
            push(top, &d);
        }
    } else if (x >= '5' && x <= '9') {
        data d;
        int N = (char) x;
        for (int i = 0; i < N; ++i) {
            d.value = gen_consonant();
            if (d.value == in.b) {
                d.value = '?';
            }
            push(top, &d);
        }
    }
}
