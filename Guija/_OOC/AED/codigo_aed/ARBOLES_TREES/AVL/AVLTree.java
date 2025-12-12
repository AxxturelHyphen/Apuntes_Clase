/**
 * AVL Tree: BST balanceado con factor de balance en {-1,0,1}.
 * insert rebalancea con rotaciones LL, RR, LR, RL para mantener altura O(log n).
 * @author AxxturelHyphen
 */

public class AVLTree {
    static class Node {
        int key;
        int height; // height of subtree rooted here
        Node left;
        Node right;

        Node(int key) {
            this.key = key;
            this.height = 1; // hoja height = 1
        }
    }

    private Node root;

    // height helper
    private int h(Node n) {
        return n == null ? 0 : n.height;
    }

    // balance factor = h(left) - h(right)
    private int balance(Node n) {
        return (n == null) ? 0 : h(n.left) - h(n.right);
    }

    // right rotation (para casos LL)
    private Node rotateRight(Node y) {
        Node x = y.left;
        Node t2 = x.right;

        x.right = y;
        y.left = t2;

        y.height = Math.max(h(y.left), h(y.right)) + 1;
        x.height = Math.max(h(x.left), h(x.right)) + 1;
        return x;
    }

    // left rotation (para casos RR)
    private Node rotateLeft(Node x) {
        Node y = x.right;
        Node t2 = y.left;

        y.left = x;
        x.right = t2;

        x.height = Math.max(h(x.left), h(x.right)) + 1;
        y.height = Math.max(h(y.left), h(y.right)) + 1;
        return y;
    }

    // insercion con rebalance; sin duplicados
    public void insert(int key) {
        root = insertRec(root, key);
    }

    private Node insertRec(Node node, int key) {
        if (node == null) return new Node(key);
        if (key < node.key) node.left = insertRec(node.left, key);
        else if (key > node.key) node.right = insertRec(node.right, key);
        else return node; // duplicado: ignorar

        node.height = Math.max(h(node.left), h(node.right)) + 1;
        int bf = balance(node);

        // 4 casos clasicos
        // LL
        if (bf > 1 && key < node.left.key) return rotateRight(node);
        // RR
        if (bf < -1 && key > node.right.key) return rotateLeft(node);
        // LR
        if (bf > 1 && key > node.left.key) {
            node.left = rotateLeft(node.left);
            return rotateRight(node);
        }
        // RL
        if (bf < -1 && key < node.right.key) {
            node.right = rotateRight(node.right);
            return rotateLeft(node);
        }
        return node;
    }

    public boolean contains(int key) {
        Node cur = root;
        while (cur != null) {
            if (key == cur.key) return true;
            cur = (key < cur.key) ? cur.left : cur.right;
        }
        return false;
    }

    // inorder imprime sorted order
    public void printInOrder() {
        printInOrder(root);
        System.out.println();
    }

    private void printInOrder(Node n) {
        if (n == null) return;
        printInOrder(n.left);
        System.out.print(n.key + " ");
        printInOrder(n.right);
    }

    public int height() {
        return h(root);
    }

    public static void main(String[] args) {
        AVLTree avl = new AVLTree();
        int[] vals = {30, 10, 20, 40, 50}; // provoca caso LR en 30
        for (int v : vals) avl.insert(v);

        System.out.print("Inorder (sorted): ");
        avl.printInOrder(); // 10 20 30 40 50
        System.out.println("Height: " + avl.height());
        System.out.println("Contains 40? " + avl.contains(40));
    }
}
