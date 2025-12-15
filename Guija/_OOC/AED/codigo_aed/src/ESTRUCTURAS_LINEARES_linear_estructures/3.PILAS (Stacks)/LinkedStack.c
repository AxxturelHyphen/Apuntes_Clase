/**
 * Pila implementada con lista enlazada (traduccion de LinkedStack.java).
 * Cada push/pop solo toca head: operaciones O(1) sin limite de capacidad
 * (mas alla de la memoria disponible).
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;  // puntero al nodo que representa la cima
} LinkedStack;

// Crea un nodo nuevo (helper interno)
static Node *create_node(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "Sin memoria para nodo\n");
        exit(EXIT_FAILURE);  // parar: no hay como continuar
    }
    n->data = value;
    n->next = NULL;
    return n;
}

static void linked_stack_init(LinkedStack *s) {
    s->top = NULL;
}

static bool linked_stack_is_empty(const LinkedStack *s) {
    return s->top == NULL;
}

// push: enlaza el nuevo nodo por delante
static void linked_stack_push(LinkedStack *s, int value) {
    Node *n = create_node(value);
    n->next = s->top;
    s->top = n;
}

// pop: extrae el nodo de la cabeza; devuelve false si underflow
static bool linked_stack_pop(LinkedStack *s, int *out_value) {
    if (s->top == NULL) {
        return false;
    }
    Node *tmp = s->top;
    if (out_value != NULL) {
        *out_value = tmp->data;
    }
    s->top = tmp->next;
    free(tmp);
    return true;
}

// peek: lee la cima sin quitarla
static bool linked_stack_peek(const LinkedStack *s, int *out_value) {
    if (s->top == NULL) {
        return false;
    }
    if (out_value != NULL) {
        *out_value = s->top->data;
    }
    return true;
}

// Borra todos los nodos (evita fugas de memoria)
static void linked_stack_clear(LinkedStack *s) {
    int dummy;
    while (linked_stack_pop(s, &dummy)) {
        // pop ya libera nodos; el valor no importa
    }
}

int main(void) {
    LinkedStack stack;
    linked_stack_init(&stack);

    linked_stack_push(&stack, 1);
    linked_stack_push(&stack, 2);
    linked_stack_push(&stack, 3);

    int top_value;
    if (linked_stack_peek(&stack, &top_value)) {
        printf("Cima: %d\n", top_value);  // esperado: 3
    }

    int popped;
    linked_stack_pop(&stack, &popped);
    printf("Pop 1: %d\n", popped);  // 3
    linked_stack_pop(&stack, &popped);
    printf("Pop 2: %d\n", popped);  // 2
    linked_stack_pop(&stack, &popped);
    printf("Pop 3: %d\n", popped);  // 1

    printf("Esta vacia? %s\n", linked_stack_is_empty(&stack) ? "si" : "no");

    linked_stack_clear(&stack);
    return 0;
}
