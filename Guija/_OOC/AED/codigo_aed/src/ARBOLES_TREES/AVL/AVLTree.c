/**
 * AVL Tree en C: BST balanceado con BF en {-1,0,1}.
 * insert rebalancea con rotaciones LL/RR/LR/RL para mantener altura O(log n).
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
} AVLTree;

static int height(Node *n) {
    return n ? n->height : 0;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static Node *new_node(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Sin memoria para nodo\n");
        exit(EXIT_FAILURE);
    }
    n->key = key;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

// Rotacion derecha (LL)
static Node *rotate_right(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Rotacion izquierda (RR)
static Node *rotate_left(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

static int balance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Insercion con rebalance; sin duplicados
static Node *insert_rec(Node *node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key) node->left = insert_rec(node->left, key);
    else if (key > node->key) node->right = insert_rec(node->right, key);
    else return node; // duplicado

    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = balance(node);

    // LL
    if (bf > 1 && key < node->left->key) return rotate_right(node);
    // RR
    if (bf < -1 && key > node->right->key) return rotate_left(node);
    // LR
    if (bf > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    // RL
    if (bf < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

static void avl_init(AVLTree *t) {
    t->root = NULL;
}

static void avl_insert(AVLTree *t, int key) {
    t->root = insert_rec(t->root, key);
}

static bool avl_contains(const AVLTree *t, int key) {
    Node *cur = t->root;
    while (cur) {
        if (key == cur->key) return true;
        cur = (key < cur->key) ? cur->left : cur->right;
    }
    return false;
}

static void inorder_print(Node *node) {
    if (!node) return;
    inorder_print(node->left);
    printf("%d ", node->key);
    inorder_print(node->right);
}

static int avl_height(const AVLTree *t) {
    return height(t->root);
}

static void free_nodes(Node *node) {
    if (!node) return;
    free_nodes(node->left);
    free_nodes(node->right);
    free(node);
}

static void avl_clear(AVLTree *t) {
    free_nodes(t->root);
    t->root = NULL;
}

int main(void) {
    AVLTree avl;
    avl_init(&avl);
    int vals[] = {30, 10, 20, 40, 50};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    for (int i = 0; i < n; ++i) {
        avl_insert(&avl, vals[i]);
    }

    printf("Inorder (sorted): ");
    inorder_print(avl.root);
    printf("\n");
    printf("Height: %d\n", avl_height(&avl));
    printf("Contains 40? %s\n", avl_contains(&avl, 40) ? "true" : "false");

    avl_clear(&avl);
    return 0;
}
