/**
 * Priority queue (max-heap) en C.
 * - insert: O(log n) con bubble-up.
 * - extract_max: O(log n) con bubble-down.
 * - peek: O(1).
 * Esta version usa array dinamico para el heap.
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *name;
    int priority;
} Task;

typedef struct {
    Task *data;
    int size;
    int capacity;
} MaxHeap;

static bool heap_init(MaxHeap *h, int initial_capacity) {
    h->data = (Task *)malloc(sizeof(Task) * initial_capacity);
    if (h->data == NULL) {
        fprintf(stderr, "No hay memoria para heap\n");
        return false;
    }
    h->size = 0;
    h->capacity = initial_capacity;
    return true;
}

// Asegura espacio; duplica capacidad si hace falta
static bool heap_ensure_capacity(MaxHeap *h) {
    if (h->size < h->capacity) {
        return true;
    }
    int new_capacity = (h->capacity == 0) ? 2 : h->capacity * 2;
    Task *tmp = (Task *)realloc(h->data, sizeof(Task) * new_capacity);
    if (tmp == NULL) {
        fprintf(stderr, "No hay memoria para resize\n");
        return false;
    }
    h->data = tmp;
    h->capacity = new_capacity;
    return true;
}

static void heap_swap(Task *a, Task *b) {
    Task tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubble-up para restaurar propiedad de max-heap
static void heap_bubble_up(MaxHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent].priority >= h->data[idx].priority) {
            break;
        }
        heap_swap(&h->data[parent], &h->data[idx]);
        idx = parent;
    }
}

// Bubble-down para restaurar propiedad tras extraer
static void heap_bubble_down(MaxHeap *h, int idx) {
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;

        if (left < h->size && h->data[left].priority > h->data[largest].priority) {
            largest = left;
        }
        if (right < h->size && h->data[right].priority > h->data[largest].priority) {
            largest = right;
        }
        if (largest == idx) {
            break;
        }
        heap_swap(&h->data[idx], &h->data[largest]);
        idx = largest;
    }
}

// insert O(log n)
static bool heap_insert(MaxHeap *h, const char *name, int priority) {
    if (!heap_ensure_capacity(h)) {
        return false;
    }
    h->data[h->size].name = name;
    h->data[h->size].priority = priority;
    heap_bubble_up(h, h->size);
    h->size++;
    return true;
}

// peek O(1); false si vacio
static bool heap_peek(const MaxHeap *h, Task *out_task) {
    if (h->size == 0) {
        return false;
    }
    if (out_task != NULL) {
        *out_task = h->data[0];
    }
    return true;
}

// extract_max O(log n); false si vacio
static bool heap_extract_max(MaxHeap *h, Task *out_task) {
    if (h->size == 0) {
        return false;
    }
    if (out_task != NULL) {
        *out_task = h->data[0];
    }
    h->size--;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        heap_bubble_down(h, 0);
    }
    return true;
}

static bool heap_is_empty(const MaxHeap *h) {
    return h->size == 0;
}

static void heap_free(MaxHeap *h) {
    free(h->data);
    h->data = NULL;
    h->size = 0;
    h->capacity = 0;
}

int main(void) {
    MaxHeap heap;
    if (!heap_init(&heap, 4)) {
        return EXIT_FAILURE;
    }

    heap_insert(&heap, "TareaA", 3);
    heap_insert(&heap, "TareaB", 5);
    heap_insert(&heap, "TareaC", 1);

    Task t;
    if (heap_peek(&heap, &t)) {
        printf("peek => %s(pri=%d)\n", t.name, t.priority); // expected: TareaB(pri=5)
    }

    while (!heap_is_empty(&heap)) {
        heap_extract_max(&heap, &t);
        printf("poll => %s(pri=%d)\n", t.name, t.priority);
    }

    heap_free(&heap);
    return 0;
}
