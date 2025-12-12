/**
 * Binary Search Tree (BST) con search/insert/delete.
 * Invariante: left subtree < key < right subtree (sin duplicados).
 * inorder devuelve las claves en sorted order (asc).
 * @author AxxturelHyphen
 */

import java.util.NoSuchElementException;

public class BSTree {
    static class Node {
        int key;
        Node left;
        Node right;

        Node(int key) {
            this.key = key;
        }
    }

    private Node root;

    // Search iterativo: O(h)
    public boolean contains(int key) {
        Node cur = root;
        while (cur != null) {
            if (key == cur.key) return true;
            cur = (key < cur.key) ? cur.left : cur.right;
        }
        return false;
    }

    // Insert sin duplicados: O(h)
    public void insert(int key) {
        root = insertRec(root, key);
    }

    private Node insertRec(Node node, int key) {
        if (node == null) return new Node(key);
        if (key < node.key) node.left = insertRec(node.left, key);
        else if (key > node.key) node.right = insertRec(node.right, key);
        // if equal -> skip (no duplicates)
        return node;
    }

    // Delete: maneja casos 0,1,2 hijos
    public void delete(int key) {
        root = deleteRec(root, key);
    }

    private Node deleteRec(Node node, int key) {
        if (node == null) return null;
        if (key < node.key) {
            node.left = deleteRec(node.left, key);
        } else if (key > node.key) {
            node.right = deleteRec(node.right, key);
        } else {
            // caso 0 hijos
            if (node.left == null && node.right == null) {
                return null;
            }
            // caso 1 hijo
            if (node.left == null) return node.right;
            if (node.right == null) return node.left;
            // caso 2 hijos: usar sucesor (min en right subtree)
            Node succ = minNode(node.right);
            node.key = succ.key;
            node.right = deleteRec(node.right, succ.key);
        }
        return node;
    }

    private Node minNode(Node node) {
        Node cur = node;
        while (cur.left != null) cur = cur.left;
        return cur;
    }

    // inorder traversal para ver orden ascendente
    public void printInOrder() {
        printInOrder(root);
        System.out.println();
    }

    private void printInOrder(Node node) {
        if (node == null) return;
        printInOrder(node.left);
        System.out.print(node.key + " ");
        printInOrder(node.right);
    }

    public int peekMin() {
        if (root == null) throw new NoSuchElementException("Empty tree");
        return minNode(root).key;
    }

    public static void main(String[] args) {
        BSTree bst = new BSTree();
        int[] vals = {8, 3, 10, 1, 6, 14, 4, 7, 13};
        for (int v : vals) bst.insert(v);

        System.out.print("Inorder sorted: ");
        bst.printInOrder(); // 1 3 4 6 7 8 10 13 14

        System.out.println("Contains 7? " + bst.contains(7));
        System.out.println("Contains 2? " + bst.contains(2));

        bst.delete(3);
        System.out.print("After delete 3 (inorder): ");
        bst.printInOrder();
    }
}
