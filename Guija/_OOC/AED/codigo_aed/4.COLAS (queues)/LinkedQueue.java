import java.util.LinkedList;
import java.util.Queue;

/**
 * Cola (queue) usando LinkedList como backing structure.
 * enqueue = add (lanza excepcion si falla).
 * dequeue = remove (lanza excepcion si la cola esta vacia).
 * Alternativas: offer() / poll() para evitar excepciones y devolver false/null.
 */
public class LinkedQueue {
    public static void main(String[] args) {
        Queue<String> cola = new LinkedList<>();

        cola.add("Juan"); // enqueue
        cola.add("Ana");

        System.out.println(cola.peek());   // "Juan" (front sin sacar)
        System.out.println(cola.remove()); // "Juan" (dequeue)
        System.out.println(cola.remove()); // "Ana"
        System.out.println(cola.isEmpty()); // true
    }
}
