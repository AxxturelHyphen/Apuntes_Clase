/**
 * Circular linked list:
 * Ultimo nodo apunta al primero.
 * Util en rondas ciclicas, buffers circulares.
 * Cuidado con bucles infinitos.
 * @author AxxturelHyphen
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CircularNode
{
    int data;                  // dato de cada nodo
    struct CircularNode *next; // puntero al siguiente nodo
} CircularNode;

static CircularNode *create_node(int data)
{
    CircularNode *n = (CircularNode *)malloc(sizeof(CircularNode));
    if (!n)
    {
        fprintf(stderr, "Sin memoria para nuevo nodo\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

// Imprime UNA VUELTA al circulo para evitar bucles infinitos
static void print_circular(const CircularNode *head)
{
    if (head == NULL)
        return;
    const CircularNode *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Busca el tail (ultimo nodo cuyo next apunta a head)
static CircularNode *find_tail(CircularNode *head)
{
    if (head == NULL)
        return NULL;
    CircularNode *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    return tail;
}

// Insertar al inicio (push_front)
static void push_front(CircularNode **head_ref, int value)
{
    CircularNode *new_node = create_node(value);
    if (*head_ref == NULL)
    {
        new_node->next = new_node; // se apunta a si mismo
        *head_ref = new_node;
        return;
    }
    CircularNode *tail = find_tail(*head_ref);
    new_node->next = *head_ref; // nuevo apunta al antiguo head
    tail->next = new_node;      // el ultimo ahora apunta al nuevo
    *head_ref = new_node;       // actualizamos head
}

// Eliminar el primer nodo (pop_front)
static void pop_front(CircularNode **head_ref)
{
    CircularNode *head = *head_ref;
    if (head == NULL)
        return;

    // si solo hay un nodo (apunta a si mismo)
    if (head->next == head)
    {
        free(head);
        *head_ref = NULL;
        return;
    }

    // recalcular tail
    CircularNode *tail = find_tail(head);
    CircularNode *new_head = head->next; // nuevo primer nodo
    tail->next = new_head;               // cerramos el circulo
    free(head);
    *head_ref = new_head;
}

// Insertar despues del primer nodo que contenga target
static void insert_after_value(CircularNode *head, int target, int value)
{
    if (head == NULL)
        return;
    CircularNode *current = head;
    do
    {
        if (current->data == target)
        {
            CircularNode *node15 = create_node(value);
            node15->next = current->next;
            current->next = node15;
            return; // dejamos de buscar
        }
        current = current->next;
    } while (current != head);
}

static void free_circular(CircularNode **head_ref)
{
    CircularNode *head = *head_ref;
    if (head == NULL)
        return;
    CircularNode *current = head->next;
    while (current != head)
    {
        CircularNode *next = current->next;
        free(current);
        current = next;
    }
    free(head);
    *head_ref = NULL;
}

int main(void)
{
    // Construir manualmente una lista circular [10 -> 20 -> 30 -> vuelve a 10]
    CircularNode *head = create_node(10);   // primer nodo
    CircularNode *second = create_node(20); // segundo nodo
    CircularNode *third = create_node(30);  // tercer nodo

    head->next = second;
    second->next = third;
    third->next = head; // cierre del circulo

    // Recorrer e imprimir UNA VUELTA al circulo
    print_circular(head); // Salida: 10 20 30

    /**
     * Insertar al inicio (push_front) valor 5
     * Resultado esperado: [5 -> 10 -> 20 -> 30 -> vuelve a 5]
     */
    push_front(&head, 5);

    /**
     * Eliminar el primer nodo (pop_front)
     * Casos:
     *  - lista con un solo nodo
     *  - lista con varios nodos
     */
    pop_front(&head);

    /**
     * Insertar 15 despues del nodo con valor 10
     * Resultado final esperado (si existia 10):
     * [10 -> 15 -> 20 -> 30 -> vuelve a 10]
     */
    insert_after_value(head, 10, 15);

    // Recorrer e imprimir de nuevo la lista circular resultante
    print_circular(head);
    // Lista: [10 -> 15 -> 20 -> 30 -> vuelve a 10]

    free_circular(&head);
    return 0;
}
