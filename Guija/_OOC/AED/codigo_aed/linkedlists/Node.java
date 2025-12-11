package org.example.estructuras_lineales.linkedlists;

/**
 * Singly linked list:
 * Solo next.
 * Menos memoria, más sencilla.
 * Para eliminar un nodo necesitas referencia al anterior (o buscarlo).
 */
/// @author AxxturelHyphen
class Node {
    int data; // dato de cada nodo
    Node next; // puntero que apunta al siguiente nodo

    Node(int data) {
        this.data = data;
        this.next = null;
    }

    static void main() {

        // Construir manualmente una lista [10 -> 20 -> 30]
        Node head = new Node(10); //primer nodo
        head.next = new Node(20); //segundo nodo
        head.next.next = new Node(30); //tercer nodo

        // Recorrer e imprimir
        Node current = head;
        while (current != null) {
            System.out.println(current.data);
            current = current.next;
        }
        //Salida: 10 \n20 \n30

        /**
         * Insertar al inicio (push_front) valor 5
         */
        Node newNode = new Node(5);
        newNode.next = head;   // el nuevo nodo apunta al antiguo primero
        head = newNode;      // head ahora es el nuevo nodo
        ///Lista resultante: [5 -> 10 -> 20 -> 30]

        /// Eliminar el priemr nodo (pop_front)
        if (head != null){
            head = head.next;
        }
        /// Insertar 15 despues del nodo con valor 10
        current = head;
        // Buscar el nodo con data == 10
        while (current != null && current.data != 10) {
            current = current.next;
        }

        if (current != null) {
            newNode = new Node(15);
            newNode.next = current.next;
            current.next = newNode;
        }
    }///Lista: [5 -> 10 -> 15 -> 20 -> 30]
}
