/**
 * Recorridos iterativos de un arbol binario usando estructuras explicitas:
 * preorder/inorder/postorder (2 stacks) y level-order (queue).
 * Usa el arbol de ejemplo del apunte (raiz=8).
 * @author AxxturelHyphen
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

static TreeNode *new_node(int v) {
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    if (!n) {
        fprintf(stderr, "Sin memoria para nodo\n");
        exit(EXIT_FAILURE);
    }
    n->value = v;
    n->left = n->right = NULL;
    return n;
}

// preorder iterativo: stack (LIFO)
static void preorder(TreeNode *root) {
    if (!root) return;
    TreeNode *stack[64];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        TreeNode *node = stack[top--];
        printf("%d ", node->value);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

// inorder iterativo: bajar a la izquierda, procesar, ir derecha
static void inorder(TreeNode *root) {
    TreeNode *stack[64];
    int top = -1;
    TreeNode *cur = root;
    while (cur || top >= 0) {
        while (cur) {
            stack[++top] = cur;
            cur = cur->left;
        }
        TreeNode *node = stack[top--];
        printf("%d ", node->value);
        cur = node->right;
    }
}

// postorder con 2 stacks
static void postorder(TreeNode *root) {
    if (!root) return;
    TreeNode *s1[64];
    TreeNode *s2[64];
    int t1 = -1, t2 = -1;
    s1[++t1] = root;
    while (t1 >= 0) {
        TreeNode *node = s1[t1--];
        s2[++t2] = node;
        if (node->left) s1[++t1] = node->left;
        if (node->right) s1[++t1] = node->right;
    }
    while (t2 >= 0) {
        printf("%d ", s2[t2--]->value);
    }
}

// level-order BFS con queue circular simple
static void level_order(TreeNode *root) {
    if (!root) return;
    TreeNode *queue[64];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        TreeNode *node = queue[head++];
        printf("%d ", node->value);
        if (node->left) queue[tail++] = node->left;
        if (node->right) queue[tail++] = node->right;
    }
}

// arbol de ejemplo (raiz 8)
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

static void free_tree(TreeNode *node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main(void) {
    TreeNode *root = build_sample();

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    printf("level-order: ");
    level_order(root);
    printf("\n");

    free_tree(root);
    return 0;
}
