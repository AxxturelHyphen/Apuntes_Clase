/**
 * Binary Search Tree (BST) con search/insert/delete.
 * Regla: left < key < right (sin duplicados). Inorder produce sorted order.
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
} BSTree;

static Node *new_node(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Sin memoria para nodo\n");
        exit(EXIT_FAILURE);
    }
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

static void bst_init(BSTree *t) {
    t->root = NULL;
}

// search iterativo O(h)
static bool bst_contains(const BSTree *t, int key) {
    Node *cur = t->root;
    while (cur) {
        if (key == cur->key) return true;
        cur = (key < cur->key) ? cur->left : cur->right;
    }
    return false;
}

// insert sin duplicados O(h)
static Node *insert_rec(Node *node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key) node->left = insert_rec(node->left, key);
    else if (key > node->key) node->right = insert_rec(node->right, key);
    return node;
}

static void bst_insert(BSTree *t, int key) {
    t->root = insert_rec(t->root, key);
}

// minimo (para sucesor)
static Node *min_node(Node *node) {
    Node *cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

// delete O(h): maneja 0,1,2 hijos
static Node *delete_rec(Node *node, int key) {
    if (node == NULL) return NULL;
    if (key < node->key) {
        node->left = delete_rec(node->left, key);
    } else if (key > node->key) {
        node->right = delete_rec(node->right, key);
    } else {
        // caso 0 hijos
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // caso 1 hijo
        if (node->left == NULL) {
            Node *tmp = node->right;
            free(node);
            return tmp;
        }
        if (node->right == NULL) {
            Node *tmp = node->left;
            free(node);
            return tmp;
        }
        // caso 2 hijos: usar sucesor
        Node *succ = min_node(node->right);
        node->key = succ->key;
        node->right = delete_rec(node->right, succ->key);
    }
    return node;
}

static void bst_delete(BSTree *t, int key) {
    t->root = delete_rec(t->root, key);
}

// inorder print para ver sorted order
static void inorder_print(Node *node) {
    if (!node) return;
    inorder_print(node->left);
    printf("%d ", node->key);
    inorder_print(node->right);
}

static void bst_print_inorder(const BSTree *t) {
    inorder_print(t->root);
    printf("\n");
}

static void bst_free_nodes(Node *node) {
    if (!node) return;
    bst_free_nodes(node->left);
    bst_free_nodes(node->right);
    free(node);
}

static void bst_clear(BSTree *t) {
    bst_free_nodes(t->root);
    t->root = NULL;
}

int main(void) {
    BSTree bst;
    bst_init(&bst);
    int vals[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    for (int i = 0; i < n; ++i) bst_insert(&bst, vals[i]);

    printf("Inorder sorted: ");
    bst_print_inorder(&bst);

    printf("Contains 7? %s\n", bst_contains(&bst, 7) ? "true" : "false");
    printf("Contains 2? %s\n", bst_contains(&bst, 2) ? "true" : "false");

    bst_delete(&bst, 3);
    printf("After delete 3 (inorder): ");
    bst_print_inorder(&bst);

    bst_clear(&bst);
    return 0;
}
