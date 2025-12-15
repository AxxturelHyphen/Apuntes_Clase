import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * PriorityQueue en Java:
 * - Por defecto es min-heap (el menor sale primero).
 * - Para max-heap usamos un Comparator que invierte la prioridad.
 * - Operaciones clave: add/offer, poll/remove, peek; offer/poll devuelven false/null en vez de lanzar excepcion.
 * @author AxxturelHyphen
 */
public class PriorityQueue {
    // Pequeno record de tarea con prioridad entera
    static class Task {
        String name;
        int priority;

        Task(String name, int priority) {
            this.name = name;
            this.priority = priority;
        }

        @Override
        public String toString() {
            return name + "(pri=" + priority + ")";
        }
    }

    public static void main(String[] args) {
        // max-heap: prioridad mas alta primero
        PriorityQueue<Task> pq =
                new PriorityQueue<>(Comparator.comparingInt(t -> -t.priority));

        pq.add(new Task("TareaA", 3));
        pq.add(new Task("TareaB", 5));
        pq.add(new Task("TareaC", 1));

        System.out.println(pq.peek()); // front sin quitar (mayor prioridad)

        while (!pq.isEmpty()) {
            System.out.println(pq.poll()); // poll devuelve null si vacia (no lanza excepcion)
        }
    }
}
