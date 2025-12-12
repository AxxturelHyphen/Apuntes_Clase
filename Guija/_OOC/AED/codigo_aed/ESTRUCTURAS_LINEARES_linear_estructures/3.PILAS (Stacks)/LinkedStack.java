/**
 * PILA CON LISTA ENLAZADA
 * Reutilizando `Node` de LinkedList.java
 */


class LinkedStack {
    private Node top;  // tope de la pila

    public LinkedStack() {
        top = null;
    }

    public void push(int val) {
        Node newNode = new Node(val);
        newNode.next = top;
        top = newNode;
    }

    public int pop() throws Exception {
        if (top == null) {
            throw new Exception("Stack underflow");
        }
        int val = top.data;
        top = top.next;
        return val;
    }

    public int peek() throws Exception {
        if (top == null) {
            throw new Exception("Stack underflow");
        }
        return top.data;
    }

    public boolean isEmpty() {
        return (top == null);
    }
}