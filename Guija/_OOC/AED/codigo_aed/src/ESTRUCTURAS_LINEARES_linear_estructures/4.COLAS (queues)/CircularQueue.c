/**
 * Implementacion de cola circular con arreglo.
 * Mantiene head, tail y tamano actual para O(1) en encolar/desencolar.
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int head;
    int tail;
    int current_size;
} CircularQueue;

static CircularQueue *create_queue(int capacity) {
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!q) {
        fprintf(stderr, "Sin memoria para la cola\n");
        exit(EXIT_FAILURE);
    }
    q->arr = (int *)malloc(sizeof(int) * capacity);
    if (!q->arr) {
        fprintf(stderr, "Sin memoria para el arreglo de la cola\n");
        free(q);
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->head = 0;
    q->tail = 0;
    q->current_size = 0;
    return q;
}

static bool is_empty(const CircularQueue *q) {
    return q->current_size == 0;
}

static bool is_full(const CircularQueue *q) {
    return q->current_size == q->capacity;
}

static bool enqueue(CircularQueue *q, int value) {
    if (is_full(q)) {
        return false; // overflow
    }
    q->arr[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->current_size++;
    return true;
}

static bool dequeue(CircularQueue *q, int *out_value) {
    if (is_empty(q)) {
        return false; // underflow
    }
    *out_value = q->arr[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->current_size--;
    return true;
}

static bool peek(const CircularQueue *q, int *out_value) {
    if (is_empty(q)) {
        return false;
    }
    *out_value = q->arr[q->head];
    return true;
}

static void free_queue(CircularQueue *q) {
    if (q) {
        free(q->arr);
        free(q);
    }
}

int main(void) {
    CircularQueue *q = create_queue(3);

    enqueue(q, 10);
    enqueue(q, 20);

    int value = 0;
    if (dequeue(q, &value)) {
        printf("%d\n", value); // 10
    }

    enqueue(q, 30);
    enqueue(q, 40); // ahora esta llena

    if (dequeue(q, &value)) printf("%d\n", value); // 20
    if (dequeue(q, &value)) printf("%d\n", value); // 30
    printf("%s\n", is_empty(q) ? "true" : "false"); // false
    if (dequeue(q, &value)) printf("%d\n", value); // 40
    printf("%s\n", is_empty(q) ? "true" : "false"); // true

    // peek de ejemplo
    enqueue(q, 50);
    if (peek(q, &value)) {
        printf("Front: %d\n", value);
    }

    free_queue(q);
    return 0;
}
