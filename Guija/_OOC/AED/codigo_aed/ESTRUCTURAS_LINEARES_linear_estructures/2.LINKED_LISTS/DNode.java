/**
 * Doubly linked list:
 * prev y next.
 * Más memoria, pero eliminar un nodo dado es O(1) sin buscar el anterior.
 * Más fácil recorrer hacia atrás.
 */
/// @author AxxturelHyphen


static class DNode {
    int data;
    DNode prev; //nodo anterior
    DNode next; //nodo siguiente

    DNode(int d) {
        data = d;
        prev = next = null;
    }
    DNode head = null;
    DNode tail = null;

    /// Insertar al final usando tail
    void addLast(int value) {
        DNode newNode = new DNode(value);

        if (tail == null) { // lista vacía
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }
    /// Eliminar un nodo 'node' de una lista doblemente enlazada
    void removeNode(DNode node) {
        if (node == null) return;

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
} static void main(){}
