/**
 * Arbol binario basico para recorridos DFS/BFS.
 * Node->left->right con ejemplo fijo para practicar los ordenes.
 * @author AxxturelHyphen
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class TreeTraversals {
    static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        TreeNode(int value) {
            this.value = value;
        }
    }

    // preorder: Node -> Left -> Right
    static void preorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        out.add(node.value);
        preorder(node.left, out);
        preorder(node.right, out);
    }

    // inorder: Left -> Node -> Right
    static void inorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        inorder(node.left, out);
        out.add(node.value);
        inorder(node.right, out);
    }

    // postorder: Left -> Right -> Node
    static void postorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        postorder(node.left, out);
        postorder(node.right, out);
        out.add(node.value);
    }

    // level-order (BFS) usando queue
    static List<Integer> levelOrder(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        if (root == null) return out;
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();
            out.add(node.value);
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return out;
    }

    // Construye el arbol de ejemplo del apunte
    static TreeNode buildSample() {
        TreeNode n8 = new TreeNode(8);
        TreeNode n3 = new TreeNode(3);
        TreeNode n10 = new TreeNode(10);
        TreeNode n1 = new TreeNode(1);
        TreeNode n6 = new TreeNode(6);
        TreeNode n14 = new TreeNode(14);
        TreeNode n4 = new TreeNode(4);
        TreeNode n7 = new TreeNode(7);
        TreeNode n13 = new TreeNode(13);

        n8.left = n3;
        n8.right = n10;
        n3.left = n1;
        n3.right = n6;
        n10.right = n14;
        n6.left = n4;
        n6.right = n7;
        n14.left = n13;
        return n8;
    }

    public static void main(String[] args) {
        TreeNode root = buildSample();

        List<Integer> pre = new ArrayList<>();
        preorder(root, pre);
        System.out.println("preorder (NLR): " + pre);

        List<Integer> in = new ArrayList<>();
        inorder(root, in);
        System.out.println("inorder (LNR): " + in);

        List<Integer> post = new ArrayList<>();
        postorder(root, post);
        System.out.println("postorder (LRN): " + post);

        System.out.println("level-order (BFS): " + levelOrder(root));
    }
}
