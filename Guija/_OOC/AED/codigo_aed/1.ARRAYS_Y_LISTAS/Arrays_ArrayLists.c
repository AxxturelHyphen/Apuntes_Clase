/**
 * Demo en C de "array fijo" y "ArrayList-like" dinamico (traduccion de Arrays_ArrayLists.java).
 * array = size fijo y acceso O(1) via index.
 * dynamic array (ArrayList style) = resize interno y add/remove que reacomodan.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Implementacion simple de ArrayList para strings (usa punteros a literales)
typedef struct {
    const char **data; // punteros a strings
    int size;          // cantidad de elementos usados
    int capacity;      // espacio reservado
} StringArrayList;

static bool sal_init(StringArrayList *list, int initial_capacity) {
    list->data = (const char **)malloc(sizeof(char *) * initial_capacity);
    if (list->data == NULL) {
        fprintf(stderr, "No hay memoria para la lista\n");
        return false;
    }
    list->size = 0;
    list->capacity = initial_capacity;
    return true;
}

// Duplica capacidad cuando hace falta (tipico resize amortizado)
static bool sal_ensure_capacity(StringArrayList *list) {
    if (list->size < list->capacity) {
        return true;
    }
    int new_capacity = (list->capacity == 0) ? 2 : list->capacity * 2;
    const char **tmp = (const char **)realloc(list->data, sizeof(char *) * new_capacity);
    if (tmp == NULL) {
        fprintf(stderr, "Resize failed: sin memoria\n");
        return false;
    }
    list->data = tmp;
    list->capacity = new_capacity;
    return true;
}

// add al final O(1) amortizado
static bool sal_add(StringArrayList *list, const char *value) {
    if (!sal_ensure_capacity(list)) {
        return false;
    }
    list->data[list->size++] = value;
    return true;
}

// get O(1) con bounds check
static bool sal_get(const StringArrayList *list, int index, const char **out_value) {
    if (index < 0 || index >= list->size) {
        return false;
    }
    if (out_value != NULL) {
        *out_value = list->data[index];
    }
    return true;
}

// remove por index: O(n) por el shift (igual que ArrayList)
static bool sal_remove(StringArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        return false;
    }
    for (int i = index; i < list->size - 1; ++i) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return true;
}

static void sal_print(const StringArrayList *list) {
    printf("[");
    for (int i = 0; i < list->size; ++i) {
        printf("%s", list->data[i]);
        if (i + 1 < list->size) {
            printf(", ");
        }
    }
    printf("]\n");
}

static void sal_free(StringArrayList *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

int main(void) {
    // Array fijo: tamano 5, acceso O(1) via index
    int numeros[5] = {0};
    numeros[0] = 42;
    numeros[1] = 13;

    printf("numeros[0] = %d\n", numeros[0]); // imprime 42

    int idx = 1;
    printf("numeros[%d] = %d\n", idx, numeros[idx]); // imprime 13

    // ArrayList-like dinamica para strings
    StringArrayList nombres;
    if (!sal_init(&nombres, 2)) {
        return EXIT_FAILURE;
    }

    sal_add(&nombres, "Ana");
    sal_add(&nombres, "Juan");
    sal_add(&nombres, "Luis");

    const char *valor;
    if (sal_get(&nombres, 1, &valor)) {
        printf("get(1) => %s\n", valor); // esperado: Juan
    }

    sal_remove(&nombres, 0); // remove desplaza: quedan [Juan, Luis]
    printf("Lista tras remove(0): ");
    sal_print(&nombres);

    sal_free(&nombres);
    return 0;
}
