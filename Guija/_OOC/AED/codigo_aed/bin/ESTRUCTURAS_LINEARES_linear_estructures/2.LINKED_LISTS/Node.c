/**
 * Singly linked list:
 * Solo next.
 * Menos memoria, mas sencilla.
 * Para eliminar un nodo necesitas referencia al anterior (o buscarlo).
 * @author AxxturelHyphen
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;            // dato de cada nodo
    struct Node *next;   // puntero que apunta al siguiente nodo
} Node;

// Crea un nuevo nodo con el valor dado
static Node *create_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Sin memoria para nuevo nodo\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

// Imprime la lista enlazada de forma lineal
static void print_list(const Node *head) {
    const Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Inserta un valor al inicio (push_front)
static void push_front(Node **head, int value) {
    Node *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

// Elimina el primer nodo (pop_front) si existe
static void pop_front(Node **head) {
    if (*head != NULL) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

// Inserta un valor despues del primer nodo que contenga target
static void insert_after_value(Node *head, int target, int value) {
    Node *current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current != NULL) {
        Node *new_node = create_node(value);
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main(void) {
    // Construir manualmente una lista [10 -> 20 -> 30]
    Node *head = create_node(10);       // primer nodo
    head->next = create_node(20);       // segundo nodo
    head->next->next = create_node(30); // tercer nodo

    // Recorrer e imprimir
    print_list(head); // Salida: 10 20 30

    /**
     * Insertar al inicio (push_front) valor 5
     */
    push_front(&head, 5);
    // Lista resultante: [5 -> 10 -> 20 -> 30]

    /// Eliminar el primer nodo (pop_front)
    pop_front(&head);
    // Lista: [10 -> 20 -> 30]

    /// Insertar 15 despues del nodo con valor 10
    insert_after_value(head, 10, 15);
    // Lista: [10 -> 15 -> 20 -> 30]

    print_list(head);

    // Liberar nodos restantes
    while (head != NULL) {
        pop_front(&head);
    }
    return 0;
}
