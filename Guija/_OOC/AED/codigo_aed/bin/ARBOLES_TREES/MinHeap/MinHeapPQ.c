/**
 * Min-heap (priority queue) usando array dinamico.
 * Operaciones: peek O(1), insert O(log n) con sift-up, extract_min O(log n) con sift-down.
 * Heap property: parent <= children (min-heap).
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

static bool heap_init(MinHeap *h, int initial_capacity) {
    h->data = (int *)malloc(sizeof(int) * initial_capacity);
    if (!h->data) {
        fprintf(stderr, "No hay memoria para heap\n");
        return false;
    }
    h->size = 0;
    h->capacity = initial_capacity;
    return true;
}

static void heap_free(MinHeap *h) {
    free(h->data);
    h->data = NULL;
    h->size = 0;
    h->capacity = 0;
}

static bool heap_ensure_capacity(MinHeap *h) {
    if (h->size < h->capacity) return true;
    int new_cap = (h->capacity == 0) ? 2 : h->capacity * 2;
    int *tmp = (int *)realloc(h->data, sizeof(int) * new_cap);
    if (!tmp) {
        fprintf(stderr, "No hay memoria para resize\n");
        return false;
    }
    h->data = tmp;
    h->capacity = new_cap;
    return true;
}

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// sift-up para restaurar min-heap despues de insertar
static void sift_up(MinHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent] <= h->data[idx]) break;
        swap(&h->data[parent], &h->data[idx]);
        idx = parent;
    }
}

// sift-down para restaurar tras extraer
static void sift_down(MinHeap *h, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        if (left < h->size && h->data[left] < h->data[smallest]) smallest = left;
        if (right < h->size && h->data[right] < h->data[smallest]) smallest = right;
        if (smallest == idx) break;
        swap(&h->data[idx], &h->data[smallest]);
        idx = smallest;
    }
}

static bool heap_insert(MinHeap *h, int value) {
    if (!heap_ensure_capacity(h)) return false;
    h->data[h->size] = value;
    sift_up(h, h->size);
    h->size++;
    return true;
}

static bool heap_peek(const MinHeap *h, int *out) {
    if (h->size == 0) return false;
    if (out) *out = h->data[0];
    return true;
}

static bool heap_extract_min(MinHeap *h, int *out) {
    if (h->size == 0) return false;
    if (out) *out = h->data[0];
    h->size--;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        sift_down(h, 0);
    }
    return true;
}

static bool heap_is_empty(const MinHeap *h) {
    return h->size == 0;
}

int main(void) {
    MinHeap heap;
    if (!heap_init(&heap, 4)) {
        return EXIT_FAILURE;
    }

    int vals[] = {5, 3, 8, 1, 6};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    for (int i = 0; i < n; ++i) {
        heap_insert(&heap, vals[i]);
    }

    int top;
    if (heap_peek(&heap, &top)) {
        printf("peek (min): %d\n", top);
    }

    while (!heap_is_empty(&heap)) {
        int x;
        heap_extract_min(&heap, &x);
        printf("extract: %d\n", x);
    }

    heap_free(&heap);
    return 0;
}
