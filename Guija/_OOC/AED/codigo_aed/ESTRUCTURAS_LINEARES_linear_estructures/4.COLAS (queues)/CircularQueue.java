/**
 * @author AxxturelHyphen
 */

class CircularQueue {
    private int[] arr;
    private int capacity;
    private int head;
    private int tail;
    private int currentSize;

    CircularQueue(int N) {
        capacity = N;
        arr = new int[N];
        head = 0;
        tail = 0;
        currentSize = 0;
    }

    void enqueue(int value) throws Exception {
        if (currentSize == capacity) {
            throw new Exception("Queue overflow (full)");
        }
        arr[tail] = value;
        tail = (tail + 1) % capacity;
        currentSize++;
    }

    int dequeue() throws Exception {
        if (currentSize == 0) {
            throw new Exception("Queue underflow (empty)");
        }
        int value = arr[head];
        head = (head + 1) % capacity;
        currentSize--;
        return value;
    }

    int peek() throws Exception {
        if (currentSize == 0) {
            throw new Exception("Empty queue");
        }
        return arr[head];
    }

    boolean isEmpty() {
        return currentSize == 0;
    }

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