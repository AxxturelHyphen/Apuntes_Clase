/**
 * Cola (queue) usando lista enlazada simple.
 * enqueue = push back; dequeue = pop front. Operaciones O(1).
 * En Java puedes usar offer()/poll() para evitar excepciones y devolver false/null.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    const char *data;
    struct Node *next;
} Node;

typedef struct {
    Node *front; // cabeza (quien se atiende primero)
    Node *rear;  // cola (donde encolamos nuevo)
} LinkedQueue;

static void lq_init(LinkedQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

static bool lq_is_empty(const LinkedQueue *q) {
    return q->front == NULL;
}

// enqueue: insertar al final
static bool lq_enqueue(LinkedQueue *q, const char *value) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "Sin memoria para enqueue\n");
        return false;
    }
    n->data = value;
    n->next = NULL;

    if (q->rear == NULL) {
        // cola vacia: front y rear apuntan al nuevo
        q->front = q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
    return true;
}

// dequeue: saca front; devuelve false si underflow
static bool lq_dequeue(LinkedQueue *q, const char **out_value) {
    if (q->front == NULL) {
        return false;
    }
    Node *tmp = q->front;
    if (out_value != NULL) {
        *out_value = tmp->data;
    }
    q->front = tmp->next;
    if (q->front == NULL) {
        // si quitamos el ultimo, rear tambien se vacia
        q->rear = NULL;
    }
    free(tmp);
    return true;
}

// peek: mira el front sin sacarlo
static bool lq_peek(const LinkedQueue *q, const char **out_value) {
    if (q->front == NULL) {
        return false;
    }
    if (out_value != NULL) {
        *out_value = q->front->data;
    }
    return true;
}

static void lq_clear(LinkedQueue *q) {
    const char *dummy;
    while (lq_dequeue(q, &dummy)) {
        // vaciar todos los nodos
    }
}

int main(void) {
    LinkedQueue cola;
    lq_init(&cola);

    lq_enqueue(&cola, "Juan"); // enqueue
    lq_enqueue(&cola, "Ana");

    const char *valor;
    if (lq_peek(&cola, &valor)) {
        printf("peek: %s\n", valor); // "Juan"
    }
    if (lq_dequeue(&cola, &valor)) {
        printf("dequeue 1: %s\n", valor); // "Juan"
    }
    if (lq_dequeue(&cola, &valor)) {
        printf("dequeue 2: %s\n", valor); // "Ana"
    }
    printf("isEmpty? %s\n", lq_is_empty(&cola) ? "true" : "false");

    lq_clear(&cola);
    return 0;
}
