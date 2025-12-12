package org.example.estructuras_lineales.linkedlists;
/**
 * Circular linked list:
 * Último nodo apunta al primero.
 * Útil en rondas cíclicas, buffers circulares.
 * Cuidado con bucles infinitos.
 */

/// @author AxxturelHyphen

class CircularNode {
    int data;          // dato de cada nodo
    CircularNode next; // puntero al siguiente nodo

    CircularNode(int data) {
        this.data = data;
        this.next = null;
    }

    static void main() {

        // Construir manualmente una lista circular [10 -> 20 -> 30 -> vuelve a 10]
        CircularNode head = new CircularNode(10);      // primer nodo
        CircularNode second = new CircularNode(20);    // segundo nodo
        CircularNode third = new CircularNode(30);     // tercer nodo

        head.next = second;
        second.next = third;
        third.next = head; // cierre del círculo

        // Recorrer e imprimir UNA VUELTA al círculo
        CircularNode current = head;
        if (head != null) {
            do {
                System.out.println(current.data);
                current = current.next;
            } while (current != head);
        }
        // Salida: 10 \n20 \n30

        /**
         * Insertar al inicio (push_front) valor 5
         * Resultado esperado: [5 -> 10 -> 20 -> 30 -> vuelve a 5]
         */
        CircularNode newNode = new CircularNode(5);

        // Buscar el "tail" (último nodo, cuyo next apunta a head)
        CircularNode tail = head;
        while (tail.next != head) {
            tail = tail.next;
        }

        newNode.next = head; // nuevo apunta al antiguo head
        tail.next = newNode; // el último ahora apunta al nuevo
        head = newNode;      // actualizamos head

        /**
         * Eliminar el primer nodo (pop_front)
         * Casos:
         *  - lista con un solo nodo
         *  - lista con varios nodos
         */
        if (head != null) {
            // si solo hay un nodo (apunta a sí mismo)
            if (head.next == head) {
                head = null;
            } else {
                // recalcular tail
                tail = head;
                while (tail.next != head) {
                    tail = tail.next;
                }
                head = head.next;  // nuevo primer nodo
                tail.next = head;  // cerramos el círculo
            }
        }

        /**
         * Insertar 15 después del nodo con valor 10
         * Resultado final esperado (si existía 10):
         * [5 -> 10 -> 15 -> 20 -> 30 -> vuelve a 5]
         */
        if (head != null) {
            current = head;
            do {
                if (current.data == 10) {
                    CircularNode node15 = new CircularNode(15);
                    node15.next = current.next;
                    current.next = node15;
                    break; // dejamos de buscar
                }
                current = current.next;
            } while (current != head);
        }

        // Recorrer e imprimir de nuevo la lista circular resultante
        if (head != null) {
            current = head;
            do {
                System.out.println(current.data);
                current = current.next;
            } while (current != head);
        }
        // Lista: [5 -> 10 -> 15 -> 20 -> 30 -> vuelve a 5]
    }
}
