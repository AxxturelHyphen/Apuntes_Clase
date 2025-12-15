/**
 * Doubly linked list:
 * prev y next.
 * Mas memoria, pero eliminar un nodo dado es O(1) sin buscar el anterior.
 * Mas facil recorrer hacia atras.
 */
/// @author AxxturelHyphen
public class DNode {
    int data;
    DNode prev; // nodo anterior
    DNode next; // nodo siguiente

    DNode(int d) {
        data = d;
        prev = next = null;
    }

    /** Lista doblemente enlazada con punteros a head/tail. */
    static class DoublyLinkedList {
        DNode head = null;
        DNode tail = null;

        /** Insertar al final usando tail. */
        void addLast(int value) {
            DNode newNode = new DNode(value);

            if (tail == null) { // lista vacia
                head = tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }

        /** Eliminar un nodo 'node' de una lista doblemente enlazada. */
        void removeNode(DNode node) {
            if (node == null) {
                return;
            }

            if (node.prev != null) {
                node.prev.next = node.next;
            } else {
                head = node.next;   // node era la cabeza
            }

            if (node.next != null) {
                node.next.prev = node.prev;
            } else {
                tail = node.prev;   // node era la cola
            }
        }

        void printForward() {
            DNode current = head;
            while (current != null) {
                System.out.println(current.data);
                current = current.next;
            }
        }
    }

    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);

        System.out.println("Lista original:");
        list.printForward();

        // eliminar el nodo central (valor 2) para mostrar que no hay que buscar el anterior
        list.removeNode(list.head.next);

        System.out.println("Despues de quitar el nodo central:");
        list.printForward();
    }
}
