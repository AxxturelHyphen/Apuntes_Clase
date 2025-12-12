/**
 * Pila con array de capacidad fija (traduccion de IntStack.java).
 * Ideal para ver la version "contigua" de una pila: O(1) en push/pop/peek.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;     // array donde guardamos los elementos
    int capacity;  // tamano maximo de la pila
    int top;       // indice del ultimo elemento; -1 si esta vacia
} IntStack;

// Reserva memoria para la pila y la deja vacia
static bool int_stack_init(IntStack *s, int capacity) {
    s->data = (int *)malloc(sizeof(int) * capacity);
    if (s->data == NULL) {
        fprintf(stderr, "Sin memoria para la pila\n");
        return false;
    }
    s->capacity = capacity;
    s->top = -1;  // sentinel que indica pila vacia
    return true;
}

// Libera la memoria asociada
static void int_stack_free(IntStack *s) {
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->top = -1;
}

// Inserta en la cima; devuelve false si hay overflow
static bool int_stack_push(IntStack *s, int value) {
    if (s->top + 1 == s->capacity) {
        return false;  // pila llena -> overflow
    }
    s->data[++(s->top)] = value;
    return true;
}

// Saca el elemento de la cima; false si underflow
static bool int_stack_pop(IntStack *s, int *out_value) {
    if (s->top < 0) {
        return false;  // pila vacia -> underflow
    }
    if (out_value != NULL) {
        *out_value = s->data[s->top];
    }
    s->top--;
    return true;
}

// Consulta el elemento de la cima sin quitarlo
static bool int_stack_peek(const IntStack *s, int *out_value) {
    if (s->top < 0) {
        return false;
    }
    if (out_value != NULL) {
        *out_value = s->data[s->top];
    }
    return true;
}

static bool int_stack_is_empty(const IntStack *s) {
    return s->top == -1;
}

int main(void) {
    IntStack stack;
    if (!int_stack_init(&stack, 5)) {
        return EXIT_FAILURE;
    }

    // push O(1)
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    // peek O(1)
    int top_value;
    if (int_stack_peek(&stack, &top_value)) {
        printf("Cima: %d\n", top_value);  // esperado: 20
    }

    // pop O(1)
    int popped;
    if (int_stack_pop(&stack, &popped)) {
        printf("Pop 1: %d\n", popped);  // esperado: 20
    }
    if (int_stack_pop(&stack, &popped)) {
        printf("Pop 2: %d\n", popped);  // esperado: 10
    }

    printf("Esta vacia? %s\n", int_stack_is_empty(&stack) ? "si" : "no");

    int_stack_free(&stack);
    return 0;
}
