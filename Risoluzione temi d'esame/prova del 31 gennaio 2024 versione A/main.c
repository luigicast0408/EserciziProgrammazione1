#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct input {
    char a;
    char b;
    int x;
    int y;
    int n;
} input;

typedef struct data {
    char value[30];
} data;

typedef struct node {
    struct node *next;
    data d;
} node;

typedef struct queue {
    node *head;
    node *tail;
} queue;

unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

input *readInput(int argc, char *argv[]);
bool check_input(char a, char b, int x, int y, int n);
void enqueue(queue *q, data *d);
void dequeue(queue *q, data *d);
void print_queue(queue *q);
bool is_empty(queue *q);
char random_char(input *in);
char *generate_random_string(char *str, int length, input *in);
void build_queue(input *in, queue *q);
char *elab(char *string);

int main(int argc, char *argv[]) {
    input *in = readInput(argc, argv);
    if (in == NULL) {
        printf("\nErrore!\n");
        exit(EXIT_FAILURE);
    }

    queue q;
    q.head = q.tail = NULL;
    build_queue(in, &q);
    print_queue(&q);

    return 0;
}

input *readInput(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Utilizzo: %s a b x y n\n", argv[0]);
        return NULL;
    }

    input *in = malloc(sizeof(input));
    if (in == NULL) {
        fprintf(stderr, "Errore nell'allocazione di memoria per input\n");
        return NULL;
    }

    in->a = *argv[1];
    in->b = *argv[2];
    in->x = atoi(argv[3]);
    in->y = atoi(argv[4]);
    in->n = atoi(argv[5]);

    if (!check_input(in->a, in->b, in->x, in->y, in->n)) {
        fprintf(stderr, "Input non valido\n");
        free(in);
        return NULL;
    }

    return in;
}

bool check_input(char a, char b, int x, int y, int n) {
    return (((islower(a) && islower(b)) || (isupper(a) && isupper(b))) && (a <= b)) &&
           (x >= 5 && y <= 30 && y - x > 5) &&
           (n >= 15 && n <= 25);
}

bool is_empty(queue *q) {
    return q->head == NULL;
}

void print_queue(queue *q) {
    node *curr = q->head;
    while (curr != NULL) {
        data d;
        strcpy(d.value,curr->d.value);
        char *modifiedString = elab(curr->d.value);
        printf("Originale: [%s]\n", curr->d.value);
        strcpy(d.value,modifiedString);
        printf("Elaborato: %s\n", modifiedString);
        curr = curr->next;
        dequeue(q,&d);
    }
}


void enqueue(queue *q, data *d) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Errore nell'allocazione di memoria per il nodo\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->d.value, d->value);
    new_node->next = NULL;

    if (is_empty(q)) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void dequeue(queue *q, data *d) {
    if(is_empty(q))
        //return false;
        memcpy(d, &((q->head)->d), sizeof( data));
    node *tmp = q->head;
    (q->head) = tmp->next;

    free(tmp);
}

char random_char(input *in) {
    int range = in->b - in->a + 1;// b-a+1+a
    return in->a + (get_random() % range);
}

char *generate_random_string(char *str, int length, input *in) {
    for (int i = 0; i < length; i++) {
        str[i] = random_char(in);
    }
    str[length] = '\0';
    return str;
}

void build_queue(input *in, queue *q) {
    for (int i = 0; i < in->n; i++) {
        data new_data;
        int length = in->x + (get_random() % (in->y - in->x + 1));
        generate_random_string(new_data.value, length, in);
        printf("\nstring->%s\n",new_data.value);
        enqueue(q, &new_data);
    }
}

char *elab(char *string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (strchr("aeiouAEIOU", string[i])) {
            string[i] = 'X';
        }
    }
    return string;
}
