/**
 * Cola circular basada en array.
 * Reutiliza el arreglo de forma circular con indices head/tail mod capacity,
 * evitando movimientos de datos y mostrando el esquema clasico de buffer circular.
 * @author AxxturelHyphen
 */
class CircularQueue {
    private int[] arr;
    private int capacity;
    private int head;
    private int tail;
    private int currentSize;

    /**
     * Crea una cola circular de capacidad fija.
     * @param N cantidad maxima de elementos encolados
     */
    CircularQueue(int N) {
        capacity = N;
        arr = new int[N];
        head = 0;
        tail = 0;
        currentSize = 0;
    }

    /**
     * Encola un valor al final de la cola.
     * @param value dato a guardar
     * @throws Exception si la cola esta llena
     */
    void enqueue(int value) throws Exception {
        if (currentSize == capacity) {
            throw new Exception("Queue overflow (full)");
        }
        arr[tail] = value;
        tail = (tail + 1) % capacity; // avanza circularmente
        currentSize++;
    }

    /**
     * Desencola y devuelve el elemento frontal.
     * @return valor almacenado en la posicion head
     * @throws Exception si la cola esta vacia
     */
    int dequeue() throws Exception {
        if (currentSize == 0) {
            throw new Exception("Queue underflow (empty)");
        }
        int value = arr[head];
        head = (head + 1) % capacity; // avanza circularmente
        currentSize--;
        return value;
    }

    /**
     * Devuelve el elemento frontal sin retirarlo.
     * @return valor en head
     * @throws Exception si la cola esta vacia
     */
    int peek() throws Exception {
        if (currentSize == 0) {
            throw new Exception("Empty queue");
        }
        return arr[head];
    }

    /** Indica si la cola no tiene elementos. */
    boolean isEmpty() {
        return currentSize == 0;
    }

    /** Indica si la cola alcanzo la capacidad declarada. */
    boolean isFull() {
        return currentSize == capacity;
    }

    static void main(){
        CircularQueue q = new CircularQueue(3);

        q.enqueue(10);
        q.enqueue(20);
        System.out.println(q.dequeue()); // 10

        q.enqueue(30);
        q.enqueue(40);

        System.out.println(q.dequeue()); // 20
        System.out.println(q.dequeue()); // 30
        System.out.println(q.isEmpty()); // false
        System.out.println(q.dequeue()); // 40
        System.out.println(q.isEmpty()); // true
    }
}
