/**
 * Arbol binario y recorridos DFS (pre/in/post) + BFS (level-order).
 * Usa el arbol de ejemplo del apunte para mostrar los ordenes.
 * @author AxxturelHyphen
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helpers de creacion
static TreeNode *new_node(int value) {
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    if (!n) {
        fprintf(stderr, "Sin memoria para nodo\n");
        exit(EXIT_FAILURE);
    }
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

// DFS recursive traversals
static void preorder(TreeNode *node) {
    if (!node) return;
    printf("%d ", node->value);
    preorder(node->left);
    preorder(node->right);
}

static void inorder(TreeNode *node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

static void postorder(TreeNode *node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->value);
}

// BFS level-order usando cola simple (array de punteros)
static void level_order(TreeNode *root) {
    if (!root) return;
    TreeNode *queue[64]; // suficiente para el ejemplo (complete binary small)
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        TreeNode *node = queue[head++];
        printf("%d ", node->value);
        if (node->left) queue[tail++] = node->left;
        if (node->right) queue[tail++] = node->right;
    }
}

// Construye el arbol de la seccion 4.3.1
static TreeNode *build_sample(void) {
    TreeNode *n8 = new_node(8);
    TreeNode *n3 = new_node(3);
    TreeNode *n10 = new_node(10);
    TreeNode *n1 = new_node(1);
    TreeNode *n6 = new_node(6);
    TreeNode *n14 = new_node(14);
    TreeNode *n4 = new_node(4);
    TreeNode *n7 = new_node(7);
    TreeNode *n13 = new_node(13);

    n8->left = n3;
    n8->right = n10;
    n3->left = n1;
    n3->right = n6;
    n10->right = n14;
    n6->left = n4;
    n6->right = n7;
    n14->left = n13;

    return n8;
}

// libera nodos (postorder free)
static void free_tree(TreeNode *node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main(void) {
    TreeNode *root = build_sample();

    printf("preorder (NLR): ");
    preorder(root);
    printf("\n");

    printf("inorder (LNR): ");
    inorder(root);
    printf("\n");

    printf("postorder (LRN): ");
    postorder(root);
    printf("\n");

    printf("level-order (BFS): ");
    level_order(root);
    printf("\n");

    free_tree(root);
    return 0;
}
