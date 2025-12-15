/**
 * Pila implementada con nodos enlazados.
 * Usa la clase {@link Node} de las listas enlazadas: cada push agrega al frente,
 * y pop/peek leen el tope apuntado por {@code top}. Ideal para ver la version
 * dinamica de una pila (sin capacidad fija).
 * @author AxxturelHyphen
 */
class LinkedStack {
    private Node top;  // referencia al tope de la pila

    public LinkedStack() {
        top = null;
    }

    /**
     * Inserta un elemento al tope de la pila.
     * @param val dato a guardar
     */
    public void push(int val) {
        Node newNode = new Node(val);
        newNode.next = top;
        top = newNode;
    }

    /**
     * Extrae el nodo del tope y devuelve su valor.
     * @return valor almacenado en el tope
     * @throws Exception si la pila esta vacia
     */
    public int pop() throws Exception {
        if (top == null) {
            throw new Exception("Stack underflow");
        }
        int val = top.data;
        top = top.next;
        return val;
    }

    /**
     * Consulta el valor del tope sin modificar la pila.
     * @return valor del nodo en el tope
     * @throws Exception si la pila esta vacia
     */
    public int peek() throws Exception {
        if (top == null) {
            throw new Exception("Stack underflow");
        }
        return top.data;
    }

    /**
     * Indica si no hay nodos apilados.
     */
    public boolean isEmpty() {
        return (top == null);
    }
}
