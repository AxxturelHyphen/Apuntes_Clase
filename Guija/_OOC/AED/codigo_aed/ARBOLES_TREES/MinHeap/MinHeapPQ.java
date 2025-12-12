/**
 * Min-heap (priority queue) implementado con ArrayList.
 * complete binary tree + heap property (parent <= children).
 * Operaciones: peek/insert/extractMin en O(log n), peek O(1).
 * @author AxxturelHyphen
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;

public class MinHeapPQ {
    private final ArrayList<Integer> heap = new ArrayList<>();

    public boolean isEmpty() {
        return heap.isEmpty();
    }

    public int size() {
        return heap.size();
    }

    // Peek min (root) O(1)
    public int peek() {
        if (heap.isEmpty()) throw new NoSuchElementException("Heap vacio");
        return heap.get(0);
    }

    // Insert O(log n) usando sift-up
    public void insert(int value) {
        heap.add(value);
        siftUp(heap.size() - 1);
    }

    // Extract-min O(log n) usando sift-down
    public int extractMin() {
        if (heap.isEmpty()) throw new NoSuchElementException("Heap vacio");
        int min = heap.get(0);
        int lastIndex = heap.size() - 1;
        Collections.swap(heap, 0, lastIndex);
        heap.remove(lastIndex);
        if (!heap.isEmpty()) {
            siftDown(0);
        }
        return min;
    }

    private void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap.get(parent) <= heap.get(i)) break; // already ok
            Collections.swap(heap, parent, i);
            i = parent;
        }
    }

    private void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap.get(left) < heap.get(smallest)) smallest = left;
            if (right < n && heap.get(right) < heap.get(smallest)) smallest = right;

            if (smallest == i) break;
            Collections.swap(heap, i, smallest);
            i = smallest;
        }
    }

    public static void main(String[] args) {
        MinHeapPQ heap = new MinHeapPQ();
        int[] vals = {5, 3, 8, 1, 6};
        for (int v : vals) heap.insert(v);

        System.out.println("peek (min): " + heap.peek()); // 1
        while (!heap.isEmpty()) {
            System.out.println("extract: " + heap.extractMin());
        }
    }
}
