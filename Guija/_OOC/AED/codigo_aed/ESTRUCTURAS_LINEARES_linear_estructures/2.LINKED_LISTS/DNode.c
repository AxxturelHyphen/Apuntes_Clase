/**
 * Doubly linked list:
 * prev y next.
 * Mas memoria, pero eliminar un nodo dado es O(1) sin buscar el anterior.
 * Mas facil recorrer hacia atras.
 * @author AxxturelHyphen
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev; // nodo anterior
    struct DNode *next; // nodo siguiente
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
} DoublyList;

static DNode *create_dnode(int value) {
    DNode *n = (DNode *)malloc(sizeof(DNode));
    if (!n) {
        fprintf(stderr, "Sin memoria para nuevo nodo\n");
        exit(EXIT_FAILURE);
    }
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/// Insertar al final usando tail
static void add_last(DoublyList *list, int value) {
    DNode *new_node = create_dnode(value);

    if (list->tail == NULL) { // lista vacia
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
}

/// Eliminar un nodo 'node' de una lista doblemente enlazada
static void remove_node(DoublyList *list, DNode *node) {
    if (node == NULL) return;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;   // node era la cabeza
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;   // node era la cola
    }
    free(node);
}

static DNode *find_by_value(DoublyList *list, int value) {
    DNode *current = list->head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    return current;
}

static void print_forward(const DoublyList *list) {
    const DNode *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

static void print_backward(const DoublyList *list) {
    const DNode *current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

static void free_list(DoublyList *list) {
    DNode *current = list->head;
    while (current != NULL) {
        DNode *next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
}

int main(void) {
    DoublyList list = {0};

    add_last(&list, 10);
    add_last(&list, 20);
    add_last(&list, 30);
    // Lista: 10 20 30
    print_forward(&list);
    print_backward(&list);

    /// Eliminar el nodo con valor 20
    DNode *middle = find_by_value(&list, 20);
    remove_node(&list, middle);
    // Lista: 10 30
    print_forward(&list);
    print_backward(&list);

    free_list(&list);
    return 0;
}
